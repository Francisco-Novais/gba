#include <string.h>
#include "toolbox.h"
#include "happySquare.h"
#include "happy.h"
#include "mapp.h"

#define MAP_WIDTH 32*16

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer = (OBJ_AFFINE *) obj_buffer;

int const firstHorizontalOffset = 10;
int const firstVerticalOffset = 64;
int currentHorizontalOffset = firstHorizontalOffset;
int currentVerticalOffset = firstVerticalOffset;

s32 playerLocationX;
s32 playerLocationY;
s32 isJumping = 0;
s32 gravity = 1;
s32 verticalSpeed = 6;
s32 horizontalSpeed = 1;
const s32 firstVerticalSpeed = 6;
const s32 firstHorizontalSpeed = 1;
s32 collisionGround = 0; //ground
s32 collisionRoof = 0; // roof
s32 collisionRight = 0;
s32 collisionLeft = 0;
int x = 0;
int timer = 0;

//doesn't work
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

    if (!collisionGround && verticalSpeed != firstVerticalSpeed) { // hits the ground
        isJumping = 0; //stops jumping
    } else {
        playerLocationY -= verticalSpeed;
    }
}

void run() {
    if (horizontalSpeed == 1) {
        horizontalSpeed <<= 1;
    }
}

//only works for the first half of the map due to the array mappMap[] being organized in a special way
s32 checkCollision(s32 coordX, s32 coordY, s32 spriteOffsetX, s32 spriteOffSetY) {

    return (mappMap[32 * (coordY + spriteOffSetY) + (coordX + spriteOffsetX)] != 0x00000000);

}

/* testing a few sprite things
 D-pad: move and horizontal flip
 UP: JUMP
 B: RUN
*/
_Noreturn void obj_test() {
    int isTurnedLeft = 0;
    playerLocationX = 10; //x = 10
    playerLocationY = 100; // y = 127

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
        if ((key_held(KEY_LEFT) || key_hit(KEY_LEFT)) && !collisionLeft) {
            playerLocationX -= horizontalSpeed;
            if (!isTurnedLeft) {
                happy->attr1 ^= ATTR1_HFLIP;
                isTurnedLeft = 1;
            }
        }

        // move right
        // flip horizontally if looking to the left
        if ((key_held(KEY_RIGHT) || key_hit(KEY_RIGHT)) && !collisionRight) {
            playerLocationX += horizontalSpeed;
            if (isTurnedLeft) {
                happy->attr1 ^= ATTR1_HFLIP;
                isTurnedLeft = 0;
            }
        }

        //has a roof
        if (collisionRoof) {
            happy->attr1 ^= ATTR1_VFLIP;
        }

        //has a wall on the way
        if (collisionGround) {
            pb = 1;
        } else {
            pb = 0;
        }

        //simple jump with gravity (no collisionGround)
        if ((key_hit(KEY_UP) || isJumping) && !collisionRoof) {
            jump();
        }

        //running
        if (key_held(KEY_B)) {
            run();
        } else {
            horizontalSpeed = firstHorizontalSpeed;
        }

        //background right scroller
        if (playerLocationX >= 110 && !collisionRight) {
            x += horizontalSpeed;
            REG_BG0HOFS = x + firstHorizontalOffset; // dx is the offset
            currentHorizontalOffset = x + firstHorizontalOffset; // saves the value of the ofset
            if (horizontalSpeed == 2) {
                playerLocationX = 110 - horizontalSpeed + 1; // inbetween frame
            } else {
                playerLocationX = 110 - horizontalSpeed;
            }
        }

        //background left scroller
        if (playerLocationX <= 40 && !collisionLeft) {
            x -= horizontalSpeed;
            REG_BG0HOFS = x + firstHorizontalOffset;
            currentHorizontalOffset = x + firstHorizontalOffset;
            if (horizontalSpeed == 2) {
                playerLocationX = 40 + horizontalSpeed - 1; // inbetween frame
            } else {
                playerLocationX = 40 + horizontalSpeed;
            }
        }

        // get the map coords
        int coordX = (currentHorizontalOffset + playerLocationX) / 16;
        int coordY = (currentVerticalOffset + playerLocationY) / 16;

        //x+1 (right wall)
        if (checkCollision(coordX, coordY, 1, 0) || checkCollision(coordX, coordY, 1, 1)) {
            collisionRight = 1;
            if (!collisionRoof) {
                playerLocationX--;
            }
        } else {
            collisionRight = 0;
        }

        //x-1 (left wall)
        if (checkCollision(coordX, coordY, 0, 0) || checkCollision(coordX, coordY, 0, 1)) {
            collisionLeft = 1;
            if (!collisionRoof) {
                playerLocationX++;;
            }

        } else {
            collisionLeft = 0;
        }

        //y-1 (roof)
        if (checkCollision(coordX, coordY, 0, 0) || checkCollision(coordX, coordY, 1, 0)) {
            collisionRoof = 1;
            if (!collisionLeft && !collisionRight) {
                playerLocationY++;
            }
        } else {
            collisionRoof = 0;
        }

        //y+1 (ground)
        if (checkCollision(coordX, coordY, 0, 1) || checkCollision(coordX, coordY, 1, 1)) {
            collisionGround = 1;
            if (!collisionLeft && !collisionRight) {
                playerLocationY--;
            }
        } else {
            collisionGround = 0;
        }

        //default gravity
        if (!collisionGround && !isJumping) {
            playerLocationY += gravity;
        }

        // Hey look, it's one of them build macros!

        happy->attr2 = ATTR2_BUILD(tid, pb, 0);
        obj_set_pos(happy, playerLocationX, playerLocationY);

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

/*
void fillSquare(int i, int j, int value) {
        int k, l;
        for (k = 0; k < 16; ++k) {
            for (l = 0; l < 16; ++l) {
                newMap[i+k][j+l] = value;
            }
        }

}*/
/*
void accessMap() {
        int i, j, constant, counter = 0;

        while (counter < 512) {
            for (i = 0; i < 16; i++) {
                constant = i;// * 32;
                int flag = 1;
                for (j = 0; j < 32; ++j) {
                    if (j >= 16 && flag) {
                        constant += 496;
                        flag = 0;
                    }

                    if (mappMap[constant] == 0) {
                        newMap[i][j] = 0; // fillSquare(i*16,j*16,0);
                    } else {
                        newMap[i][j] = 1; // fillSquare(i*16,j*16,1);
                    }
                    counter++;
                    constant++;
                }
            }
        }
}*/

int main() {

    loadBackGround();
    loadSprite();
    //  accessMap();
    obj_test();
}
