#include <cpctelera.h>
#include "state/game.h"
#include "state/menu.h"
#include "constants.h"

void handlerInterruption(){
	static u8 interruption_counter = 0;

	if(++interruption_counter == 4){
		run = true;
		cpct_setBorder(8);
		return;
	}

	if(interruption_counter == 6){
		interruption_counter = 0;
		cpct_scanKeyboard_f();
	}
	cpct_setBorder(0);
	run = false;		
}

void initializeCPC(void){
	cpct_disableFirmware();
   	cpct_setVideoMode(0);
   	//cpct_setPalette(g_palette, 13);
	cpct_setBorder(HW_BLACK); 
	cpct_setInterruptHandler ( handlerInterruption );
}

void main(void) {
	initializeCPC();

   	while (1){
   		show_menu();
   		run_game();
   	}
}
