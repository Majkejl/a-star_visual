#include <iostream>
#include "render.hpp"


Renderer::Renderer(int w, int h)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << '\n';
		throw;
	}

	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		std::cerr << "Warning: Linear texture filtering not enabled!" << '\n';
	}

	//Create window
	gWindow = SDL_CreateWindow("a-star", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
		throw;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << '\n';
		throw;
	}

	//Initialize renderer color
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

Renderer::~Renderer()
{
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	gWindow = NULL;
	gRenderer = NULL;

	SDL_Quit();
}