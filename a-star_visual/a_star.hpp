#pragma once
#include <vector>
#include <exception>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include "utils.hpp"
#include "graph.hpp"

using que_t = std::priority_queue<Node*, std::vector<Node*>, N_cmp>;

template<typename G>
concept graph_c = requires(G g)
{
	{ g.height() } -> std::convertible_to<std::size_t>;
	{ g.width() } -> std::convertible_to<std::size_t>;
	{ g.get(Position()) } -> std::same_as<blocks>;
	{ g.in_bounds(Position()) } -> std::convertible_to<bool>;
};

template<graph_c T>
class A_star 
{
	T& graph;
	std::map<Position, std::unique_ptr<Node>> visited;
	Position start;
	Position target;
	Position current;
	bool end = false;

public:
	Node* target_n = nullptr; // TODO make private + getter

	A_star(T& graph, Position s, Position t);
	A_star(T& graph);

	bool step(que_t& que);
	bool run();
};

template<graph_c T>
A_star<T>::A_star(T& g, Position s, Position t) : graph{ g }, start{ s }, target{ t } {}

template<graph_c T>
A_star<T>::A_star(T& g) : A_star<T>(g, { 0,0 }, { 0,0 })
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

template<graph_c T>
bool A_star<T>::step(que_t& que)
{
	Node* n = que.top();
	que.pop();

	for (Position pos : std::vector<Position>{
				{ -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 }
		})
	{
		Position new_p = n->p + pos;
		if ((pos.x == 0 && pos.y == 0)
			|| !graph.in_bounds(new_p)
			|| graph.get(new_p) == blocks::wall)
			continue;
		if (visited.contains(new_p)) continue;
		visited.emplace(new_p, std::make_unique<Node>(n, new_p, graph.get(new_p), n->g + 1, target - new_p));
		if (new_p == target)
		{
			target_n = visited.at(new_p).get();
			return true;
		}

		que.emplace(visited.at(new_p).get());
	}
	return false;
}

template<graph_c T>
bool A_star<T>::run()
{
	visited.clear();
	visited.emplace(start, std::make_unique<Node>(nullptr, start, blocks::start, 0, start - target));

	que_t que;
	que.push(visited.begin()->second.get());

	while (!que.empty())
	{
		if (step(que)) return true;
	}
	return false;
}