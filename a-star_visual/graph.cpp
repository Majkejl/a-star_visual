#include "graph.hpp"

Graph::Graph(plane_t _p) : plane{ std::make_unique<plane_t>(_p) } 
{
	w = static_cast<int>(plane->data()->size());
	h = static_cast<int>(plane->size());
}

Graph::Graph(int _w, int _h) : plane{ std::make_unique<plane_t>() }, w{ _w }, h{ _h }
{
	for (size_t i = 0; i < h; i++)
	{
		plane->emplace_back(w, blocks::empty);
	}
}

Graph::Graph() : Graph(DEFAULT_SIZE, DEFAULT_SIZE)
{
	(*plane)[0][0] = blocks::start;
	(*plane)[DEFAULT_SIZE - 1][DEFAULT_SIZE - 1] = blocks::target;
}

bool Graph::in_bounds(int x, int y) const
{
	return x < w && y < h && x >= 0 && y >= 0;
}

blocks Graph::get(int x, int y) const
{
	return in_bounds(x, y) ? (*plane)[y][x] : blocks::wall;
}

void Graph::set(int x, int y, blocks value)
{
	if (!in_bounds(x, y)) throw out_of_bounds();
	(*plane)[y][x] = value;
}
