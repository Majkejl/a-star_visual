#pragma once
#include "a-star.hpp"

using plane_t = std::vector<std::vector<blocks>>;

class out_of_bounds : std::exception {};

constexpr int DEFAULT_SIZE = 10;

class Graph
{
	plane_t plane;
	int w;
	int h;

public:
	Graph(int _w, int _h);
	Graph();

	bool in_bounds(int x, int y);
	inline bool in_bounds(Position p) { return in_bounds(p.x, p.y); }

	blocks get(int x, int y);
	inline blocks get(Position p) { return get(p.x, p.y); }
	void set(int x, int y, blocks value);
	inline void set(Position p, blocks value) { return set(p.x, p.y, value); }

	inline int width() { return w; }
	inline int height() { return h; }
};