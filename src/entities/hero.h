#ifndef _HERO_H_
#define _HERO_H_

#include <cpctelera.h>

typedef struct {
	u8 x;
	u8 y;
	u8 px;
	u8 py;
	u8 ldf; // L.D.F Last Direcction Faced 0: up, 1: down, 2: left, 3: right
	u8* sprite;
	u8 lives;
} THero;

inline void attack();

extern void update_hero();
extern void hero_erase_and_draw();

extern const THero hero;

#endif