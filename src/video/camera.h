#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <cpctelera.h>
#include "constants.h"

extern inline void camera_set_entity(u8*, u8*);
extern void camera_run();
extern u8 max_w;
extern u8 max_h;

void camera_scroll_to(u8 to_x, u8 to_y, void(*call_back)(u8,u8), u8 f_param, u8 s_param);

#endif