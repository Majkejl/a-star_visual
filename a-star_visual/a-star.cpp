

#include <vector>
#include <exception>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include "a-star.hpp"

Position::Position(int _x, int _y) : x( _x ), y( _y ) {}
Position::Position() { Position(0, 0); }

Position operator+(Position lhs, Position rhs)
{
	return Position(lhs.x + rhs.x, lhs.y + rhs.y);
}

int Position::operator-(Position other)
{
	return std::abs(x - other.x) + std::abs(y - other.y);
}

bool Position::operator==(Position other)
{
	return x == other.x && y == other.y;
}

Graph::Graph(int _w, int _h) : w( _w ), h( _h )
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


bool operator>(Node lhs, Node other)
{
	if (lhs.f() != other.f()) return lhs.f() > other.f();
	if (lhs.p.x != other.p.x) return lhs.p.x > other.p.x;
	return lhs.p.y > other.p.y;
}

bool Node::operator==(Node& other)
{
	return p == other.p;
}


template<typename T>
Node a_star(T graph, g_set &visited)
{
	Position start;
	Position target;
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
Node a_star(T graph, Position start, Position target, g_set &visited)
{
	std::priority_queue<Node, std::vector<Node>, std::greater<Node>> que;
	que.emplace(nullptr, start, blocks::start, 0, start - target );


	while (!que.empty())
	{
		Node n = que.top();
		visited.emplace(n);

		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				Position new_p = n.p + Position{i, j};
				if (new_p == target) return { &n, target, blocks::target, n.g + 1, 0 }; // change return type
				Node tmp{ &n, new_p, graph.get(new_p), n.g + 1, target - new_p};
				auto existing = visited.find(tmp);
				if (existing != visited.end())
				{
					if (tmp.f() > existing->f()) continue;
					visited.erase(existing);
					visited.insert(tmp);
				}
				que.emplace(tmp);
			}
		}
	}
	return Node();
}

int main()
{
	Graph g;
	g_set visited;
	a_star<Graph>(g, visited);
}