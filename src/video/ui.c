#include "ui.h"
#include "sprites.h"

#define POS_WHITE_KEY_1 (void*)(0xF0BE+0x3E3)
#define POS_RED_KEY_1 (void*)(0xF0C1+0x3E3)
#define POS_GREEN_KEY_1 (void*)(0xF0C6+0x3E3)
#define POS_BLUE_KEY_1 (void*)(0xF0CA+0x3E3)

#define POS_WHITE_KEY_2 (void*)(0xB0BE+0x3E3)
#define POS_RED_KEY_2 (void*)(0xB0C1+0x3E3)
#define POS_GREEN_KEY_2 (void*)(0xB0C6+0x3E3)
#define POS_BLUE_KEY_2 (void*)(0xB0CA+0x3E3)

#define POS_WHITE_KEY_VALUE_1 (void*)(0xF0BE+0x3E3+7)
#define POS_RED_KEY_VALUE_1 (void*)(0xF0BE+0x3E3+7+0xA0)
#define POS_GREEN_KEY_VALUE_1 (void*)(0xF0BE+0x3E3+7+0xA0+0xA0)
#define POS_BLUE_KEY_VALUE_1 (void*)(0xF0BE+0x3E3+7+0xA0+0xA0+0xA0)

#define POS_WHITE_KEY_VALUE_2 (void*)(0xB0BE+0x3E3+7)
#define POS_RED_KEY_VALUE_2 (void*)(0xB0BE+0x3E3+7+0xA0)
#define POS_GREEN_KEY_VALUE_2 (void*)(0xB0BE+0x3E3+7+0xA0+0xA0)
#define POS_BLUE_KEY_VALUE_2 (void*)(0xB0BE+0x3E3+7+0xA0+0xA0+0xA0)

#define VIDA_POS_1 (void*)((0xF0BE+0x3E3)-(0xA0+0xA0+0xA0+0x03))
#define VIDA_POS_2 (void*)((0xB0BE+0x3E3)-(0xA0+0xA0+0xA0+0x03))

#define POS_1_HEARTH_1 (void*)((0xF0BE+0x3E3)-(0xA0+0xA0+0xA0+0x03) + 0xA0)
#define POS_2_HEARTH_1 (void*)((0xF0BE+0x3E3)-(0xA0+0xA0+0xA0+0x03) + 0xA0 + 0x04)
#define POS_3_HEARTH_1 (void*)((0xF0BE+0x3E3)-(0xA0+0xA0+0xA0+0x03) + 0xA0 + 0x04 + 0x04)
#define POS_4_HEARTH_1 (void*)((0xF0BE+0x3E3)-(0xA0+0xA0+0xA0+0x03) + 0xA0 + 0x04 + 0x04 + 0x04)
 
#define POS_1_HEARTH_2 (void*)((0xB0BE+0x3E3)-(0xA0+0xA0+0xA0+0x03) + 0xA0)
#define POS_2_HEARTH_2 (void*)((0xB0BE+0x3E3)-(0xA0+0xA0+0xA0+0x03) + 0xA0 + 0x04)
#define POS_3_HEARTH_2 (void*)((0xB0BE+0x3E3)-(0xA0+0xA0+0xA0+0x03) + 0xA0 + 0x04 + 0x04)
#define POS_4_HEARTH_2 (void*)((0xB0BE+0x3E3)-(0xA0+0xA0+0xA0+0x03) + 0xA0 + 0x04 + 0x04 + 0x04)

#define FIRST_RECT (void*)0xC000
#define SECOND_RECT (void*)0xC000

void ui_init(u8* mem_screen)
{
	cpct_drawSolidBox(mem_screen, 204, 60, SCREEN_HEIGHT-VIEWPORT_HEIGHT);
	mem_screen += 0x3C;
	cpct_drawSolidBox(mem_screen, 204, SCREEN_WIDTH-60, SCREEN_HEIGHT);
	mem_screen += 0x37FB;
	cpct_drawSpriteMasked(sprite_logo, mem_screen, 20, 20);
}

void ui_init_keys_aux(u8* mem_screen)
{
	cpct_drawSpriteMasked(sprite_white_key, mem_screen, OBJECT_KEY_WIDTH, OBJECT_KEY_HEIGHT);
	cpct_drawCharM0(mem_screen+3,2,KEY_BACKGROUND_COLOR,120);
   	mem_screen += 0xA0;
   	cpct_drawSpriteMasked(sprite_red_key, mem_screen, OBJECT_KEY_WIDTH, OBJECT_KEY_HEIGHT);
	cpct_drawCharM0(mem_screen+3,4,KEY_BACKGROUND_COLOR,120);
   	mem_screen += 0xA0;
   	cpct_drawSpriteMasked(sprite_green_key, mem_screen, OBJECT_KEY_WIDTH, OBJECT_KEY_HEIGHT);
	cpct_drawCharM0(mem_screen+3,5,KEY_BACKGROUND_COLOR,120);
   	mem_screen += 0xA0;
   	cpct_drawSpriteMasked(sprite_blue_key, mem_screen, OBJECT_KEY_WIDTH, OBJECT_KEY_HEIGHT);
	cpct_drawCharM0(mem_screen+3,6,KEY_BACKGROUND_COLOR,120);

	ui_update_keys(0, 0);
	ui_update_keys(0, 1);
	ui_update_keys(0, 2);
	ui_update_keys(0, 3);
}

void ui_init_keys()
{
	ui_init_keys_aux(POS_WHITE_KEY_1);
	ui_init_keys_aux(POS_WHITE_KEY_2);
}

void ui_init_heal_aux(u8* mem_screen)
{
	cpct_drawStringM0("Vida", mem_screen, 2, KEY_BACKGROUND_COLOR);

	mem_screen += 0xA0;

	cpct_drawSpriteMasked(sprite_full_hearth, mem_screen, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
   	mem_screen += 4;
   	cpct_drawSpriteMasked(sprite_full_hearth, mem_screen, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
   	mem_screen += 4;
   	cpct_drawSpriteMasked(sprite_full_hearth, mem_screen, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
   	mem_screen += 4;
   	cpct_drawSpriteMasked(sprite_full_hearth, mem_screen, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
}


void ui_init_heal()
{
	ui_init_heal_aux(VIDA_POS_1);
	ui_init_heal_aux(VIDA_POS_2);
}

void ui_update_heal(u8 heal)
{
	switch(heal)
	{
		case 0:
			cpct_drawSpriteMasked(sprite_empty_hearth, POS_1_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_empty_hearth, POS_1_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			break;
		case 1:
			cpct_drawSpriteMasked(sprite_half_hearth, POS_1_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_half_hearth, POS_1_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			break;
		case 2:
			cpct_drawSpriteMasked(sprite_full_hearth, POS_1_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_full_hearth, POS_1_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);

			cpct_drawSpriteMasked(sprite_empty_hearth, POS_2_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_empty_hearth, POS_2_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			break;
		case 3:
			cpct_drawSpriteMasked(sprite_half_hearth, POS_2_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_half_hearth, POS_2_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			break;
		case 4:
			cpct_drawSpriteMasked(sprite_full_hearth, POS_2_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_full_hearth, POS_2_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			
			cpct_drawSpriteMasked(sprite_empty_hearth, POS_3_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_empty_hearth, POS_3_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			break;
		case 5:
			cpct_drawSpriteMasked(sprite_half_hearth, POS_3_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_half_hearth, POS_3_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			break;
		case 6:
			cpct_drawSpriteMasked(sprite_full_hearth, POS_3_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_full_hearth, POS_3_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			
			cpct_drawSpriteMasked(sprite_empty_hearth, POS_4_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_empty_hearth, POS_4_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			break;
		case 7:
			cpct_drawSpriteMasked(sprite_half_hearth, POS_4_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_half_hearth, POS_4_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			break;
		case 8:
			cpct_drawSpriteMasked(sprite_full_hearth, POS_4_HEARTH_1, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			cpct_drawSpriteMasked(sprite_full_hearth, POS_4_HEARTH_2, OBJECT_HEARTH_WIDTH, OBJECT_HEARTH_HEIGHT);
			break;
	}
}

void ui_update_keys(u8 key, u8 index_keys)
{
		switch(index_keys)
		{
			case 0: // white
				cpct_drawCharM0(POS_WHITE_KEY_VALUE_1,2,KEY_BACKGROUND_COLOR,48+key);
				cpct_drawCharM0(POS_WHITE_KEY_VALUE_2,2,KEY_BACKGROUND_COLOR,48+key);
				break;
			case 1: // red
				cpct_drawCharM0(POS_RED_KEY_VALUE_1,4,KEY_BACKGROUND_COLOR,48+key);
				cpct_drawCharM0(POS_RED_KEY_VALUE_2,4,KEY_BACKGROUND_COLOR,48+key);
				break;
			case 2: // green
				cpct_drawCharM0(POS_GREEN_KEY_VALUE_1,5,KEY_BACKGROUND_COLOR,48+key);
				cpct_drawCharM0(POS_GREEN_KEY_VALUE_2,5,KEY_BACKGROUND_COLOR,48+key);
				break;
			case 3: // blue
				cpct_drawCharM0(POS_BLUE_KEY_VALUE_1,6,KEY_BACKGROUND_COLOR,48+key);
				cpct_drawCharM0(POS_BLUE_KEY_VALUE_2,6,KEY_BACKGROUND_COLOR,48+key);
				break;

		}
}