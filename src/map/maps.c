/*#include <stdio.h>

#define u8 char
#define NUM_MAPS 28

int main()
{
	char buf[32];
	FILE *write_ptr;
	for(int file = 10; file < NUM_MAPS; file++)
	{
		sprintf(buf, "map_data_%d.h", file);
		write_ptr = fopen(buf,"wb");  // w for write, b for binary
		sprintf(buf, "map_data_%d.c", file);
		write_ptr = fopen(buf,"wb");  // w for write, b for binary
	}
}*/