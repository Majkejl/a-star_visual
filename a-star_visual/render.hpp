#pragma once
#define SDL_MAIN_HANDLED // idk why but thank you stack overflow
#include <SDL.h>

struct Renderer {
	SDL_Window* gWindow = NULL; 
	SDL_Surface* gScreenSurface = NULL;
	SDL_Surface* gCurrentSurface = NULL;
	SDL_Renderer* gRenderer = NULL;


	Renderer(int w, int h);
	~Renderer();

	
};