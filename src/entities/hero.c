#include "hero.h"
#include "constants.h"

const THero hero = {0,42,0,42,1,(u8*)0x0000,1};

void hero_update(){
	u8 *p_hero = (u8*)&hero.px;
	u8 *p_hero_ldf = (u8*)&hero.ldf;

	(*p_hero) = hero.x;
	p_hero++;
	(*p_hero) = hero.y;

	p_hero = (u8*)&hero;

	if (cpct_isKeyPressed(Key_A)){

		if((*p_hero) > 0){
			(*p_hero) -= HERO_SPEED_X;
			(*p_hero_ldf) = 2;
		}
	}else if (cpct_isKeyPressed(Key_D)){
		
		if((*p_hero) < 80-4){
			(*p_hero) += HERO_SPEED_X;
			(*p_hero_ldf) = 3;
		}
	}

	p_hero++;

	if (cpct_isKeyPressed(Key_W)){

		if((*p_hero) > 0){
			(*p_hero) -= HERO_SPEED_Y;
			(*p_hero_ldf) = 0;
		}
	}else if (cpct_isKeyPressed(Key_S)){

		if((*p_hero) < 200-16){
			(*p_hero) += HERO_SPEED_Y;
			(*p_hero_ldf) = 1;
		}
	}

	if(cpct_isKeyPressed(Key_Space)){
		attack();
	}
}

void hero_erase_and_draw(){
	cpct_drawSolidBox(cpct_getScreenPtr((void*)0xC000, hero.px, hero.py), 0, 4, 16);
	
	cpct_drawSolidBox(cpct_getScreenPtr((void*)0xC000, hero.x, hero.y), 3, 4, 16);
}

inline void attack(){
	switch(hero.ldf){
		case 0:
			//Arriba
			
			break;
		case 1:
			//Abajo
			
			break;
		case 2:
			//Izquierda
			
			break;
		case 3:
			//Derecha
			
			break;
	}
}