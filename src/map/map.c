#include "map.h"
#include "decompresor/exomizer.h"
#include "entities/hero.h"
#include "entities/enemy.h"
#include "entities/object.h"
#include "entities/portal.h"
#include "entities/door.h"
#include "video/video.h"
#include "video/camera.h"
#include "data_types.h"
#include "sprites.h"
#include "tilemap/tiles.h"


#define CREATE_CHECKPOINT(ID,X,Y) {\
								.id = ID,		\
								.x= X,		\
								.y= Y		\
							}

const TCheckpoint actual_checkpoint = CREATE_CHECKPOINT(18,6,15);


const TCheckpoint checkpoints[CHECKPOINTS] = {
	CREATE_CHECKPOINT(18,6,15),
	CREATE_CHECKPOINT(26,15,6),
	CREATE_CHECKPOINT(29,25,9),
	CREATE_CHECKPOINT(23,11,3),
	CREATE_CHECKPOINT(2,15,18),
	CREATE_CHECKPOINT(16,24,11),
	CREATE_CHECKPOINT(31,14,8)
};

const u8 map[SCREEN_HEIGHT_T][SCREEN_WIDTH_T] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

const u8* const sprite_by_type[] = {sprite_duck_left_1, sprite_girador_1, sprite_gusano_out, sprite_disparador_front, sprite_princess};

//Index of the global array of maps
const u8 next_maps[4] = {0xFF,0xFF,0xFF,0xFF};

const bool win = false;

#define CREATE_MAP(WIDTH, HEIGHT, MAP_COMPRESSED, AM_0, AM_1, AM_2, AM_3, N_ENEMIES, P_ENEMIES, P_DIRECTION, P_DOOR, P_EXTERNAL) { 	\
																														  	.map_width = WIDTH, \
																															.map_height = HEIGHT, \
																															.map_compressed_data = MAP_COMPRESSED, \
																															.adjacent_maps = {AM_0,AM_1,AM_2,AM_3}, \
																															.number_enemies = N_ENEMIES, \
																															.enemies_array = (u8*)P_ENEMIES, \
																															.portal_direction = (u8*)P_DIRECTION, \
																															.door = (u8*)P_DOOR, \
																															.external_portal = (u8*)P_EXTERNAL \
																														}

const TMap all_maps_compressed[] = {
	CREATE_MAP(16, 22, G_c_map_0, 0xFF,6,0xFF,0xFF, 0, 0x0000, 0x0000, 0x0000, &external_portal_map_0),
	CREATE_MAP(20, 22, G_c_map_1, 0xFF,7,0xFF,2, 1, &enemies_map_1, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(28, 26, G_c_map_2, 0xFF,0xFF,1,3, 2, &enemies_map_2, 0x0000, &door_map_2, &external_portal_map_2),
	CREATE_MAP(32, 25, G_c_map_3, 0xFF,0xFF,2,4, 2, &enemies_map_3, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(32, 25, G_c_map_4, 0xFF,0xFF,3,5, 2, &enemies_map_4, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(32, 20, G_c_map_5, 0xFF,12,4,0xFF, 5, &enemies_map_5, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(16, 22, G_c_map_6, 0,14,0xFF,0xFF, 2, &enemies_map_6, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(20, 22, G_c_map_7, 1,0x0F,0xFF,0xFF, 3, &enemies_map_7, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(28, 20, G_c_map_8, 0xFF,16,0xFF,0xFF, 3, &enemies_map_8, 0x0000, 0x0000, &external_portal_map_8),
	CREATE_MAP(20, 21, G_c_map_9, 0xFF,17,0xFF,10, 0, 0x0000, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(16, 20, G_c_map_10, 0xFF,0xFF,9,11, 0, 0x0000, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(28, 20, G_c_map_11, 0xFF,0xFF,10,0xFF, 0, 0x0000, 0x0000, 0x0000, &external_portal_map_11),
	CREATE_MAP(27, 20, G_c_map_12, 5,0xFF,0xFF,13, 3, &enemies_map_12, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(32, 20, G_c_map_13, 0xFF,19,12,0xFF, 4, &enemies_map_13, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(16, 20, G_c_map_14, 6,0xFF,0xFF,15, 2, &enemies_map_14, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(20, 20, G_c_map_15, 7,20,14,0xFF, 2, &enemies_map_15, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(28, 20, G_c_map_16, 8,0xFF,0xFF,0xFF, 3, &enemies_map_16, 0x0000, 0x0000, &external_portal_map_16),
	CREATE_MAP(20, 20, G_c_map_17, 9,0xFF,0xFF,18, 0, 0x0000, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(15, 20, G_c_map_18, 0xFF,21,17,0xFF, 0, 0x0000, 0x0000, &door_map_18, &external_portal_map_18),
	CREATE_MAP(32, 24, G_c_map_19, 13,23,0xFF,0xFF, 3, &enemies_map_19, 0x0000, &door_map_19, 0x0000),
	CREATE_MAP(15, 20, G_c_map_20, 0xFF,25,0xFF,0xFF, 0, 0x0000, 0x0000, &door_map_20, &external_portal_map_20),
	CREATE_MAP(15, 20, G_c_map_21, 18,27,0xFF,0xFF, 0, 0x0000, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(30, 20, G_c_map_22, 0xFF,28,0xFF,23, 3, &enemies_map_22, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(29, 20, G_c_map_23, 19,0xFF,22,0xFF, 4, &enemies_map_23, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(16, 21, G_c_map_24, 0xFF,30,0xFF,25, 0, 0x0000, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(15, 20, G_c_map_25, 20,0xFF,24,0xFF, 0, 0x0000, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(22, 24, G_c_map_26, 0xFF,32,0xFF,0xFF, 2, &enemies_map_26, 0x0000, 0x0000, &external_portal_map_26),
	CREATE_MAP(26, 24, G_c_map_27, 21,33,0xFF,0xFF, 3, &enemies_map_27, &portal_map_27, 0x0000, 0x0000),
	CREATE_MAP(22, 20, G_c_map_28, 22,35,0xFF,29, 3, &enemies_map_28, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(32, 20, G_c_map_29, 0xFF,0xFF,28,0xFF, 4, &enemies_map_29, &portal_map_29, &door_map_29, &external_portal_map_29),
	CREATE_MAP(17, 20, G_c_map_30, 24,0xFF,0xFF,31, 0, 0x0000, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(21, 20, G_c_map_31, 0xFF,0xFF,30,0xFF, 0, 0x0000, 0x0000, 0x0000, &external_portal_map_31),
	CREATE_MAP(29, 20, G_c_map_32, 26,0xFF,0xFF,33, 3, &enemies_map_32, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(25, 20, G_c_map_33, 27,0xFF,32,34, 4, &enemies_map_33, 0x0000, &door_map_33, 0x0000),
	CREATE_MAP(15, 20, G_c_map_34, 0xFF,0xFF,33,35, 1, &enemies_map_34, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(32, 20, G_c_map_35, 28,0xFF,34,36, 4, &enemies_map_35, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(22, 20, G_c_map_36, 0xFF,0xFF,35,0xFF, 3, &enemies_map_36, 0x0000, 0x0000, 0x0000),
	
	CREATE_MAP(15, 20, G_c_map_37, 0xFF,0xFF,0xFF,0xFF, 0, 0x0000, 0x0000, 0x0000, &external_portal_map_37),
	
	CREATE_MAP(15, 20, G_c_map_38, 0xFF,0xFF,0xFF,0xFF, 1, &enemies_map_38, 0x0000, 0x0000, &external_portal_map_38),
	
	CREATE_MAP(15, 20, G_c_map_39, 0xFF,0xFF,0xFF,40, 0, 0x0000, &portal_map_39, 0x0000, &external_portal_map_39),
	CREATE_MAP(15, 20, G_c_map_40, 0xFF,43,39,41, 4, &enemies_map_40, 0x0000, &door_map_40, &external_portal_map_38),
	CREATE_MAP(15, 20, G_c_map_41, 0xFF,0xFF,40,0xFF, 3, &enemies_map_41, 0x0000, 0x0000, &external_portal_map_38),
	CREATE_MAP(15, 20, G_c_map_42, 0xFF,45,0xFF,43, 3, &enemies_map_42, 0x0000, &door_map_42, &external_portal_map_38),
	CREATE_MAP(15, 20, G_c_map_43, 40,0xFF,42,44, 4, &enemies_map_43, 0x0000, 0x0000, &external_portal_map_38),
	CREATE_MAP(15, 20, G_c_map_44, 0xFF,0xFF,43,0xFF, 1, &enemies_map_44, 0x0000, 0x0000, &external_portal_map_38),
	CREATE_MAP(15, 20, G_c_map_45, 42,0xFF,0xFF,46, 4, &enemies_map_45, 0x0000, 0x0000, &external_portal_map_38),
	CREATE_MAP(15, 20, G_c_map_46, 0xFF,0xFF,45,47, 2, &enemies_map_46, 0x0000, 0x0000, &external_portal_map_38),
	CREATE_MAP(15, 20, G_c_map_47, 0xFF,0xFF,46,0xFF, 3, &enemies_map_47, 0x0000, &door_map_47, &external_portal_map_47),
	
	CREATE_MAP(17, 20, G_c_map_48, 0xFF,0xFF,0xFF,49, 5, &enemies_map_48, 0x0000, &door_map_48, 0x0000),
	CREATE_MAP(19, 20, G_c_map_49, 0xFF,0xFF,48,50, 4, &enemies_map_49, &portal_map_49, 0x0000, 0x0000),
	CREATE_MAP(26, 20, G_c_map_50, 0xFF,0xFF,49,0xFF, 5, &enemies_map_50, 0x0000, 0x0000, &external_portal_map_50),
	CREATE_MAP(27, 20, G_c_map_51, 0xFF,0xFF,0xFF,52, 4, &enemies_map_51, &portal_map_51, &door_map_51, 0x0000),
	CREATE_MAP(18, 20, G_c_map_52, 0xFF,0xFF,51,53, 4, enemies_map_52, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(17, 20, G_c_map_53, 0xFF,0xFF,52,0xFF, 2, &enemies_map_53, &portal_map_53, 0x0000, &external_portal_map_53),
	CREATE_MAP(17, 22, G_c_map_54, 0xFF,0xFF,0xFF,55, 5, &enemies_map_54, &portal_map_54, &door_map_54, 0x0000),
	CREATE_MAP(21, 22, G_c_map_55, 0xFF,0xFF,54,56, 4, &enemies_map_55, &portal_map_55, &door_map_55, 0x0000),
	CREATE_MAP(24, 22, G_c_map_56, 0xFF,0xFF,55,0xFF, 6, &enemies_map_56, 0x0000, &door_map_56, &external_portal_map_56),

	CREATE_MAP(20, 20, G_c_map_57, 0xFF,0xFF,0xFF,58, 4, &enemies_map_57, 0x0000, &door_map_57, 0x0000),
	CREATE_MAP(22, 20, G_c_map_58, 0xFF,0xFF,57,59, 4, &enemies_map_58, &portal_map_58, 0x0000, 0x0000),
	CREATE_MAP(20, 20, G_c_map_59, 0xFF,62,58,0xFF, 4, &enemies_map_59, 0x0000, &door_map_59, 0x0000),
	CREATE_MAP(20, 20, G_c_map_60, 0xFF,63,0xFF,61, 3, &enemies_map_60, &portal_map_60, &door_map_60, 0x0000),
	CREATE_MAP(22, 20, G_c_map_61, 0xFF,0xFF,60,62, 3, &enemies_map_61, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(20, 20, G_c_map_62, 59,0xFF,61,0xFF, 2, &enemies_map_62, 0x0000, &door_map_62, 0x0000),
	CREATE_MAP(20, 20, G_c_map_63, 60,0xFF,0xFF,64, 6, &enemies_map_63, &portal_map_63, 0x0000, 0x0000),
	CREATE_MAP(22, 20, G_c_map_64, 0xFF,0xFF,63,65, 4, &enemies_map_64, 0x0000, 0x0000, 0x0000),
	CREATE_MAP(20, 20, G_c_map_65, 0xFF,0xFF,64,0xFF, 6, &enemies_map_65, 0x0000, &door_map_65, &external_portal_map_65),
	
	CREATE_MAP(15, 20, G_c_map_66, 0xFF,0xFF,0xFF,0xFF, 1, &enemies_map_66, 0x0000, 0x0000, &external_portal_map_66),
	
	CREATE_MAP(15, 20, G_c_map_67, 0xFF,0xFF,0xFF,0xFF, 1, &enemies_map_67, 0x0000, 0x0000, 0x0000)

};

const u8 change_map = false;
const u8* const actual_map = G_c_map_18;

void load_map(u8* p)
{
	u8** p_a_map = &actual_map;
	(*p_a_map) = p;
}

void load_adjacent_maps(u8* p)
{
	u8* p_next_maps = next_maps;
	(*p_next_maps++) = (*p++);
	(*p_next_maps++) = (*p++);
	(*p_next_maps++) = (*p++);
	(*p_next_maps) = (*p);
}

void win_game()
{
	u8 *p_win = &win;
	(*p_win) = true;
}

void load_enemies(u8 index)
{
	u8 size = all_maps_compressed[index].number_enemies;
	u8 *p_enemy_data = all_maps_compressed[index].enemies_array; 
	u8 *p_enemy;
	TKey *p_key = &key;
	u8 type = 0;
	
	
	for(u8 i = 0 ; i < size ; ++i)
	{
		p_enemy = (u8*)&enemies[i];

		if(((struct TEnemyData *)p_enemy_data)->on_dead == enemy_drop_white_key ||
			((struct TEnemyData *)p_enemy_data)->on_dead == enemy_drop_red_key ||
			((struct TEnemyData *)p_enemy_data)->on_dead == enemy_drop_green_key ||
			((struct TEnemyData *)p_enemy_data)->on_dead == enemy_drop_blue_key)
			{
				p_key->enemy_to_change = p_enemy_data;	
			} 

		(*p_enemy++) = (*p_enemy_data++)*4;			// x
		(*p_enemy++) = (*p_enemy_data++)*8 + SCREEN_OFFSET;	// y
		(*p_enemy++) = 0; 							// ldf
		(*p_enemy++) = 0; 							// pldf
		(*p_enemy++) = 0; 							// anim_state
		(*p_enemy++) = (*p_enemy_data++); 			// lives
		(*p_enemy++) = enemy_walking; 				// state
		(*p_enemy++) = 0xFF; 						// direction_f
		(*p_enemy++) = (*p_enemy_data++); 			// types
		type = (*(p_enemy_data-1));
		
		if(type == princess)
		{
			win_game();
		}
		
		(*p_enemy++) = 0; 							// ctpa
		(*p_enemy++) = (*p_enemy_data++); 			// on_dead
		(*p_enemy++) = (*p_enemy_data++); 			// on_dead
		(*p_enemy++) = ((u16)sprite_by_type[type]) & 0xFF;
		(*p_enemy) = ((u16)sprite_by_type[type]) >> 8 & 0xFF;
	}
}

void load_portal(u8 index)
{
	u8* p_portal = (u8*)&portals;
	u8* p_portal_map = all_maps_compressed[index].portal_direction;

	if(p_portal_map == 0x0000) return;
	
	(*p_portal++) = (*p_portal_map++); 
	(*p_portal++) = (*p_portal_map++); 
	(*p_portal++) = (*p_portal_map++); 
	(*p_portal) = (*p_portal_map); 
}

void load_external_portal(u8 index)
{
	u8* p_external_portal = (u8*)&external_portal;
	u8* p_external_portal_map = all_maps_compressed[index].external_portal;

	if(p_external_portal_map == 0x0000) return;
	
	(*p_external_portal++) = (*p_external_portal_map++);
	(*p_external_portal++) = (*p_external_portal_map++);
	(*p_external_portal) = (*p_external_portal_map);
}

void load_doors(u8 index)
{
	u8* p_door_data = all_maps_compressed[index].door;
	u8* p_door;

	if(p_door_data != 0x0000)
	{
		p_door = (u8*)&door;
		(*p_door++) = (*p_door_data++)*4; 		// x
		(*p_door++) = (*p_door_data++)*8 + SCREEN_OFFSET; 	// y
		(*p_door++) = (*p_door_data++);			// type
		(*p_door) = (*p_door_data); 			// id
	}
	else
	{
		p_door = (u8*)&door.id;
		(*p_door) = 0xFF;
	}
	
}

void load_hero(u8 direction)
{
	u8* p_map = &hero.x;
	switch(direction)
	{
		case 0:
			(*(p_map+1)) = (max_h+SCREEN_OFFSET) - ENTITY_HEIGHT;
			break;
		case 1:
			(*(p_map+1)) = 0 + SCREEN_OFFSET;
			break;
		case 2:
			(*p_map) = max_w - ENTITY_WIDTH;
			break;
		case 3:
			(*p_map) = 0;
			break;
	}
}

void load_dimensions(u8 width, u8 height)
{
	u8 *p_dimension = &width_map;
	(*p_dimension++) = width;
	max_w = width*4;
	(*p_dimension) = height;
	max_h = height*8;
}

void change_flag()
{
	u8* p_map = &change_map;

	// Activate flag to change map in the next iteration
	(*p_map) = true;
}

void change_checkpoint(u8 id)
{
	u8 *p_checkpoint;

	for(u8 i = 0 ; i < CHECKPOINTS ; ++i)
	{
		if(checkpoints[i].id == id)
		{
			p_checkpoint = (u8*)&actual_checkpoint;

			(*p_checkpoint++) = checkpoints[i].id;
			(*p_checkpoint++) = checkpoints[i].x;
			(*p_checkpoint) = checkpoints[i].y;
		}
	}
}

void change_map_aux(u8 map_index)
{
	change_flag();


	//Delete all enemies
	enemies_reset_all();

	//Delete all objects
	object_reset_all();

	// Load index of left, right, up, down maps
	load_adjacent_maps((u8*) &all_maps_compressed[map_index].adjacent_maps);

	load_dimensions(all_maps_compressed[map_index].map_width, all_maps_compressed[map_index].map_height);
	load_enemies(map_index);
	load_portal(map_index);
	load_external_portal(map_index);
	load_doors(map_index);

	cpct_etm_setDrawTilemap4x8_ag(VIEWPORT_WIDTH_T, VIEWPORT_HEIGHT_T, all_maps_compressed[map_index].map_width, tileset_tiles_00);


	load_map(all_maps_compressed[map_index].map_compressed_data);
	
}

void map_init_game()
{
   	change_map_aux(37);
}

void map_change_map_by_portal(u8 index_map)
{
	change_map_aux(index_map);
}

inline void map_can_change(u8 direction)
{
	u8 id = next_maps[direction];
	if(id != 0xFF)
	{
		change_map_aux(id);
		change_checkpoint(id);
		load_hero(direction);
		camera_run();
	}
}

inline void map_load_new_map()
{
	u8* p_map = &change_map;
	(*p_map) = false;

	__asm
		ld	hl, (#_actual_map)
		ld	de, #_map
		call	_decompress_exomizer
	__endasm;

	//load rest of the data
}

inline u16 get_tile_horizontal_0(const u8 x, const u8 y){
    return ((y-SCREEN_OFFSET) / TILE_HP) << 8 | (x*NUMBER_OF_PIXELS_PER_BYTE) / TILE_WP;
}

inline u16 get_tile_horizontal_1(const u8 x, const u8 y){
    return ((y+(ENTITY_HEIGHT/2)-SCREEN_OFFSET) / TILE_HP) << 8 | (x*NUMBER_OF_PIXELS_PER_BYTE) / TILE_WP;
}

inline u16 get_tile_horizontal_2(const u8 x, const u8 y){
    return ((y+(ENTITY_HEIGHT)-SCREEN_OFFSET) / TILE_HP) << 8 | (x*NUMBER_OF_PIXELS_PER_BYTE) / TILE_WP;
}

inline u16 get_tile_vertical_0(const u8 x, const u8 y){
    return ((y-SCREEN_OFFSET) / TILE_HP) << 8 | (x*NUMBER_OF_PIXELS_PER_BYTE) / TILE_WP;
}

inline u16 get_tile_vertical_1(const u8 x, const u8 y){
    return ((y-SCREEN_OFFSET) / TILE_HP) << 8 | ((x+ENTITY_WIDTH-1)*NUMBER_OF_PIXELS_PER_BYTE) / TILE_WP;
}
