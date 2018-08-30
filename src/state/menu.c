#include "menu.h"
#include "sprites.h"




void clean_screen(u8* p_screen)
{
	cpct_drawSolidBox(p_screen, 204, 64, 200);
	p_screen += 0x40;
	cpct_drawSolidBox(p_screen, 204, 16, 200);
}

void clear_screens()
{
	clean_screen(CPCT_VMEM_START);
	clean_screen(HW_BACKBUFFER);
}

void show_menu()
{
	while(cpct_isAnyKeyPressed());

	clear_screens();
	cpct_drawSpriteMasked(sprite_logo, (void*)0xE24E, 20, 20);
	cpct_drawStringM0("Press any button", (void*)0xE3C7, MENU_FOREGROUND_COLOR, MENU_BACKGROUND_COLOR);
	cpct_drawStringM0("to play", (void*)0xDC7A, MENU_FOREGROUND_COLOR, MENU_BACKGROUND_COLOR);
	
	cpct_drawSpriteMasked(sprite_hero_front_1, cpct_getScreenPtr(CPCT_VMEM_START, 10, 20), 4, 16);
	cpct_drawSpriteMasked(sprite_princess, cpct_getScreenPtr(CPCT_VMEM_START, 65, 25), 4, 16);

	cpct_drawSpriteMasked(sprite_duck_front_1, cpct_getScreenPtr(CPCT_VMEM_START, 25, 160), 4, 16);
	cpct_drawSpriteMasked(sprite_girador_1, cpct_getScreenPtr(CPCT_VMEM_START, 35, 160), 4, 16);
	cpct_drawSpriteMasked(sprite_gusano_out, cpct_getScreenPtr(CPCT_VMEM_START, 45, 160), 4, 16);
	cpct_drawSpriteMasked(sprite_disparador_front, cpct_getScreenPtr(CPCT_VMEM_START, 55, 160), 4, 16);

	while(!cpct_isAnyKeyPressed());
}