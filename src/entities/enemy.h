#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <cpctelera.h>

typedef struct {
	u8 x;
	u8 y;
	u8 px;
	u8 py;
	u8 ldf;	
	void (*perform_action)(u8*);
	u8 ctpa; // count_to_perform_action
	u8 stpa; // steps_to_perform_action
	u8 lives;
	u8* sprite;
} TEnemy;

extern const TEnemy enemies[];
extern const u8* const ref_enemies[];

void chase_hero(u8*);

#endif