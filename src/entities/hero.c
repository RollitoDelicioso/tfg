#include "hero.h"
#include "animation/animation.h"
#include "entities/enemy.h"
#include "entities/object.h"
#include "entities/entity.h"
#include "entities/door.h"
#include "entities/bullet.h"
#include "sprites.h"
#include "map/map.h"
#include "tilemap/tiles.h"
#include "video/video.h"
#include "video/camera.h"
#include "video/ui.h"


const THero hero = {	.x = 		6*4,
						.y = 		14*8 + 40,
						.ldf = 		1,
						.pldf = 	1,
						.sprite = 	sprite_hero_front_1,
						.lives = 	8,
						.state = 	hero_idle
					};
const u8 keys[4] = { 5,0,0,0 };

u8 god_mode = 0;
u8 aux_f = 0xFF;

void hero_add_key()
{
	u8* p_keys = &keys[key.type];
	(*p_keys)++;
	ui_update_keys((*p_keys), key.type);
}

void hero_increase_heal()
{
	u8* p_hero = &hero.lives;
	if((*p_hero)+1 < 9){
		ui_update_heal(++(*p_hero));
	}
}


void hero_decrease_heal(u8 cuantity)
{
	if(hero.state != hero_small_hit && hero.state != hero_big_hit){
		u8* hero_p = &hero.lives;
		u8 to_minus = cuantity;

		while((*hero_p) > 0 && to_minus > 0)
		{
			ui_update_heal(--(*hero_p));
			to_minus--;
		}
		
		hero_p = &hero.state;

		if(cuantity > 1)
		{
			god_mode = 10;
			(*hero_p) = hero_big_hit;

		}
		else
		{
			god_mode = 20;
			(*hero_p) = hero_small_hit;	
		}
		
	}
}

inline bool attack()
{
	THero *hero_aux = &hero;
	if(cpct_isKeyPressed(Key_Space))
	{
		if(video_isInsideViewport(hero.x, hero.y, ENTITY_WIDTH, ENTITY_HEIGHT))
		{
			switch(hero.ldf)
			{
				case up:
					if(RELATIVE_POSITION_Y(hero.y) < (SCREEN_HEIGHT-VIEWPORT_HEIGHT)+SWORD_HEIGHT) return false;
				case down:
					if(RELATIVE_POSITION_Y(hero.y) > (SCREEN_HEIGHT-ENTITY_HEIGHT)-SWORD_HEIGHT) return false;
				case left:
					if(RELATIVE_POSITION_X(hero.x) < SWORD_WIDTH) return false;
				case right:
					if(RELATIVE_POSITION_X(hero.x) > (VIEWPORT_WIDTH-ENTITY_WIDTH)-SWORD_WIDTH) return false;
			}

			hero_aux->state = hero_attacking;
			aux_f = 0xFF;
			
			hero_aux->sprite=hero_attack_sword[hero.ldf];
			return true; 	
		}
	}
	return false;
}

bool hero_check_collision_door()
{
	u8* p_key = 0;
	u8 	hero_direction = hero.ldf; 
	u8* p_hero = &hero.x;


	if(door.id != 0xFF && doors_closed[door.id] 
		&& entity_x_collision(door.x,ENTITY_WIDTH,hero.x,ENTITY_WIDTH)
		&& entity_y_collision(door.y,ENTITY_HEIGHT,hero.y,ENTITY_HEIGHT))
	{
		if(hero.state == hero_big_hit)
		{
			p_hero = &hero.x;
			hero_direction = aux_f;
		}

		p_key = &keys[door.type];
		if(*p_key > 0)
		{
			object_decrease_key(p_key);
			ui_update_keys((*p_key), door.type);
			return true;
		}

		switch(hero_direction)
		{
			case up:
				(*(p_hero+1)) += HERO_SPEED_Y;
				break;
			case down:
				(*(p_hero+1)) -= HERO_SPEED_Y;
				break;
			case left:
				(*p_hero) += 2;
				break;
			case right:
				(*p_hero) -= 2;
				break;

		}
		return false;
	}
	return true;	
}

inline void check_collision_objects()
{
	TObject* p_object;
	TKey* p_key;
	for(u8 i = 0 ; i < MAX_HEARTHS ; ++i)
	{
		if(!hearths[i].picked 
			&& entity_x_collision(hearths[i].x,OBJECT_HEARTH_WIDTH,hero.x,ENTITY_WIDTH)
			&& entity_y_collision(hearths[i].y,OBJECT_HEARTH_HEIGHT,hero.y,ENTITY_HEIGHT))
		{
			p_object = &hearths[i];
			p_object->picked++;
			p_object->object_action();
			break;
		}
	}

	if(!key.picked && entity_x_collision(key.x,OBJECT_KEY_WIDTH,hero.x,ENTITY_WIDTH)
		&& entity_y_collision(key.y,OBJECT_KEY_HEIGHT,hero.y,ENTITY_HEIGHT))
	{
		p_key = &key;
		p_key->picked++;
		p_key->object_action();
	}
}

inline void save_previous_ldf(u8* p_ldf)
{
	(*(p_ldf+1)) = (*p_ldf);
}

void move_hero()
{
	static u8 every_five_steps = 0;
	bool changed = false;
	u8 *p_hero = (u8*)&hero;
	u8 *p_hero_ldf = (u8*)&hero.ldf;
	THero *p_hero_sprite = &hero;

	save_previous_ldf(&hero.ldf);

	if (cpct_isKeyPressed(Key_A))
	{
		if((*p_hero) > 0)
		{
			if(hero_check_collision_door() && CHECK_MOVE_HORIZONTAL(hero.x-HERO_SPEED_X,hero.y, 1))
			{ 
				(*p_hero) -= HERO_SPEED_X;
				(*p_hero_ldf) = left;
				changed = true;
			}
		}
		else
		{
			map_can_change(left);
		}
	}
	else if (cpct_isKeyPressed(Key_D))
	{
		if((*p_hero) < max_w-ENTITY_WIDTH)
		{
			if(hero_check_collision_door() && CHECK_MOVE_HORIZONTAL(hero.x+ENTITY_WIDTH,hero.y, 1))
			{
				(*p_hero) += HERO_SPEED_X;
				(*p_hero_ldf) = right;
				changed = true;
			}
		}
		else
		{
			map_can_change(right);
		}
	}

	p_hero++;

	if (cpct_isKeyPressed(Key_W))
	{
		if((*p_hero) > SCREEN_HEIGHT-(VIEWPORT_HEIGHT-2))
		{
			if(hero_check_collision_door() && CHECK_MOVE_VERTICAL(hero.x, hero.y-HERO_SPEED_Y, 1))
			{
				(*p_hero) -= HERO_SPEED_Y;
				(*p_hero_ldf) = up;
				changed = true;
			}
		}
		else
		{
			map_can_change(up);
		}
	}
	else if (cpct_isKeyPressed(Key_S))
	{
		if((*p_hero) < (max_h+SCREEN_OFFSET)-(ENTITY_HEIGHT+2))
		{
			if(hero_check_collision_door() && CHECK_MOVE_VERTICAL(hero.x, hero.y+ENTITY_HEIGHT+HERO_SPEED_Y, 1))
			{
				(*p_hero) += HERO_SPEED_Y;
				(*p_hero_ldf) = down;
				changed = true;
			}
		}
		else
		{
			map_can_change(down);
		}
	}

	// Previous direction == actual direction
	if((*(p_hero+1)) == (*(p_hero+2)))
	{
		if(++aux_f == 2)
		{
			aux_f = 0;
		}
		if(changed)
		{
			++every_five_steps;				
		}
	}
	else
	{
		aux_f = 0;
		every_five_steps = 5;
	}

	if(every_five_steps > 4)
	{
		p_hero_sprite->sprite = hero_sprites[hero.ldf][aux_f];
		every_five_steps = 0;
	}

	check_collision_objects();
}

bool can_be_hit(u8 state)
{
	switch(state)
	{
		case enemy_walking: case gusano_waiting_above: case gusano_hiding: case gusano_emerging:
			return true;
		default:
			return false;
	}
	/*enemy_walking = 0,		// 0
   	enemy_hit  					// 1
	gusano_waiting_above = 2, 	// 2
   	gusano_hiding,				// 3
   	gusano_going_to_hero,  		// 4
   	gusano_emerging  			// 5*/
}

void check_collision_attack(u8 x, u8 y, u8 w, u8 h)
{
	for(u8 i = 0 ; i < MAX_ENEMIES ; ++i)
	{
		if(can_be_hit(enemies[i].state) && enemies[i].lives > 0 && entity_x_collision(enemies[i].x,ENTITY_WIDTH,x,w)
			&& entity_y_collision(enemies[i].y,ENTITY_HEIGHT,y,h))
		{
			enemy_on_hit(i);
		}
	}

	for(u8 i = 0 ; i < MAX_ENEMIES ; ++i)
	{
		if(bullets[i].x != 0xFF && bullets[i].hit_by_hero == 0 
			&& entity_x_collision(bullets[i].x,BULLET_WIDTH,x,w)
			&& entity_y_collision(bullets[i].y,BULLET_HEIGHT,y,h))
		{
			bullet_hit_by_hero(i);
		}
	}
}

void draw_attack_and_check_collision()
{
	THero* hero_aux = &hero;
	u8 sprite_to_show = 0;

	switch(++aux_f){
		case 0:
			sprite_to_show = 0;
			break;
		case 1: case 2: 
			sprite_to_show = 1;
			break;
		case 3:
			aux_f = 0xFF;
			hero_aux->state = hero_idle;
			hero_aux->sprite = hero_sprites[hero.ldf][0];
			return;
	}
	
	switch(hero.ldf){
		case up:
			check_collision_attack(hero.x, hero.y-ENTITY_HEIGHT/2, attack_animation_up[0].width, attack_animation_up[0].height);
			if(sprite_to_show)
			{
				cpct_drawSpriteMasked(attack_animation_up[sprite_to_show].sprite, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(hero.x+2), RELATIVE_POSITION_Y(hero.y-ENTITY_HEIGHT/2)), attack_animation_up[sprite_to_show].width, attack_animation_up[sprite_to_show].height);
			}
			else
			{
				cpct_drawSpriteMasked(attack_animation_up[sprite_to_show].sprite, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(hero.x), RELATIVE_POSITION_Y(hero.y-ENTITY_HEIGHT/2)), attack_animation_up[sprite_to_show].width, attack_animation_up[sprite_to_show].height);
			}
			break;
		case down:
			check_collision_attack(hero.x, hero.y+ENTITY_HEIGHT, attack_animation_down[0].width, attack_animation_down[0].height);
			cpct_drawSpriteMasked(attack_animation_down[sprite_to_show].sprite, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(hero.x), RELATIVE_POSITION_Y(hero.y+ENTITY_HEIGHT)), attack_animation_down[sprite_to_show].width, attack_animation_down[sprite_to_show].height);
			break;
		case left:
			check_collision_attack(hero.x-3, hero.y, attack_animation_left[0].width, attack_animation_left[0].height);
			if(sprite_to_show)
			{
				cpct_drawSpriteMasked(attack_animation_left[sprite_to_show].sprite, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(hero.x-3), RELATIVE_POSITION_Y(hero.y+ENTITY_HEIGHT/2)), attack_animation_left[sprite_to_show].width, attack_animation_left[sprite_to_show].height);
			}
			else
			{
				cpct_drawSpriteMasked(attack_animation_left[sprite_to_show].sprite, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(hero.x-3), RELATIVE_POSITION_Y(hero.y)), attack_animation_left[sprite_to_show].width, attack_animation_left[sprite_to_show].height);
			}
			break;
		case right:
			check_collision_attack(hero.x+ENTITY_WIDTH, hero.y, attack_animation_right[0].width, attack_animation_right[0].height);
			if(sprite_to_show)
			{
				cpct_drawSpriteMasked(attack_animation_right[sprite_to_show].sprite, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(hero.x+ENTITY_WIDTH), RELATIVE_POSITION_Y(hero.y+ENTITY_HEIGHT/2)), attack_animation_right[sprite_to_show].width, attack_animation_right[sprite_to_show].height);
			}
			else
			{
				cpct_drawSpriteMasked(attack_animation_right[sprite_to_show].sprite, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(hero.x+ENTITY_WIDTH), RELATIVE_POSITION_Y(hero.y)), attack_animation_right[sprite_to_show].width, attack_animation_right[sprite_to_show].height);
			}
			break;		
	}	
}

void decrease_god_mode(){
	u8* hero_p;

	if(--god_mode == 0)
	{ 
		aux_f = 0xFF;
		hero_p = &hero.state;
		(*hero_p) = hero_walking;
	}
}

void hero_update()
{
	switch(hero.state)
	{
		case hero_idle:case hero_walking:
			if(!attack()) move_hero();
			break;

		case hero_attacking:
			draw_attack_and_check_collision();
			break;

		case hero_small_hit:
			move_hero();
			decrease_god_mode();
			break;
		case hero_big_hit:
			entity_perform_movement((u8*)&hero, aux_f, 1);
			decrease_god_mode();
			break;
	}
}

inline void hero_draw()
{
	if(god_mode != -1 && god_mode%2 == 0)
	{
		if(video_isInsideViewport(hero.x, hero.y, ENTITY_WIDTH, ENTITY_HEIGHT))
		{
			cpct_drawSpriteMasked(hero.sprite, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(hero.x), RELATIVE_POSITION_Y(hero.y)), ENTITY_WIDTH, ENTITY_HEIGHT);
		}
	}
}