#include "enemy.h"
#include "entities/hero.h"
#include "entities/entity.h"
#include "entities/object.h"
#include "entities/bullet.h"
#include "animation/animation.h"
#include "map/map.h"
#include "video/video.h"
#include "sprites.h"

#define CREATE_ENEMY(X,Y) {\
								X,				/*x*/\
								Y,				/*y*/\
								2,				/*ldf*/\
								2,				/*pldf*/\
								0,				/*anim_state*/\
								10,				/*lives*/\
								enemy_walking,	/*state*/\
								0xFF,			/*direction_f*/\
								0,				/*type*/\
								0,				/*cpta*/\
								enemy_drop_half_heal,		/*on_dead*/\
								0x0000,						/*reference_enemy_data*/\
								0x0000						/*sprite*/\
							}

const TEnemy enemies[] = 	{			
								CREATE_ENEMY(30,96), CREATE_ENEMY(80,156), CREATE_ENEMY(50,96), CREATE_ENEMY(60,96), CREATE_ENEMY(70,96),
								CREATE_ENEMY(20,96)
							};
#undef CREATE_ENEMY

extern u8 update_index; // From Game
u8 ref_index = 0;

u8 drop_heal_aux()
{
	for(u8 i=0;i<MAX_HEARTHS;++i)
	{
		if(hearths[i].picked != 0) return i;
	}
	return 0xFF;
}

void enemy_drop_key(u8* enemy, u8 type)
{
	object_create_key(enemy, type);
}

void enemy_drop_white_key(u8* enemy)
{
	enemy_drop_key(enemy, 0);
}

void enemy_drop_red_key(u8* enemy)
{
	enemy_drop_key(enemy,1);
}

void enemy_drop_green_key(u8* enemy)
{
	enemy_drop_key(enemy,2);
}

void enemy_drop_blue_key(u8* enemy)
{
	enemy_drop_key(enemy,3);
}

void enemy_drop_half_heal(u8* enemy)
{
	u8 index = drop_heal_aux();
	if(index == 0xFF) return;
	
	object_create_heal(enemy, index);
}

void enemy_generic_drop(u8* enemy)
{
	if(cpct_getRandom_mxor_u8() < 55) enemy_drop_half_heal(enemy);	
}


inline void save_previous_ldf(u8* enemy)
{
	(*(enemy+3)) = (*(enemy+2));
}

void enemies_reset_all()
{
	u8* p_enemy;
	for(u8 i = 0 ; i < MAX_ENEMIES ; i++)
	{
		p_enemy = &enemies[i].lives;
		(*p_enemy) = 0;
		p_enemy = &enemies[i].ctpa;
		(*p_enemy) = 0;
	}
}

void update_animation_enemy(u8* enemy)
{
	// Previous direction (pldf) == actual direction (ldf)
	if((*(enemy+3)) == (*(enemy+2)))
	{
		//anim_state == 2
		if(++(*(enemy+4)) == 2) 
		{
			//anim_state = 0
			(*(enemy+4)) = 0;
		}
	}
	else
	{
		// anim_state == 0
		(*(enemy+4)) = 0;
	}
}

void update_duck()
{
	TEnemy *p_enemy = &enemies[update_index];
	chase_hero(&enemies[update_index].x);
	p_enemy->sprite = duck_sprites[enemies[update_index].ldf][enemies[update_index].anim_state];
}

void update_girador()
{
	TEnemy *p_enemy = &enemies[update_index];
	chase_hero(&enemies[update_index].x);
	p_enemy->sprite = girador_sprites[enemies[update_index].anim_state];
}

void update_gusano()
{
	u8 *p_ctpa = &enemies[update_index].ctpa;
	TEnemy *p_enemy = &enemies[update_index];

	switch(enemies[update_index].state)
	{
		case gusano_waiting_above:
			(*p_ctpa) = 1;
			(*(p_ctpa-3)) = gusano_hiding;
			p_enemy->sprite = sprite_gusano_out;
			break;
		case gusano_hiding:

			p_enemy->sprite = gusano_sprites[(*p_ctpa)];
			if((*p_ctpa)++ == 3)
			{
				(*p_ctpa) = 0xFF;
				(*(p_ctpa-3)) = gusano_going_to_hero;
			}
			break;
		case gusano_going_to_hero:
			
			if((*p_ctpa) == 0xFF)
			{
				chase_hero(&enemies[update_index].x);

				if(	entity_x_collision(enemies[update_index].x,ENTITY_WIDTH,hero.x,ENTITY_WIDTH) 
					&& entity_y_collision(enemies[update_index].y,ENTITY_HEIGHT,hero.y,ENTITY_HEIGHT))
				{
					(*p_ctpa)++;
				}	
			}
			else
			{
				(*p_ctpa)++;
			}

			if((*p_ctpa) == 3)
			{
				(*(p_ctpa-3)) = gusano_emerging;
			}	
			break;
		case gusano_emerging:
		
			p_enemy->sprite = gusano_sprites[(*p_ctpa)];
			if((*p_ctpa)-- == 0)
			{
				(*p_ctpa) = 0;
				(*(p_ctpa-3)) = gusano_waiting_above;
			}
			break;
		default:
			(*(p_ctpa-3)) = gusano_waiting_above;
			break;
	}
}

void update_disparador()
{
	u8 *p_ctpa = &enemies[update_index].ctpa;
	TEnemy *p_enemy = &enemies[update_index];
	u8 direction = 0;

	switch(enemies[update_index].state)
	{
		case disparador_walking:
			direction = cpct_getRandom_mxor_u8() >> 4 & 0x03;
			p_enemy->ldf = direction;
			entity_perform_movement((u8*)&enemies[update_index], direction, 0);  

			if((*p_ctpa)++ > 10)
			{
				if(entity_x_collision(hero.x, ENTITY_WIDTH, enemies[update_index].x, ENTITY_WIDTH))
				{
					if(hero.y < enemies[update_index].y)
					{
						//Shot down
						p_enemy->ldf = up;
						bullet_fill(p_enemy->x+(ENTITY_WIDTH/2 - BULLET_WIDTH/2),p_enemy->y-(BULLET_HEIGHT),up);
					}
					else
					{
						//Shot up
						p_enemy->ldf = down;
						bullet_fill(p_enemy->x+(ENTITY_WIDTH/2 - BULLET_WIDTH/2),p_enemy->y+(ENTITY_HEIGHT),down);
					}
					
					(*(p_ctpa-3)) = disparador_shotting;
					(*p_ctpa) = 0;
					
				}
				else if(entity_y_collision(hero.y, ENTITY_HEIGHT, enemies[update_index].y, ENTITY_HEIGHT))
				{
					if(hero.x < enemies[update_index].x)
					{
						//Shot right
						p_enemy->ldf = left; 
						bullet_fill(p_enemy->x-(BULLET_WIDTH),p_enemy->y+(ENTITY_HEIGHT/2 - BULLET_HEIGHT/2),left);
					}
					else
					{
						//Shot left
						p_enemy->ldf = right;
						bullet_fill(p_enemy->x+(ENTITY_WIDTH),p_enemy->y+(ENTITY_HEIGHT/2 - BULLET_HEIGHT/2),right);
					}
					(*(p_ctpa-3)) = disparador_shotting;
					(*p_ctpa) = 0;
				}
			}
			p_enemy->sprite = disparador_sprites[direction];
			break;
		case disparador_shotting:
			p_enemy->sprite = disparador_sprites_attacking[enemies[update_index].ldf];

			//create_bullet

			(*(p_ctpa-3)) = disparador_walking;

			break;
		default:
			(*(p_ctpa-3)) = disparador_walking;
			break;
	}
}

void perform_action()
{
	switch(enemies[update_index].type)
		{
		case duck:
			update_duck();
			break;
		case girador:
			update_girador();
			break;
		case gusano:
			update_gusano();
			break;
		case disparador:
			update_disparador();
			break;
	}
}

bool enemy_is_hit()
{
	u8 *p_data = &enemies[update_index].ctpa;

	if(enemies[update_index].state == enemy_hit)
	{
		if(++(*p_data) == DISPLACEMENT_ENEMY)
		{
			(*p_data) = 0;
			p_data = &enemies[update_index].state;
			(*p_data) = enemy_walking;
		}
		else
		{
			entity_perform_movement((u8*)&enemies[update_index], enemies[update_index].direction_f, 0);
		}
		return true;
	}
	return false;
}

inline void check_and_perform()
{
	
	if(!enemy_is_hit())
	{
		perform_action();
	}
	
	if(can_hit_hero() && check_collision_hero()){

		switch(enemies[update_index].type)
		{
			case 0: case 2: case 3:
				hero_decrease_heal(1);
				break;
			case 1:
				aux_f = enemies[update_index].ldf;
				hero_decrease_heal(2);
				break;
		} 
	}
}

bool can_hit_hero()
{
	/*enemy_walking = 0,		// 0
   	enemy_hit  					// 1
	gusano_waiting_above = 2, 	// 2
   	gusano_hiding,				// 3
   	gusano_going_to_hero,  		// 4
   	gusano_emerging  			// 5*/
	switch(enemies[update_index].state)
	{
		case enemy_walking: case gusano_waiting_above: case gusano_hiding: case gusano_emerging:
		case disparador_walking: case disparador_shotting:
			return true;
		default:
			return false;
	}
}

//Check collision of actual enemy with hero
inline bool check_collision_hero()
{
	return entity_x_collision(enemies[update_index].x,ENTITY_WIDTH,hero.x,ENTITY_WIDTH) && entity_y_collision(enemies[update_index].y,ENTITY_HEIGHT,hero.y,ENTITY_HEIGHT);
}

bool enemy_decrease_heal(u8 index)
{
	u8* p_enemy = &enemies[index].lives;
	
	if(--(*p_enemy) == 0)
	{
		enemies[index].on_dead((u8*)&enemies[index]);
		return true;
	}

	return false;
}

void enemy_on_hit(u8 index)
{	
	u8* p_enemy = &enemies[index].state;

	if(!enemy_decrease_heal(index))
	{
		(*(p_enemy)) = enemy_hit;
		(*(++p_enemy)) = hero.ldf;
	}
}

//Update Enemy: Perform action assigned and checkcollision
void enemy_update()
{
	if(enemies[update_index].lives > 0)
	{
		check_and_perform();
	}

	++update_index;

	if(enemies[update_index].lives > 0)
	{
		check_and_perform();
	}
}

void enemy_draw(){
	for(u8 i = 0 ; i < MAX_ENEMIES ; ++i)
	{
		if(enemies[i].lives > 0 && video_isInsideViewport(enemies[i].x, enemies[i].y, ENTITY_WIDTH, ENTITY_HEIGHT))
		{
			cpct_drawSpriteMasked(enemies[i].sprite, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(enemies[i].x), RELATIVE_POSITION_Y(enemies[i].y)), ENTITY_WIDTH, ENTITY_HEIGHT);
		}
	}
}

bool enemy_collision_left(u8* entity){
	i8 i = update_index-1;
	
	//Mientras la entidad de la izquierda colisione en el eje x con nuestra entidad  
	while(i >= 0)
	{
		if(	enemies[i].lives != 0 
			&& entity_x_collision(enemies[i].x,ENTITY_WIDTH,(*entity),ENTITY_WIDTH) 
			&& entity_y_collision(enemies[i].y,ENTITY_HEIGHT,(*(entity+1)),ENTITY_HEIGHT))
		{
			return true;	
		}	
		--i;
	}
	return false;
}

bool enemy_collision_right(u8* entity){
	u8 i = update_index+1;
	
	//Mientras la entidad de la izquierda colisione en el eje x con nuestra entidad
	while(i < MAX_ENEMIES)
	{
		if(	enemies[i].lives != 0 
			&& entity_x_collision(enemies[i].x,ENTITY_WIDTH,(*entity),ENTITY_WIDTH) 
			&& entity_y_collision(enemies[i].y,ENTITY_HEIGHT,(*(entity+1)),ENTITY_HEIGHT))
		{
			return true;
		}
		++i;
	}
	return false;
}

void chase_hero(u8 *enemy){
	save_previous_ldf(enemy);

	if(hero.x < (*enemy))
	{
		(*(enemy+2)) = left;
		entity_perform_movement(enemy, left, 0);
	}
	else if(hero.x > (*enemy))
	{
		(*(enemy+2)) = right;
		entity_perform_movement(enemy, right, 0);
	}
	
	if(hero.y < (*(enemy+1)))
	{	
		(*(enemy+2)) = up;
		entity_perform_movement(enemy, up, 0);
	}
	else if(hero.y > (*(enemy+1)))
	{	
		(*(enemy+2)) = down;
		entity_perform_movement(enemy, down, 0);		
	}

	update_animation_enemy(enemy);
}

/*void shot_hero(u8 *enemy){

	if(hero.x < (*enemy))
	{
		if((*(enemy+1))+ENTITY_HEIGHT > hero.y && hero.y+ENTITY_HEIGHT > (*(enemy+1)))
		{
		
		}

		entity_perform_movement(enemy, right, 0);
		(*(enemy+2)) = left;
	}
	else if(hero.x > (*enemy))
	{
		if((*(enemy+1))+ENTITY_HEIGHT > hero.y && hero.y+ENTITY_HEIGHT > (*(enemy+1)))
		{
		
		}
		(*(enemy+2)) = right;
		entity_perform_movement(enemy, left, 0);
	}
	
	if(hero.y < (*(enemy+1)))
	{	
		if((*enemy)+ENTITY_WIDTH > hero.x && hero.x+ENTITY_WIDTH > (*enemy))
		{
		
		}
		(*(enemy+2)) = up;
		entity_perform_movement(enemy, down, 0);		
	}
	else if(hero.y > (*(enemy+1)))
	{	
		if((*enemy)+ENTITY_WIDTH > hero.x && hero.x+ENTITY_WIDTH > (*enemy))
		{
		
		}
		(*(enemy+2)) = down;
		entity_perform_movement(enemy, up, 0);
	}
}*/
