#include <string.h>
#include "toolbox.h"
#include "happy.h"
#include "mapp.h"

#define COLLISION_X 1
#define COLLISION_Y 2
#define MAP_WIDTH 32*8

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer = (OBJ_AFFINE *) obj_buffer;

s32 playerLocation[2];
s32 isJumping = 0;
s32 gravity = 1;
s32 verticalSpeed = 6;
s32 horizontalSpeed = 1;
s32 firstVerticalSpeed = 6;
s32 firstHorizontalSpeed = 1;
s32 collision = 0;
int x = 0;
int timer = 0;

// Converts x and y into the appropriate screen entry
int se_index(int x, int y) {
    int base = 0;

    if (x >= MAP_WIDTH/2) {
        x -= MAP_WIDTH/2;
        base = 32*32;
    }

    return base + (y>>3<<5) + (x>>3);
}

// Returns true if we have a collision tile at x,y
int point_collision(int x, int y) {
    int i = se_index(x,y);
    int tid = se_mem[30][i];
    tid = tid & 0xFF; // Chop off the lower bits

    return (
            tid == 64 ||
            tid == 65 ||
            tid == 66 ||
            tid == 96 ||
            tid == 97 ||
            tid == 98 ||
            tid == 99 ||
            tid == 128 ||
            tid == 129 ||
            tid == 130 ||
            tid == 131 ||
            tid == 161 ||
            tid == 162 ||
            tid == 163
    );
}

// Test if there would be a collision given the bounding box and the proposed
// x and y offsets
int collision_test(int x1, int y1, int x2, int y2, int xofs, int yofs) {
    int result = 0;

    if (xofs > 0) {
        if (point_collision(x2+xofs,y1) || point_collision(x2+xofs,y2))
            result = COLLISION_X;
    }
    else if (xofs < 0) {
        if (point_collision(x1+xofs,y1) || point_collision(x1+xofs,y2))
            result = COLLISION_X;
    }

    if (yofs > 0) {
        if (point_collision(x1,y2+yofs) || point_collision(x2,y2+yofs))
            result = result | COLLISION_Y;
    }
    else if (yofs < 0) {
        if (point_collision(x1,y1+yofs) || point_collision(x2,y1+yofs))
            result = result | COLLISION_Y;
    }

    return result;
}

void jump() {
    if (!isJumping) {
        isJumping = 1;
        verticalSpeed = firstVerticalSpeed;
    }

    timer++;
    if(verticalSpeed > 0){
        if (timer % 3 == 0){
            verticalSpeed -= gravity;
        }
    }else{
        if (timer % 2 == 0){
            verticalSpeed -= gravity;
        }
    }

    if(timer % 34 == 0){
        collision = 1;
    }else{
        collision = 0;
    }

    if (collision == 1) { //there is collision on the bottom part of the player
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
    playerLocation[1] = 127; // y = 127

    u32 tid = 0, pb = 0;        // tile id, pal-bank

    OBJ_ATTR *happy = &obj_buffer[0];
    obj_set_attr(happy,
                 ATTR0_SQUARE,                    // Square, regular sprite
                 ATTR1_SIZE_16x16,                    // 16x16p,
                 ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    obj_set_pos(happy, playerLocation[0], playerLocation[1]);
    int dx = 192, dy = 64;
    //scroll around some
    REG_BG0HOFS = dx;
    REG_BG0VOFS = dy;

    while (1) {
        vid_vsync();
        key_poll();



        // move left
        // flip horizontally if looking to the right
        if (key_held(KEY_LEFT) || key_hit(KEY_LEFT)) {
            playerLocation[0] -= horizontalSpeed;
            if (!isTurnedLeft) {
                happy->attr1 ^= ATTR1_HFLIP;
                isTurnedLeft = 1;
            }
        }

        // move right
        // flip horizontally if looking to the left
        if (key_held(KEY_RIGHT) || key_hit(KEY_RIGHT)) {
            playerLocation[0] += horizontalSpeed;
            if (isTurnedLeft) {
                happy->attr1 ^= ATTR1_HFLIP;
                isTurnedLeft = 0;
            }
        }

        //simple jump with gravity (no collision)
        if (key_hit(KEY_UP) || isJumping) {
            jump();
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
            REG_BG0HOFS = x + dx; // dx is the offset
            if (horizontalSpeed == 2) {
                playerLocation[0] = 110 - horizontalSpeed + 1; // inbetween frame
            } else {
                playerLocation[0] = 110 - horizontalSpeed;
            }
        }

        //background left scroller
        if (playerLocation[0] <= 40) {
            x -= horizontalSpeed;
            REG_BG0HOFS = x + dx;
            if (horizontalSpeed == 2) {
                playerLocation[0] = 40 + horizontalSpeed - 1; // inbetween frame
            } else {
                playerLocation[0] = 40 + horizontalSpeed;
            }
        }
        int coord = (playerLocation[1]/8);
        coord += 1;
        coord *= MAP_WIDTH/8;
        coord += playerLocation[0]/8;

       //collision = collision_test(playerLocation[0], playerLocation[1], playerLocation[0]+31, playerLocation[1]+63, horizontalSpeed, verticalSpeed);
       /*if(mappMap[coord] != 0x00000000){
           collision = 1;
           if (key_held(KEY_A)) {
               playerLocation[1] = 110;
           }
       }else{
           collision = 0;
       }*/


        // Hey look, it's one of them build macros!
        // happy->attr2= ATTR2_BUILD(tid, pb, 0);
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
    memcpy(&tile_mem[4][0], happyTiles, happyTilesLen);
    memcpy(pal_obj_mem, happyPal, happyPalLen);

    oam_init(obj_buffer, 128);
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0;
}



int main() {

    loadBackGround();
    loadSprite();
    obj_test();
    while (1);

    return 0;
}
