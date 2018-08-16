#ifndef _MAP_H_
#define _MAP_H_

#include <cpctelera.h>
#include "constants.h"
#include "map/maps_data/c_map_data.h"
#include "map/maps_data/c_maps.h"



typedef struct {
	u8 map_width;
	u8 map_height;
	u8* map_compressed_data;
	u8 adjacent_maps[4]; 
	u8 number_enemies;
	u8* enemies_array;
	u8* portal_direction;
	u8* door;
	u8* external_portal;
} TMap;

extern const u8 change_map;
extern const u8 map[SCREEN_HEIGHT_T][SCREEN_WIDTH_T];
extern const u8 next_maps[4];
extern const TMap all_maps_compressed[];

void map_init_game();
inline void map_load_new_map();
inline void map_can_change(u8 direction);
inline u16 get_tile_horizontal_0(const u8, const u8);
inline u16 get_tile_horizontal_1(const u8, const u8);
inline u16 get_tile_horizontal_2(const u8, const u8);
inline u16 get_tile_vertical_0(const u8, const u8);
inline u16 get_tile_vertical_1(const u8, const u8);
void map_change_map_by_portal(u8);

#endif