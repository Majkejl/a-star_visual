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

void Renderer::get_block_size()
{
	int w, h;
	SDL_GetWindowSize(gWindow, &w, &h);

	block_w = w / grid_w;
	block_h = h / grid_h;
}

void Renderer::set_color(int rgb)
{
	SDL_SetRenderDrawColor(gRenderer, rgb >> 16, rgb >> 8, rgb, 0xFF);
}

void Renderer::draw_grid() // TODO add viewport to keep squares square
{
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(gRenderer);

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (int i = 1; i < grid_h; ++i)
	{
		SDL_RenderDrawLine(gRenderer, 0, i * block_h, grid_w * block_w, i * block_h);
	}

	for (int i = 1; i < grid_w; ++i)
	{
		SDL_RenderDrawLine(gRenderer, i * block_w, 0, i * block_w, grid_h * block_w);
	}
}

void Renderer::draw_wall(int x, int y, int rgb = 0xFFFFFF)
{
	set_color(rgb);

	SDL_Rect rect{ x * block_w, y * block_h, block_w, block_h};
	SDL_RenderDrawRect(gRenderer, &rect);
}

void Renderer::draw_line(int x1, int y1, int x2, int y2, int rgb = 0xFFFFFF)
{
	SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);
}

void Renderer::draw_circle(int x, int y, int rgb = 0xFF00FF)
{
	// TODO maybe next time
}