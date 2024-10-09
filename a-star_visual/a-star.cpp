#include "a-star.hpp"

template<typename T>
A_star<T>::A_star(T g, Position s, Position t) : graph{ g }, start{ s }, target{ t } {}

template<typename T>
A_star<T>::A_star(T g) : A_star<T>(g, {0,0}, {0,0})
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

	return a_star(graph, start, target, visited);
}

template<typename T>
bool A_star<T>::run()
{
	std::priority_queue<Node, std::vector<Node>, std::greater<Node>> que;
	que.emplace(nullptr, start, blocks::start, 0, start - target );


	while (!que.empty())
	{
		Node n = que.top(); // TODO color current point
		visited.emplace(n);

		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (end) return false;

				Position new_p = n.p + Position{i, j};
				if (!graph.in_bounds(new_p)) continue;
				if (new_p == target)
				{
					target_n = { &n, target, blocks::target, n.g + 1, 0 }; // TODO color target
					return true;
				}

				Node tmp{ &n, new_p, graph.get(new_p), n.g + 1, target - new_p};
				auto existing = visited.find(tmp);
				if (existing != visited.end())
				{
					if (tmp.f() > existing->f()) continue;
					visited.erase(existing);
					visited.insert(tmp);
				}
				que.emplace(tmp); // TODO draw new line
			}
		}
	}
	return false;
}
