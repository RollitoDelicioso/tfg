#include "door.h"
#include "sprites.h"
#include "video/video.h"

#define INIT_DOOR {.x = 0,.y = 0,.type = 0,.id = 0xFF} 

const TDoor door = INIT_DOOR;
const u8** const door_sprites[4] = {sprite_white_door,sprite_red_door,sprite_green_door,sprite_blue_door};
const u8 doors_closed[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

void door_open_door()
{
	u8* p_close_door = &doors_closed[door.id];
	(*p_close_door)--;
}

void door_draw()
{
	if(door.id != 0xFF && doors_closed[door.id] && video_isInsideViewport(door.x, door.y, ENTITY_WIDTH, ENTITY_HEIGHT))
	{
		cpct_drawSpriteMasked(door_sprites[door.type], cpct_getScreenPtr(video_buffer, RELATIVE_POSITION_X(door.x), RELATIVE_POSITION_Y(door.y)), ENTITY_WIDTH, ENTITY_HEIGHT);
	}
}