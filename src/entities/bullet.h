#ifndef _BULLET_H_
#define _BULLET_H_

#include <cpctelera.h>
#include "constants.h"

typedef struct {
	u8 x;			// 0xFF means that the bullet is not going to be processed
	u8 y;
	u8 direction;
	u8 hit_by_hero;
} TBullet;

extern const TBullet bullets[MAX_BULLETS];

void bullet_hit_by_hero(u8);
void bullet_fill(u8,u8,u8);
void bullet_update();
void bullet_draw();
#endif