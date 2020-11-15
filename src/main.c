#include <SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

#include "logic_structures.h"

extern double SLOPES[];

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("Beautiful-Trigonometry---Numberphile", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Event event;
	bool running = true;

	//create base circle
	struct Point base_point;
	base_point.x = CIRCLE_RADIUS;
	base_point.y = 0;

	//calculate lines slopes
	calculate_slopes();

	//allocate point list
	pPoint point_lst = (pPoint)malloc(sizeof(struct Point) * NUM_OF_LINES);

	if (!point_lst)
	{ 
		printf("%s\n", "can't allocate memory. exiting");
		exit(1);
	}
	while (running)
	{
		//event if user wants to 
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			running = false;

		//generate frame
		generate_frames(&base_point, point_lst);


		// draw
			//draw backround (black screen)
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);
		
			//draw point's lines
		SDL_SetRenderDrawColor(render, 255, 0, 255, 255);
		
		for (size_t l = 0; l < NUM_OF_LINES; l++)
		{

			if (l == 0 || l == 1)
				SDL_RenderDrawLine(render, 512, 384 + CIRCLE_RADIUS, 512, 384 - CIRCLE_RADIUS);
			else
			{
				SDL_RenderDrawLine(render, 512 + CIRCLE_RADIUS * cos(SLOPES[l]), (double)384 + CIRCLE_RADIUS * sin(SLOPES[l]), 512 + -CIRCLE_RADIUS * cos(SLOPES[l]), 384 + -CIRCLE_RADIUS * sin(SLOPES[l]));
			}

		}
			
			//draw the frame
		SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
		for (size_t p = 0; p < NUM_OF_LINES; p++)
		{
			SDL_Rect rect = { 512 + point_lst[p].x, 384 + point_lst[p].y, 10, 10 };
			SDL_RenderDrawRect(render, &rect);
		}
		SDL_SetRenderDrawColor(render, 0, 255, 255, 255);
		SDL_Rect rect = { 512 + base_point.x, 384 + base_point.y, 20,20 };
		SDL_RenderDrawRect(render, &rect);

		//draw the changes
		SDL_RenderPresent(render);
		//move the base point for the next frame
		move_base_pointer(&base_point);
	}
	
	//free allocated memory
	free(point_lst);
	return 0;
}