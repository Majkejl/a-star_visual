#include <iostream>
#include "renderer.hpp"


Renderer::Renderer(int w, int h, int g_w, int g_h) : grid_w{ g_w }, grid_h{ g_h }
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

void Renderer::draw_grid() // TODO add viewport to keep squares square
{
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(gRenderer);
	int w, h;
	SDL_GetWindowSize(gWindow, &w, &h);

	int block_w = w / grid_w;
	int block_h = h / grid_h;


	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (int i = block_h; i < h; i += block_h)
	{
		SDL_RenderDrawLine(gRenderer, 0, i, w, i);
	}

	for (int i = block_w; i < w; i += block_w)
	{
		SDL_RenderDrawLine(gRenderer, i, 0, i, h);
	}

	
}