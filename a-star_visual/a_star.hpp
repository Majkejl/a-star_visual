#pragma once
#include <vector>
#include <exception>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include "utils.hpp"
#include "renderer.hpp"
#include "graph.hpp"

using que_t = std::priority_queue<Node, std::vector<Node>, std::greater<Node>>;

template<typename T>
class A_star 
{
	T& graph;
	Renderer& render;
	g_set visited;
	Position start;
	Position target;
	Position current;
	Node target_n;
	bool end = false;

public:
	A_star(T& graph, Renderer& r, Position s, Position t);
	A_star(T& graph, Renderer& r);

	bool step(que_t& que);
	bool run();
};

//#include "a_star.cpp" // bruh
