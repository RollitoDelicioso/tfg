#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <cpctelera.h>
#include "constants.h"

bool entity_can_move(u16,u8);
void entity_perform_movement(u8*, u8, u8);
bool entity_x_collision(u8,u8,u8,u8);
bool entity_y_collision(u8,u8,u8,u8);
#endif