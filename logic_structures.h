#pragma once

#define NUM_OF_LINES 10
#define CIRCLE_RADIUS 100

typedef struct Point
{
	double x;
	double y;
} Point, *pPoint;

typedef struct BasePoint
{
	Point point;
	int radius;
} BasePoint, *pBasePoint;

void calculate_slopes();

pPoint generate_frames(const pBasePoint const base_point, int nLines);