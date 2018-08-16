#include "camera.h"
#include "video/video.h"
#include "map/map.h"

#include "entities/hero.h"
#include "entities/enemy.h"

u8* entity_x;
u8* entity_y;

u8 max_w;
u8 max_h;

inline void camera_set_entity(u8* px, u8* py){
	entity_x = px;
	entity_y = py;
}

u8 camera_calculate_offset_x(u8 x)
{
	if(x <= 40)
	{
		return 0;
	}
	else if(x >= max_w-40)
	{
		return width_map-VIEWPORT_WIDTH_T;
	}
	else if(RELATIVE_POSITION_X(x) < 15 || RELATIVE_POSITION_X(x) > 45)
	{
		if((width_map-VIEWPORT_WIDTH_T) == 0)
		{
			return offset_x;
		}
		else
		{
			return x / ( (max_w) / (width_map-VIEWPORT_WIDTH_T) );
		}
	}
	return offset_x;
}

u8 camera_calculate_offset_y(u8 y)
{
	if(y <= 90)
	{
		return 0;
	}
	else if(y >= (max_h+SCREEN_OFFSET) - 90)
	{
		return height_map-VIEWPORT_HEIGHT_T;
	}
	else if(RELATIVE_POSITION_Y(y) < 90 || RELATIVE_POSITION_Y(y) > 140)
	{
		return y / ( (max_h+SCREEN_OFFSET) / (height_map-VIEWPORT_HEIGHT_T) );
	}
	return offset_y;
}

void camera_run()
{
	offset_x = camera_calculate_offset_x(*entity_x);
	viewport_x = offset_x*4;

	offset_y = camera_calculate_offset_y(*entity_y);
	viewport_y = offset_y*8;
}

void camera_scroll_to(u8 to_x, u8 to_y, void(*call_back)(u8,u8), u8 f_param, u8 s_param)
{
	u8 aux_x = offset_x, 
	aux_y = offset_y, 
	aux_x_ = camera_calculate_offset_x(to_x), 
	aux_y_ = camera_calculate_offset_y(to_y);

	while( aux_x != aux_x_ || aux_y != aux_y_ )
	{
		if(aux_x < aux_x_)
		{
			aux_x++;
		}
		else if(aux_x > aux_x_)
		{
			aux_x--;
		}
		if(aux_y < aux_y_)
		{
			aux_y++;
		}
		else if(aux_y > aux_y_)
		{
			aux_y--;
		}
		
		offset_x = aux_x;
		offset_y = aux_y;
		viewport_x = aux_x*4;
		viewport_y = aux_y*8;


		cpct_etm_drawTilemap4x8_ag(video_buffer+SCREEN_HEIGHT_OFFSET, (u8*)map + offset_y*width_map + offset_x);
		hero_draw();
		enemy_draw();
		video_switchBuffers();
	}

	if(call_back != 0x00){
		call_back(f_param, s_param);
	}
}
