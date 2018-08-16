#ifndef _UI_H_
#define _UI_H_

#include <cpctelera.h>
#include "constants.h"

void ui_update_heal(u8);
void ui_init(u8*);
void ui_init_heal();
void ui_init_keys();
void ui_update_keys(u8,u8);
#endif