#pragma once
#include <vector>
#include <exception>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include "utils.hpp"

template<typename T>
class A_star 
{
	T& graph;
	g_set visited;
	Position start;
	Position target;
	Position current;
	Node target_n;
	bool end = false;

public:
	A_star(T& graph, Position s, Position t);
	A_star(T& graph);

	bool run();
};


