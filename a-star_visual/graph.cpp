#include "graph.hpp"

Graph::Graph(int _w, int _h) : w(_w), h(_h)
{
	for (size_t i = 0; i < h; i++)
	{
		plane.emplace_back(w, blocks::empty);
	}
}

Graph::Graph() : Graph(DEFAULT_SIZE, DEFAULT_SIZE)
{
	plane[0][0] = blocks::start;
	plane[9][9] = blocks::target;
}

bool Graph::in_bounds(int x, int y)
{
	return x < w && y < h && x >= 0 && y >= 0;
}

blocks Graph::get(int x, int y)
{
	return in_bounds(x, y) ? plane[y][x] : blocks::wall;
}

void Graph::set(int x, int y, blocks value)
{
	if (!in_bounds(x, y)) throw out_of_bounds();
	plane[y][x] = value;
}
