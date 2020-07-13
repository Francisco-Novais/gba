#include <string.h>
#include "toolbox.h"
#include "happySquare.h"
#include "mapp.h"

#define MAP_WIDTH 32*16

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer = (OBJ_AFFINE *) obj_buffer;

int const firstHorizontalOffset = 192;
int const firstVerticalOffset = 64;
int currentHorizontalOffset = firstHorizontalOffset;
int currentVerticalOffset = firstVerticalOffset;
int newMap[16][32];

s32 playerLocation[2];
s32 isJumping = 0;
s32 gravity = 1;
s32 verticalSpeed = 6;
s32 horizontalSpeed = 1;
s32 firstVerticalSpeed = 6;
s32 firstHorizontalSpeed = 1;
s32 collisionX = 0;
s32 collisionY = 0;
int x = 0;
int timer = 0;

void jump() {
    if (!isJumping) {
        isJumping = 1;
        verticalSpeed = firstVerticalSpeed;
    }

    timer++;
    if (verticalSpeed > 0) {
        if (timer % 3 == 0) {
            verticalSpeed -= gravity;
        }
    } else {
        if (timer % 2 == 0) {
            verticalSpeed -= gravity;
        }
    }

    if (isJumping && collisionX) { //there is collisionX on the bottom part of the player
        isJumping = 0; //stops jumping
    } else {
        playerLocation[1] -= verticalSpeed;
    }
}

void run() {
    if (horizontalSpeed == 1) {
        horizontalSpeed <<= 1;
    }
}

// testing a few sprite things
// D-pad: move and horizontal flip
// UP: JUMP
_Noreturn void obj_test() {
    int isTurnedLeft = 0;
    playerLocation[0] = 10; //x = 10
    playerLocation[1] = 100; // y = 127

    u32 tid = 0, pb = 0;        // tile id, pal-bank

    OBJ_ATTR *happy = &obj_buffer[0];
    obj_set_attr(happy,
                 ATTR0_SQUARE,                    // Square, regular sprite
                 ATTR1_SIZE_16x16,                    // 16x16p,
                 ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    //obj_set_pos(happy, playerLocation[0], playerLocation[1]);

    //scroll around some
    REG_BG0HOFS = firstHorizontalOffset;
    REG_BG0VOFS = firstVerticalOffset;

    while (1) {
        vid_vsync();
        key_poll();

        // move left
        // flip horizontally if looking to the right
        if ((key_held(KEY_LEFT) || key_hit(KEY_LEFT)) && !collisionY) {
            playerLocation[0] -= horizontalSpeed;
            if (!isTurnedLeft) {
                happy->attr1 ^= ATTR1_HFLIP;
                isTurnedLeft = 1;
            }
        }

        // move right
        // flip horizontally if looking to the left
        if ((key_held(KEY_RIGHT) || key_hit(KEY_RIGHT)) && !collisionY) {
            playerLocation[0] += horizontalSpeed;
            if (isTurnedLeft) {
                happy->attr1 ^= ATTR1_HFLIP;
                isTurnedLeft = 0;
            }
        }

       /* if (collisionX) {
            happy->attr1 ^= ATTR1_VFLIP;
            playerLocation[1] -= 1;
            // make it glow (via palette swapping)
        }

        if (collisionY) {
            pb = 1;
        } else {
            pb = 0;
        }
*/
        if (!collisionX && !isJumping) {
            playerLocation[1] += 1;
        }

        //simple jump with gravity (no collisionX)
        if (key_hit(KEY_UP) || key_held(KEY_UP) || isJumping) {
            jump();
        }

        if (key_hit(KEY_A)) {
            playerLocation[1] = 110;
        }

        if (key_held(KEY_B)) {
            run();
        }

        if (!key_held(KEY_B)) {
            horizontalSpeed = firstHorizontalSpeed;
        }

        //background right scroller
        if (playerLocation[0] >= 110) {
            x += horizontalSpeed;
            REG_BG0HOFS = x + firstHorizontalOffset; // dx is the offset
            currentHorizontalOffset = x + firstHorizontalOffset; // saves the value of the ofset
            if (horizontalSpeed == 2) {
                playerLocation[0] = 110 - horizontalSpeed + 1; // inbetween frame
            } else {
                playerLocation[0] = 110 - horizontalSpeed;
            }
        }

        //background left scroller
        if (playerLocation[0] <= 40) {
            x -= horizontalSpeed;
            REG_BG0HOFS = x + firstHorizontalOffset;
            currentHorizontalOffset = x + firstHorizontalOffset;
            if (horizontalSpeed == 2) {
                playerLocation[0] = 40 + horizontalSpeed - 1; // inbetween frame
            } else {
                playerLocation[0] = 40 + horizontalSpeed;
            }
        }

        //collisionX = collisionX_test(playerLocation[0], playerLocation[1], playerLocation[0]+31, playerLocation[1]+63, horizontalSpeed, verticalSpeed);

        int coordX = (currentHorizontalOffset + playerLocation[0]) / 16;
        int coordY = (currentVerticalOffset + playerLocation[1]) / 16;

        if ((newMap[coordY][coordX + 1] != 0x00000000)) {
            collisionY = 1;
            playerLocation[0] -= 2;
        } else {
            collisionY = 0;
        }
        if (newMap[coordY][coordX - 1] != 0x00000000) {
            collisionY = 1;
            playerLocation[0] += 2;
        } else {
            collisionY = 0;
        }

        if (newMap[coordY + 1][coordX] != 0x00000000) {
            collisionX = 1;
            playerLocation[1] -= 2;
        } else {
            collisionX = 0;
        }

        if (newMap[coordY - 1][coordX] != 0x00000000) {
            playerLocation[1] += 2;
        }

        // Hey look, it's one of them build macros!
        // happy->attr2= ATTR2_BUILD(tid, pb, 0);
        happy->attr2 = ATTR2_BUILD(tid, pb, 0);
        obj_set_pos(happy, playerLocation[0], playerLocation[1]);

        oam_copy(oam_mem, obj_buffer, 1);    // only need to update one
    }
}

void loadBackGround() {
    // Load palette
    memcpy(pal_bg_mem, mappPal, mappPalLen);
    // Load tiles into CBB 0
    memcpy(&tile_mem[0][0], mappTiles, mappTilesLen);
    // Load map into SBB 30
    memcpy(&se_mem[30][0], mappMap, mappMapLen);

    // set up BG0 for a 4bpp 64x32t map, using
    //   using charblock 0 and screenblock 31
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_4BPP | BG_REG_64x32;
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;

}

void loadSprite() {
    // Places the glyphs of a 4bpp boxed happy sprite
    //   into LOW obj memory (cbb == 4)
    memcpy(&tile_mem[4][0], happySquareTiles, happySquareTilesLen);
    memcpy(pal_obj_mem, happySquarePal, happySquarePalLen);

    oam_init(obj_buffer, 128);
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0;
}

static void accessMap() {
    int i, j, constant, counter = 0;

    while (counter < 512) {
        for (i = 0; i < 16; i++) {
            constant = i * 32;
            int flag = 1;
            for (j = 0; j < 32; ++j) {

                if (j >= 16 && flag) {
                    constant += 496;
                    flag = 0;
                }

                if (mappMap[constant] == 0) {
                    newMap[i][j] = 0;
                } else {
                    newMap[i][j] = 1;
                }
                counter++;
                constant++;
            }
        }
    }
}

int main() {

    loadBackGround();
    loadSprite();
    accessMap();
    obj_test();
    while (1);

    return 0;
}
