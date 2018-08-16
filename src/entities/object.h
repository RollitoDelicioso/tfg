#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <cpctelera.h>
#include "constants.h"

typedef struct {
	u8 x;
	u8 y;
	u8* sprite;
	u8 picked;
	void(*object_action)();
} TObject;

typedef struct {
	u8 x;
	u8 y;
	u8 type;
	u8 picked;
	void(*object_action)();
	u8* enemy_to_change;
} TKey;

void object_decrease_key(u8*);
void object_reset_all();
void object_create_key(u8*, u8);
void object_create_heal(u8*, u8);
void add_heal();
void add_key();

void draw_objects();
extern const TObject hearths[MAX_HEARTHS];
extern const TKey key;
#endif