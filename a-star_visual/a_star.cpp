#include "a_star.hpp"

A_star<Graph>::A_star(Graph& g, Renderer& r, Position s, Position t) : graph{ g }, render{ r }, start{ s }, target{ t } {}

A_star<Graph>::A_star(Graph& g, Renderer& r) : A_star<Graph>(g, r, {0,0}, {0,0})
{
	int found = 0;
	for (int y = 0; y < graph.height(); y++)
	{
		for (int x = 0; x < graph.width(); x++)
		{
			if (graph.get(x, y) == blocks::start) { start = { x, y }; ++found; }
			else if (graph.get(x, y) == blocks::target) { target = { x, y }; ++found; }
	
			if (found == 2) break;
		}
		if (found == 2) break;
	}
}

bool A_star<Graph>::step(que_t& que)
{
	Node n = que.top(); // TODO color current point
	visited.emplace(n);

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (end) return false;

			Position new_p = n.p + Position{ i, j };
			if (!graph.in_bounds(new_p)) continue;
			if (new_p == target)
			{
				target_n = { &n, target, blocks::target, n.g + 1, 0 }; // TODO color target
				return true;
			}

			Node tmp{ &n, new_p, graph.get(new_p), n.g + 1, target - new_p };
			auto existing = visited.find(tmp);
			if (existing != visited.end())
			{
				if (tmp.f() > existing->f()) continue;
				visited.erase(existing);
				visited.insert(tmp);
			}
			que.emplace(tmp); // TODO draw new line
		}
	}
}

bool A_star<Graph>::run()
{
	que_t que;
	que.emplace(nullptr, start, blocks::start, 0, start - target );

	while (!que.empty())
	{
		// rendering
		render.draw_grid();	
		for (int i = 0; i < graph.height(); i++)
		{
			for (int j = 0; j < graph.width(); j++)
			{
				int rgb = 0;
				switch (graph.get(j, i))
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
				render.draw_wall(j, i, rgb);
			}
		}

		render.present();

		// algorithm
		step(que);
	}
	return false;
}
