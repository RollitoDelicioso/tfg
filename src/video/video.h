#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <cpctelera.h>
#include "constants.h"

extern u8* video_buffer;


extern u8 offset_x;
extern u8 offset_y;
extern u8 viewport_x;
extern u8 viewport_y;

extern const u8 width_map;
extern const u8 height_map;

extern void video_initBuffers();
extern void video_switchBuffers();
extern void video_resetScreenPtr();
bool video_isInsideViewport(u8, u8, u8, u8);

#endif