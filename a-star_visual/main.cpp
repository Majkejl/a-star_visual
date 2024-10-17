#include "data.hpp"
#include "a_star.hpp"
#include "renderer.hpp"

void draw_map(Renderer& r, Graph& g, A_star<Graph>& as)
{
	r.draw_grid();
	for (int i = 0; i < g.height(); i++)
	{
		for (int j = 0; j < g.width(); j++)
		{
			/* int rgb = 0;
			switch (g.get(j, i))
			{
			case blocks::start:
				rgb = 0x00FF00;
				break;
			case blocks::target:
				rgb = 0xFF0000;
				break;
			case blocks::wall:
				rgb = 0xFFFFFF;
				break;
			case blocks::empty:
				break;
			} */
			if (g.get(j, i) == blocks::wall) r.draw_wall(j, i, 0xFFFFFF);
		}
	}

	if (as.target_n != nullptr)
	{
		auto ptr = as.target_n;
		int g_max = ptr->g;
		while (ptr != nullptr)
		{
			r.draw_wall(ptr->p.x, ptr->p.y, ((0xFF / g_max * ptr->g) << 16) + ((0xFF / g_max * (g_max - ptr->g) << 8)));
			ptr = ptr->parent;
		}
	} // TODO add else
	r.present();
}

int main()
{
	constexpr int width = 720;
	constexpr int height = 720;

	Graph g(p1);
	Renderer r(width, height, g.width(), g.height());
	A_star<Graph> as(g);


	as.run();

	draw_map(r, g, as);
	r.present();

	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT) quit = true;
			//else if (e.type == SDL_KEYDOWN); 
		}
	}

	return 0;
}