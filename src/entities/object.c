#include "object.h"
#include "entities/hero.h"
#include "entities/enemy.h"
#include "entities/door.h"
#include "sprites.h"
#include "video/video.h"
#include "video/ui.h"
#include "data_types.h"

#define INIT_OBJECT_HEARTH {.x = 0 , .y = 0, .sprite = sprite_half_hearth, .picked = 1, .object_action = add_heal}
#define INIT_OBJECT_KEY {.x = 0 , .y = 0, .type = 0, .picked = 1, .object_action = add_key, .enemy_to_change = 0x0000}

const u8** const key_sprites[4] = {sprite_white_key,sprite_red_key,sprite_green_key,sprite_blue_key};
const TObject hearths[MAX_HEARTHS] = { INIT_OBJECT_HEARTH, INIT_OBJECT_HEARTH, INIT_OBJECT_HEARTH };
const TKey key = INIT_OBJECT_KEY;

void object_decrease_key(u8* p_key)
{
	(*p_key)--;
	door_open_door();
}

void object_reset_all()
{
	u8* p_object;
	for(u8 i = 0;i<MAX_HEARTHS;i++)
	{
		p_object = &hearths[i].picked;
		(*p_object) = 1;
	}
	p_object = &key.picked;
	(*p_object) = 1;
}

void add_key()
{
	struct TEnemyData *change = (struct TEnemyData*) key.enemy_to_change;
	change->on_dead	= enemy_generic_drop;	
	hero_add_key();
}

void add_heal()
{
	hero_increase_heal();
}

void object_create_key_aux(u8* item, u8* enemy, u8 type)
{
	(*item++) = (*enemy++); 	// x
	(*item++) = (*enemy++); 	// y
	(*item++) =  type;		 	// skip sprite
	(*item) = 0;				 // picket = 0
}

void object_create_heal_aux(u8* item, u8* enemy)
{
	(*item++) = (*enemy++); 	// x
	(*item++) = (*enemy++); 	// y
	item++; 		 		 	// skip sprite
	item++; 		 		 	// skip sprite
	(*item) = 0;				 // picket = 0
}

void object_create_key(u8* enemy, u8 type)
{
	object_create_key_aux((u8*)&key, enemy, type);		
}

void object_create_heal(u8* enemy, u8 index)
{
	object_create_heal_aux((u8*)&hearths[index], enemy);
}

void draw_objects()
{
	for(u8 i = 0 ; i < MAX_HEARTHS ; ++i)
	{
		if(hearths[i].picked == 0 && video_isInsideViewport(hearths[i].x, hearths[i].y, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT))
		{
			cpct_drawSpriteMasked(hearths[i].sprite, cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(hearths[i].x), RELATIVE_POSITION_Y(hearths[i].y)), OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
		}
	}

	if(key.picked == 0 && video_isInsideViewport(key.x, key.y, OBJECT_KEY_WIDTH, OBJECT_KEY_HEIGHT))
	{
			cpct_drawSpriteMasked(key_sprites[key.type], cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(key.x), RELATIVE_POSITION_Y(key.y)), OBJECT_KEY_WIDTH, OBJECT_KEY_HEIGHT);
	}
}

