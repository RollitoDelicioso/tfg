#ifndef _DATA_TYPES_H_
#define _DATA_TYPES_H_

#include <cpctelera.h>
#include "constants.h"


// Directions in tiles
struct TEnemyData{
	u8 x;
	u8 y;
	i8 lives;
	u8 type;
	void (*on_dead)(u8*);
};


// Directions in tiles
struct TLocalPortalData{
	u8 portal_1_x;
	u8 portal_1_y;
	u8 portal_2_x;
	u8 portal_2_y;
};

// Directions in tiles
struct TExternalPortalData{
	u8 x;
	u8 y;
	u8 id_map;
};

// Directions in tiles
struct TDoorData{
	u8 x;
	u8 y;
	u8 type;
	u8 id;
};


#endif
