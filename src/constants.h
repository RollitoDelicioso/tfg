#define bool u8
#define false 0
#define true 1

#define duck		0
#define girador		1
#define gusano		2
#define disparador	3
#define princess 4

#define up		0
#define down	1
#define left	2
#define right	3

#define white		0
#define red		1
#define green		2
#define blue		3

#define HERO_SPEED_X 1
#define HERO_SPEED_Y 2

#define BULLET_SPEED_Y 6
#define BULLET_SPEED_X 2

#define MAX_ENEMIES 6
#define MAX_HEARTHS 3
#define MAX_OBJECTS 4
#define MAX_DOORS 2
#define MAX_BULLETS 6

#define DISPLACEMENT_ENEMY 5

#define CHECKPOINTS 7

// Pointer to the second hardware screen
#define HW_BACKBUFFER (u8*)(0x8000)

#define SCREEN_HEIGHT_OFFSET 0x0190

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 200

#define SCREEN_WIDTH_T 32
#define SCREEN_HEIGHT_T 27

#define VIEWPORT_WIDTH 60
#define VIEWPORT_HEIGHT 160

#define SCREEN_OFFSET (SCREEN_HEIGHT-VIEWPORT_HEIGHT)


#define VIEWPORT_WIDTH_T 15
#define VIEWPORT_HEIGHT_T 20

#define NUMBER_OF_PIXELS_PER_BYTE 2
#define TILE_WP            8         	// Width of a tile in pixels
#define TILE_HP            8          	// Height of a tile in pixels

#define ENTITY_WIDTH 4
#define ENTITY_HEIGHT 16

#define OBJECT_HEARTH_WIDTH 4
#define OBJECT_HEARTH_HEIGHT 8

#define OBJECT_KEY_WIDTH 2
#define OBJECT_KEY_HEIGHT 8

#define SWORD_WIDTH 3
#define SWORD_HEIGHT 8

#define BULLET_WIDTH 1
#define BULLET_HEIGHT 4

#define RELATIVE_POSITION_X(X) (X-viewport_x)
#define RELATIVE_POSITION_Y(Y) (Y-viewport_y) 

#define GET_UPPER_TILE(var) (var >> 8) & 0xFF
#define GET_LOW_TILE(var) (var & 0xFF)

#define CHECK_MOVE_HORIZONTAL(X,Y,WHO) entity_can_move(get_tile_horizontal_0(X,Y),WHO) && entity_can_move(get_tile_horizontal_1(X,Y),WHO) && entity_can_move(get_tile_horizontal_2(X,Y),WHO)
#define CHECK_MOVE_VERTICAL(X,Y,WHO) entity_can_move(get_tile_vertical_0(X,Y),WHO) && entity_can_move(get_tile_vertical_1(X,Y),WHO)

#define SCORE_FOREGROUND_COLOR 4
#define KEY_BACKGROUND_COLOR 3

// COLORS
#define MENU_FOREGROUND_COLOR 13
#define MENU_BACKGROUND_COLOR 3