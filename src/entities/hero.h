#ifndef _HERO_H_
#define _HERO_H_

#include <cpctelera.h>
#include "constants.h"

typedef struct {
	u8 x;
	u8 y;
	u8 ldf; // L.D.F Last Direcction Faced 0: up, 1: down, 2: left, 3: right
	u8 pldf;
	u8* sprite;
	u8 lives;
	u8 state;
} THero;

//
// Possible statuses of the hero
//
typedef enum {
   hero_idle = 0, 		// Entity that does not move
   hero_walking,		// Entity walking
   hero_attacking,		// Entity attacking
   hero_small_hit,  	// Entity has recived a small hit
   hero_big_hit			// Entity has recived a big hit
} THeroStatus;

void hero_update();
inline void hero_erase();
inline void hero_draw();
void update_hero();
void hero_decrease_heal(u8);
void hero_add_key();
void hero_increase_heal(); 
bool hero_check_collision_door();
void hero_init();
extern const THero hero;
extern u8 aux_f;

#endif