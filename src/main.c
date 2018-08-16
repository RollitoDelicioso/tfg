#include <cpctelera.h>
#include "state/game.h"
#include "state/menu.h"
#include "constants.h"
#include "sprites.h"
#include "tilemap/tiles.h"

void handlerInterruption()
{
	static u8 interruption_counter = 0;

	//cpct_setBorder(0);
	//run = false;		

	//if(++interruption_counter == 5)
	//{
	//	run = true;
	//	cpct_setBorder(8);
	//}

	if(++interruption_counter == 6)
	{
		interruption_counter = 0;
		cpct_scanKeyboard_f();
	}
}

void initializeCPC(void)
{
	cpct_disableFirmware();
   	cpct_waitVSYNC();
	cpct_setInterruptHandler ( handlerInterruption );
	cpct_setVideoMode(0);
   	cpct_setPalette(tileset_palette, 16);
	
}

void main(void)
{
    cpct_setStackLocation((void*) 0x8000);
	initializeCPC();
   	while (1){
   		show_menu();
   		run_game();
   	}
}
