#include "portal.h"
#include "entities/hero.h"

const TLocalPortal portals = {.portal_1_x=0,.portal_1_y=0,.portal_2_x=0,.portal_2_y=0};
const TExternalPortal external_portal = {.to_x=0,.to_y=0,.id_map=0};

u16 portal_get_destination(u8 x, u8 y)
{
	if(portals.portal_1_x == x && portals.portal_1_y == y)
	{
		return (40 + (portals.portal_2_y * TILE_HP)) << 8 | portals.portal_2_x * TILE_WP / NUMBER_OF_PIXELS_PER_BYTE;
	}
	else
	{
		return (40 + (portals.portal_1_y * TILE_HP)) << 8 | portals.portal_1_x * TILE_WP / NUMBER_OF_PIXELS_PER_BYTE;
	}
}

u16 portal_get_external_destination()
{
	return (40 + (external_portal.to_y * TILE_HP)) << 8 | external_portal.to_x * TILE_WP / NUMBER_OF_PIXELS_PER_BYTE;
}

u8 portal_get_external_map()
{
	return external_portal.id_map;
}

void portal_perform_local_teletransportation(u8 x, u8 y){
	u8* p_hero = &hero.x;
	u16 destination = portal_get_destination(x,y);
	
	(*p_hero) = destination & 0xFF;
	(*(p_hero+1)) = destination >> 8 & 0xFF; 
}

void portal_perform_external_teletransportation(u8 x, u8 y){
	u8* p_hero = &hero.x;
	(*p_hero) = x;
	(*(p_hero+1)) = y; 
}

