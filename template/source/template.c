
/*#include <gba_console.h>
#include <gba_sprites.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>*/
#include <stdio.h>
#include <stdlib.h>
#include "toolbox.h"

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;
    m3_plot(120, 80, RGB15(31, 0, 0)); // or CLR_RED
    m3_plot(136, 80, RGB15(0, 31, 0)); // or CLR_LIME
    m3_plot(120, 96, RGB15(0, 0, 31)); // or CLR_BLUE
    while (1);
    return 0;
}




