#include <string.h>
#include "toolbox.h"
#include "happy.h"

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer = (OBJ_AFFINE *) obj_buffer;

s32 playerLocation[2];
s32 isJumping = 0;
s32 gravity = 1;
s32 currentSpeed = 8;
s32 firstSpeed = 8;

void jump() {
    if (!isJumping) {
        isJumping = 1;
        currentSpeed = firstSpeed;
    }

    currentSpeed -= gravity;

    if (currentSpeed <= -firstSpeed) { //the jump has ended and the player is on the ground
        isJumping = 0;
    }else{
        playerLocation[1] -= currentSpeed;
    }
}


// testing a few sprite things
// D-pad: move and horizontal flip
// UP: JUMP
_Noreturn void obj_test() {
    int isTurnedLeft = 0;
    playerLocation[0] = 10; //x = 10
    playerLocation[1] = 100; // y = 32

    u32 tid = 0, pb = 0;        // tile id, pal-bank

    OBJ_ATTR *happy = &obj_buffer[0];
    obj_set_attr(happy,
                 ATTR0_SQUARE,                    // Square, regular sprite
                 ATTR1_SIZE_16x16,                    // 16x16p,
                 ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    obj_set_pos(happy, playerLocation[0], playerLocation[1]);

    while (1) {
        vid_vsync();
        key_poll();

        // move left
        // flip horizontally if looking to the right
        if (key_held(KEY_LEFT)|| key_hit(KEY_LEFT) ) {
            playerLocation[0] += key_tri_horz();
            if (!isTurnedLeft) {
                happy->attr1 ^= ATTR1_HFLIP;
                isTurnedLeft = 1;
            }
        }

        // move right
        // flip horizontally if looking to the left
        if (key_held(KEY_RIGHT) || key_hit(KEY_RIGHT) ) {
            playerLocation[0] += key_tri_horz();
            if (isTurnedLeft) {
                happy->attr1 ^= ATTR1_HFLIP;
                isTurnedLeft = 0;
            }
        }

        //simple jump with gravity (no collision)
        if (key_hit(KEY_UP) || isJumping == 1) {
            jump();
        }

        // Hey look, it's one of them build macros!
        // happy->attr2= ATTR2_BUILD(tid, pb, 0);
        obj_set_pos(happy, playerLocation[0], playerLocation[1]);

        oam_copy(oam_mem, obj_buffer, 1);    // only need to update one
    }
}

int main() {

    // Places the glyphs of a 4bpp boxed happy sprite
    //   into LOW obj memory (cbb == 4)
    memcpy(&tile_mem[4][0], happyTiles, happyTilesLen);
    memcpy(pal_obj_mem, happyPal, happyPalLen);

    oam_init(obj_buffer, 128);
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D;

    obj_test();

    while (1);

    return 0;
}
