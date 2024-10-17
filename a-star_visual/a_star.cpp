#include "a_star.hpp"

A_star<Graph>::A_star(Graph& g, Position s, Position t) : graph{ g }, start{ s }, target{ t } {}

A_star<Graph>::A_star(Graph& g) : A_star<Graph>(g, {0,0}, {0,0})
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
