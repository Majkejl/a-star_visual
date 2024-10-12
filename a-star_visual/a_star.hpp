#pragma once
#include <vector>
#include <exception>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include "utils.hpp"
#include "graph.hpp"

using que_t = std::priority_queue<Node, std::vector<Node>, std::greater<Node>>;

template<typename T>
class A_star 
{
	T& graph;
	std::map<Position, std::unique_ptr<Node>> visited;
	Position start;
	Position target;
	Position current;
	bool end = false;

public:
	Node target_n;

	A_star(T& graph, Position s, Position t);
	A_star(T& graph);

	bool step(que_t& que);
	bool run();
};

