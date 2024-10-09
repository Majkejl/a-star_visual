#pragma once
#define SDL_MAIN_HANDLED // idk why but thank you stack overflow
#include <SDL.h>

struct Renderer {
	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Surface* gCurrentSurface = NULL;
	SDL_Renderer* gRenderer = NULL;

	int grid_w;
	int grid_h;

	int block_w;
	int block_h;

	Renderer(int w, int h, int g_w, int g_h);
	~Renderer();

	inline void present() { SDL_RenderPresent(gRenderer); }

	void get_block_size();
	void set_color(int rgb);

	void draw_grid();
	void draw_wall(int x, int y, int rgb);
	void draw_line(int x1, int y1, int x2, int y2, int rgb);

};