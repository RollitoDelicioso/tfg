#include <cpctelera.h>
#include "constants.h"

		typedef struct {
			u8 x;
			u8 y;
			u8 type;
			u8 id;
		} TDoor;

extern const TDoor door;
extern const u8 doors_closed[]; 

void door_draw();
void door_open_door();

