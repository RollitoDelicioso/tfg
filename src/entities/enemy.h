#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <cpctelera.h>
#include "constants.h"

typedef struct {
	u8 x;
	u8 y;

	u8 ldf;
	u8 pldf;
	u8 anim_state;
	
	i8 lives;
	u8 state;
	u8 direction_f;
	u8 type;
	u8 ctpa; // count_to_perform_action
	void (*on_dead)(u8*);
	u8* sprite;
} TEnemy;

//
// Possible statuses of the enemy
//
typedef enum {
   enemy_walking= 0,		// 0
   enemy_hit  				// 1
} TEnemyStatus;

typedef enum { duck_no_additional_states } DuckStatus;

typedef enum { girador_no_additional_states } GiradorStatus;

typedef enum {
   gusano_waiting_above = 2, 	// 2
   gusano_hiding,				// 3
   gusano_going_to_hero,  		// 4
   gusano_emerging  			// 5
} GusanoStatus;

typedef enum {
   disparador_walking = 6, 			// 6
   disparador_shotting,				// 7
} DisparadorStatus;

/*typedef enum {
   enemy_idle = 3, 		// Entity that does not move
   enemy_walking,		// Entity walking
   enemy_hit  			// Entity is moving a floor
} DisparadorStatus;*/


extern const TEnemy enemies[];
extern const u8* const ref_enemies[];

void enemies_reset_all();
inline void save_previous_position(u8* enemy);
inline void check_and_perform();
inline bool check_collision_hero();
bool enemy_collision_left(u8*);
bool enemy_collision_right(u8*);
void chase_hero(u8*);
void enemy_update();
void enemy_draw();

void enemy_on_hit(u8 index);
bool enemy_decrease_heal(u8 index);
bool can_hit_hero();

void enemy_drop_half_heal(u8*);
void enemy_drop_white_key(u8*);
void enemy_drop_red_key(u8*);
void enemy_drop_green_key(u8*);
void enemy_drop_blue_key(u8*);
void enemy_generic_drop(u8*);

#endif