#pragma once
#include "a-star.hpp"
#include <memory>

using plane_t = std::vector<std::vector<blocks>>;
using plane_ptr = std::unique_ptr<plane_t>;

class out_of_bounds : std::exception {};

constexpr int DEFAULT_SIZE = 10;

class Graph
{
	plane_ptr plane;
	int w;
	int h;

public:
	Graph(plane_t _p);
	Graph(int _w, int _h);
	Graph();

	bool in_bounds(int x, int y) const;
	inline bool in_bounds(Position p) const { return in_bounds(p.x, p.y); }

	blocks get(int x, int y) const;
	inline blocks get(Position p) const { return get(p.x, p.y); }
	void set(int x, int y, blocks value);
	inline void set(Position p, blocks value) { return set(p.x, p.y, value); }

	inline int width() const { return w; }
	inline int height() const { return h; }
};