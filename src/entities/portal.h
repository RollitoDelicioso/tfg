#ifndef _PORTAL_H_
#define _PORTAL_H_

#include <cpctelera.h>
#include "constants.h"


typedef struct TLocalPortal {
	u8 portal_1_x;
	u8 portal_1_y;
	u8 portal_2_x;
	u8 portal_2_y;
} TLocalPortal;

typedef struct TExternalPortal {
	u8 to_x;
	u8 to_y;
	u8 id_map;
} TExternalPortal;

extern const TLocalPortal portals;
extern const TExternalPortal external_portal;
u8 portal_get_external_map();
u16 portal_get_destination(u8 x, u8 y);
u16 portal_get_external_destination();
void portal_perform_local_teletransportation(u8,u8);
void portal_perform_external_teletransportation(u8,u8);

#endif