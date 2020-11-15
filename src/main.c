#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

#include "logic_structures.h"

int main(int argc, char** argv)
{
	bool running = true;

	//create base circle
	struct Point base_point;
	base_point.x = CIRCLE_RADIUS;
	base_point.y = 0;

	//calculate lines slopes
	calculate_slopes();

	//allocate point list
	pPoint point_lst = (pPoint)malloc(sizeof(struct Point) * NUM_OF_LINES);

	while (running)
	{
		//event if user wants to 
		
		//generate frame
		generate_frames(&base_point, point_lst);

		//move the base point for the next frame
		move_base_pointer(&base_point);
	}
	
	//free allocated memory
	free(point_lst);
}