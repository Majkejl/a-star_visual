#include "graph.hpp"
#include "data.hpp"
#include "a_star.hpp"

void draw_map(Renderer& r, Graph& g)
{
	r.draw_grid();
	for (int i = 0; i < g.height(); i++)
	{
		for (int j = 0; j < g.width(); j++)
		{
			int rgb = 0;
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
			}
			r.draw_wall(j, i, rgb);
		}
	}
}

int main()
{
	constexpr int width = 1280;
	constexpr int height = 720;

	Graph g(p1);
	Renderer r(width, height, g.width(), g.height());
	A_star<Graph> as(g, r);

	draw_map(r, g);

	as.run();

	r.present();



	return 0;
}