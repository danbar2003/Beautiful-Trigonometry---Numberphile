#pragma once

#define NUM_OF_LINES 10
#define CIRCLE_RADIUS 100
#define FRAME_DEGREE 1

typedef struct Point
{
	double x;
	double y;
} Point, *pPoint;

void calculate_slopes();

pPoint generate_frames(const pPoint const base_point, pPoint point_lst);

void move_base_pointer(const pPoint const base_point);