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

void initialize_all()
{
	video_initBuffers();
	
   	ui_init(CPCT_VMEM_START);
   	ui_init(HW_BACKBUFFER);

   	ui_init_heal();
	ui_init_keys();
   	
   	// Cambiar 3º parámetro por ancho de pantalla actual
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

inline void go_next_map()
{
	map_load_new_map();
}

void run_game(){
	initialize_all();

	while(hero.lives){
		draw();
		update();

		if(++update_index == MAX_ENEMIES){
			update_index = 0;
		}

		if(change_map)
		{
			go_next_map();
		}

		video_switchBuffers();
	}
}