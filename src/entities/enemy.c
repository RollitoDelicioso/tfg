#include "enemy.h"
#include "entities/hero.h"
#include "constants.h"

#define CREATE_ENEMY(X) {X,0,X,0,2,chase_hero,0,2,1,(u8*)0x4000}
const TEnemy enemies[] = 	{			
								CREATE_ENEMY(10), CREATE_ENEMY(20), CREATE_ENEMY(30), CREATE_ENEMY(40), CREATE_ENEMY(50),
								CREATE_ENEMY(60)
							};
#undef CREATE_ENEMY

const u8* const ref_enemies[] = {	
									(u8*)&enemies[0], (u8*)&enemies[1], (u8*)&enemies[2], (u8*)&enemies[3], (u8*)&enemies[4],
									(u8*)&enemies[5]
								};

extern u8 update_index; // From Game

void check_and_perform(u8 index){
	u8 *p_enemy = &enemies[index].ctpa; 
	if(++(*p_enemy) == enemies[index].stpa){
		(*p_enemy) = 0;
		enemies[index].perform_action((u8*)&enemies[index]);
	}
}

void enemy_update(){
	check_and_perform(update_index);
	check_and_perform(update_index+1);
}

void enemy_erase_and_draw(){
	u8 index = update_index+1;
	cpct_drawSolidBox(cpct_getScreenPtr((void*)0xC000, enemies[update_index].px, enemies[update_index].py), 0, 4, 16);
	cpct_drawSolidBox(cpct_getScreenPtr((void*)0xC000, enemies[index].px, enemies[index].py), 0, 4, 16);

	cpct_drawSolidBox(cpct_getScreenPtr((void*)0xC000, enemies[update_index].x, enemies[update_index].y), 10, 4, 16);
	cpct_drawSolidBox(cpct_getScreenPtr((void*)0xC000, enemies[index].x, enemies[index].y), 10, 4, 16);
}

void chase_hero(u8 *enemy){

	u8 *p_enemy = enemy+2;
	(*p_enemy) = (*enemy);
	p_enemy++;
	(*p_enemy) = (*(enemy+1));


	if(hero.x < (*enemy))
	{
		(*enemy)--;
	}
	else
	{
		(*enemy)++;
	}
	enemy++;
	if(hero.y < (*enemy))
	{
		(*enemy) -= 3;
	}
	else
	{
		(*enemy) += 3;
	}
}
