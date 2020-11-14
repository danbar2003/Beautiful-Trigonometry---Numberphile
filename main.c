#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "logic_structures.h"

int main(int argc, char** argv)
{
	bool running = true;

	//create base circle
	BasePoint base_point;
	base_point.radius = CIRCLE_RADIUS;
	base_point.point.x = CIRCLE_RADIUS;
	base_point.point.y = 0;

	while (running)
	{
		//event if user wants to 

		//generate frame
		pPoint point_lst;
		point_lst = generate_frames(&base_point, NUM_OF_LINES);
		
		
	}
}