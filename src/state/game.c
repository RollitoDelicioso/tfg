#include "game.h"
#include "entities/enemy.h"
#include "entities/hero.h"
#include "constants.h"

u8 run = false;
u8 update_index = 0;
//Using InsertionSort


void sort_enemies(void){
	u8 **array = ref_enemies;
   	u8 i, j;
   	u8* swap_value;
	for (i = 1 ; i < MAX_ENEMIES; i++) {
    	j = i;
	    while ( j > 0 && (*array[j-1]) > (*array[j])) {
	      swap_value = array[j];
	      array[j] = array[j-1];
	      array[j-1] = swap_value;
	    }
  	}
}

void update(){
	cpct_setBorder(2);
	hero_update();
	enemy_update();
	cpct_setBorder(3);
}

void erase_and_draw(){
	cpct_setBorder(4);
	hero_erase_and_draw();
	enemy_erase_and_draw();
	cpct_setBorder(5);
}

void run_game(){
	while(hero.lives){
		while(!run);
		erase_and_draw();
		cpct_setBorder(6);
		sort_enemies();
		cpct_setBorder(7);
		update(); 
		cpct_setBorder(9);
		update_index += 2;
		if(update_index == 6){
			update_index = 0;
		}
		run = false;
	}
}