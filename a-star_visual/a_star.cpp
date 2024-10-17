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

bool A_star<Graph>::step(que_t& que)
{
	Node* n = que.top();
	que.pop();

	for (Position pos : std::vector<Position>{ 
				{ -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } 
			})
	{
		Position new_p = n->p + pos;
		if ( (pos.x == 0 && pos.y == 0) 
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

bool A_star<Graph>::run()
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
