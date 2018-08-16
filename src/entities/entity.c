#include "entity.h"
#include "map/map.h"
#include "entities/hero.h"
#include "entities/portal.h"
#include "entities/enemy.h"
#include "video/camera.h"
#include "video/video.h"


void portal_touched(u16 index)
{
	u8 ix = index & 0xFF, iy = index >> 8 & 0xFF;
	u16 destination = portal_get_destination(ix, iy);

	camera_scroll_to((destination & 0xFF), (destination >> 8 & 0xFF), portal_perform_local_teletransportation, ix, iy);
}

void external_portal_touched()
{
	u16 destination = portal_get_external_destination();

	portal_perform_external_teletransportation((destination & 0xFF), (destination >> 8 & 0xFF));

	map_change_map_by_portal(portal_get_external_map());
}

// who: 1 -> hero, 0 -> enemy
bool entity_can_move(u16 index, u8 who){ 
	
	//true: not obstacle, false: obstacle
	
	switch( * ( (u8*)map + (index >> 8 & 0xFF)*width_map + (index & 0xFF) ) )
	{
			case 5:
				if(who)	portal_touched(index);
				return false;
			case 8:
				if(who)	external_portal_touched();
				return false;
			case 0:case 1:case 2:case 3:case 4:case 6:case 7:case 9:case 10:
				return true;
			default:
				return false;
	}
}

bool entity_x_collision(u8 f_x, u8 f_w, u8 s_x, u8 s_w)
{
	return f_x+f_w > s_x && s_x+s_w > f_x;
}

bool entity_y_collision(u8 f_y, u8 f_h, u8 s_y, u8 s_h)
{
	return f_y+f_h > s_y && s_y+s_h > f_y;
}

void entity_perform_movement(u8* entity, u8 direction, u8 who){ //who: 0 -> enemy, 1 -> hero
	u8 x_entity = (*entity), y_entity = (*(entity+1));
	u8 speed_x = who ? HERO_SPEED_X*2 : HERO_SPEED_X, speed_y = who ? HERO_SPEED_Y+1 : HERO_SPEED_Y;
	
	switch(direction){
		case up:
		
			if(y_entity-speed_y > SCREEN_HEIGHT-(VIEWPORT_HEIGHT-2))
			{
				// Colision Tiles
				if(CHECK_MOVE_VERTICAL(x_entity, y_entity-HERO_SPEED_Y,who))
				{
					(*(entity+1)) -= speed_y;
					if(who == 0)
					{	
						// Colision Entities
						if(enemy_collision_left(entity) || enemy_collision_right(entity))
						{
							(*(entity+1)) += speed_y;
						}
					}
					else
					{
						hero_check_collision_door();
					}
					
				}
			}
			break;
		case down:

			if(y_entity+speed_y < (max_h+40)-(ENTITY_HEIGHT+1))
			{
				// Colision Tiles
				if(CHECK_MOVE_VERTICAL(x_entity, y_entity+ENTITY_HEIGHT+HERO_SPEED_Y,who))
				{
					(*(entity+1)) += speed_y;
					if(who == 0)
					{
						// Colision Entities
						if(enemy_collision_left(entity) || enemy_collision_right(entity))
						{
							(*(entity+1)) -= speed_y;
						}
					}
					else
					{
						hero_check_collision_door();
					}
					
				}
			}
			break;
		case left:
			
			if(x_entity-speed_x > 0)
			{
		
				// Colision Tiles
				if(CHECK_MOVE_HORIZONTAL(x_entity-HERO_SPEED_X,y_entity,who))
				{
					(*entity) -= speed_x;
					if(who == 0)
					{
						// Colision Entities
						if(enemy_collision_left(entity) || enemy_collision_right(entity))
						{
							(*entity) += speed_x;
						}
					}
					else
					{
						hero_check_collision_door();
					}
					
				}
			}
			break;
		case right:

			if(x_entity+speed_x < max_w-ENTITY_WIDTH)
			{
		
				// Colision Tiles
				if(CHECK_MOVE_HORIZONTAL(x_entity+ENTITY_WIDTH,y_entity,who))
				{
					(*entity) += speed_x;
					if(who == 0)
					{
						// Colision Entities
						if(enemy_collision_right(entity) || enemy_collision_left(entity))
						{
							(*entity) -= speed_x;	
						}
					}
					else
					{
						hero_check_collision_door();	
					}

				}
			}
			break;
	}
}
