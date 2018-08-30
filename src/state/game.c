#include "game.h"
#include "entities/enemy.h"
#include "entities/hero.h"
#include "entities/object.h"
#include "entities/bullet.h"
#include "entities/door.h"
#include "map/map.h"
#include "video/video.h"
#include "video/camera.h"
#include "video/ui.h"

u8 update_index = 0;
u8 times_killed = 0;

void initialize_all()
{
	video_initBuffers();
	
   	ui_init(CPCT_VMEM_START);
   	ui_init(HW_BACKBUFFER);

   	ui_init_heal();
	ui_init_keys();
   	hero_init();
   	camera_set_entity(&hero.x, &hero.y);
	enemy_draw();
	map_init_game();
}

void update()
{
	hero_update();
	enemy_update();
	bullet_update();
	camera_run();
}

void draw()
{
   	// Cambiar y parámetro por ancho de pantalla actual
	cpct_etm_drawTilemap4x8_ag(video_buffer+SCREEN_HEIGHT_OFFSET, (u8*)map + offset_y*width_map + offset_x );

	draw_objects();
	enemy_draw();
	bullet_draw();
	hero_draw();
	door_draw();
}	

void wait()
{
	for(u8 i=0;i<100;++i)
	{
		__asm__("halt");
	}
}

void reload_heal()
{
	wait();
	hero_increase_heal();
	wait();
	hero_increase_heal();
	wait();
	hero_increase_heal();
	wait();
	hero_increase_heal();
}

inline void go_next_map()
{
	map_load_new_map();
}

void load_hero_checkpoint()
{
	u8* p_hero = &hero.x;
	(*p_hero++) = actual_checkpoint.x * (TILE_WP / NUMBER_OF_PIXELS_PER_BYTE);
	(*p_hero) = actual_checkpoint.y * TILE_HP + SCREEN_OFFSET;
}


void restart_from_checkpoint()
{
	times_killed++;
	change_map_aux(actual_checkpoint.id);
	load_hero_checkpoint();
	reload_heal();
}
	
void you_win()
{
	u8 *p_win = &win;
	u8 *p_video;
	(*p_win) = false;
	

	if(video_getBackBufferPtr() == CPCT_VMEM_START)
	{
		p_video = HW_BACKBUFFER;
	}
	else
	{
		p_video = CPCT_VMEM_START;
	}


	cpct_drawStringM0("You win", (void*)(p_video + 0x23C7 - (0xA0+0xA0) - 0xA0 - 0x50 + 0x07), MENU_FOREGROUND_COLOR, MENU_BACKGROUND_COLOR);
	cpct_drawStringM0("Times died:", (void*)(p_video + 0x23C7 - (0xA0+0xA0+0xA0) + 0x02), MENU_FOREGROUND_COLOR, MENU_BACKGROUND_COLOR);
	
	cpct_drawCharM0(p_video + 0x23C7 - (0xA0+0xA0) + 0x02 + 5*3,2,KEY_BACKGROUND_COLOR,48+times_killed/100);
	cpct_drawCharM0(p_video + 0x23C7 - (0xA0+0xA0) + 0x06 + 5*3,2,KEY_BACKGROUND_COLOR,48+times_killed%100/10);
	cpct_drawCharM0(p_video + 0x23C7 - (0xA0+0xA0) + 0x0A + 5*3,2,KEY_BACKGROUND_COLOR,48+times_killed%10);
	


	cpct_drawStringM0("Press any", (void*)(p_video + 0x23C7+0xA0+0xA0+0xA0+0xA0+ 0x04), MENU_FOREGROUND_COLOR, MENU_BACKGROUND_COLOR);
	cpct_drawStringM0("button", (void*)(p_video + 0x23C7+0xA0+0xA0+0xA0+0xA0+0xA0 + 0x0A), MENU_FOREGROUND_COLOR, MENU_BACKGROUND_COLOR);
	
	while(cpct_isAnyKeyPressed());
	while(!cpct_isAnyKeyPressed());
}

void run_game(){
	bool keep = true;
	initialize_all();


	while(!win)
	{
		while(hero.lives && keep)
		{
			if(win)
			{
				keep = false;
			}

			draw();
			update();

			if(++update_index == MAX_ENEMIES)
			{
				update_index = 0;
			}

			if(change_map)
			{
				go_next_map();
			}

			video_switchBuffers();
		}

		if(!win)
		{
			restart_from_checkpoint();
		}	
	}

	you_win();
}