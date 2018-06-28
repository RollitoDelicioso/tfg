//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2018 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include <cpctelera.h>
#include "constants.h"
#include "structs.h"

#define N 10
#define CREATE_ENEMY(X) {X,2,2,do_Nothing,2,2,2,(u8*)0x4000}
const TEnemy enemies[] = 	{			CREATE_ENEMY(1), CREATE_ENEMY(5), CREATE_ENEMY(8), CREATE_ENEMY(4), CREATE_ENEMY(2), 
										CREATE_ENEMY(3), CREATE_ENEMY(9), CREATE_ENEMY(7), CREATE_ENEMY(6), CREATE_ENEMY(0)
							};

const TEnemy* const ref_enemies[] = {	&enemies[0], &enemies[1], &enemies[2], &enemies[3], &enemies[4],
										&enemies[5], &enemies[6], &enemies[7], &enemies[8], &enemies[9] 
									};

void do_Nothing(u8 *val){}

//Using InsertionSort
void sort_enemies(void){
	TEnemy **array = ref_enemies;
   	u8 i, j;
   	TEnemy* swap_value;
	for (i = 1 ; i < N; i++) {
    	j = i;
	    while ( j > 0 && array[j-1]->x > array[j]->x) {
	      swap_value = array[j];
	      array[j] = array[j-1];
	      array[j-1] = swap_value;
	 
	      j--;
	    }
  	}
}

void initializeCPC(void){
	cpct_disableFirmware();         // Firmware must be disabled for this application to work
   	cpct_setVideoMode(0);           // Set Mode 0 (160x200, 16 Colours)
   	//cpct_setPalette(g_palette, 13); // Set Palette 
	cpct_setBorder(HW_BLACK); // Set the border and background colours to black
}

void main(void) {
	initializeCPC();
	sort_enemies();
   	while (1);
}