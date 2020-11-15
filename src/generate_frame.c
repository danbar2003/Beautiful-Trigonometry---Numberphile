#define _USE_MATH_DEFINES

#include "logic_structures.h"
#include <malloc.h>
#include <math.h>

#include <stdio.h>
static double SLOPES[NUM_OF_LINES];

void calculate_slopes()
{
	double d = ((double)360 / (NUM_OF_LINES * 2));
	for (size_t line = 0; line < NUM_OF_LINES; line++)
	{
		SLOPES[line] = tan(line * d * M_PI / 180);
	}
}

pPoint generate_frames(const pPoint const base_point, pPoint point_lst)
{
	for (size_t line = 0; line < NUM_OF_LINES; line++)
	{
		if (SLOPES[line] == NAN)
		{
			point_lst[line] = *base_point;
			return;
		}

		point_lst[line].x = (base_point->x + SLOPES[line] * base_point->y)
			/ (pow(SLOPES[line], 2) + 1);
		point_lst[line].y = point_lst[line].x * SLOPES[line];
	}
}

void move_base_pointer(const pPoint const base_point)
{
	static unsigned long degree = 0;
	degree += FRAME_DEGREE;
	base_point->x = CIRCLE_RADIUS * cos(degree * M_PI / 180);
	base_point->y = CIRCLE_RADIUS * sin(degree * M_PI / 180);
	degree = degree == 360 ? 0 : degree;
	printf("%.8g %.8g\n", base_point->x, base_point->y);
	printf("%lu\n", degree);
}