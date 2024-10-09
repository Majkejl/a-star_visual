#pragma once
#include <vector>
#include <exception>
#include <set>

const int DEFAULT_SIZE = 10;

enum class blocks {	empty, wall, start, target };

using plane_t = std::vector<std::vector<blocks>>;

class out_of_bounds : std::exception {};

struct Position
{
	int x;
	int y;

	Position(int, int);
	Position();

	friend Position operator+(Position lhs, Position rhs);
	int operator-(Position other);
	bool operator==(Position other);
};

class Graph
{
	plane_t plane;
	int w = 10;
	int h = 10;

public:
	Graph(int _w, int _h);
	Graph();

	bool in_bounds(int x, int y);
	inline bool in_bounds(Position p) { return in_bounds(p.x, p.y); }

	blocks get(int x, int y);
	inline blocks get(Position p) {	return get(p.x, p.y); }
	void set(int x, int y, blocks value);
	inline void set(Position p, blocks value) { return set(p.x, p.y, value); }

	inline int width() { return w; }
	inline int height() { return h; }
};


struct Node
{
	Node* parent = nullptr;
	Position p;
	blocks b;
	int g;
	int h;
	inline int f() const { return g + h; }

	friend bool operator>(Node lhs, Node other);
	bool operator==(Node& other);
};
using g_set = std::set<Node, std::greater<Node>>;


template<typename T>
Node a_star(T graph, g_set &visited);

template<typename T>
Node a_star(T graph, Position start, Position target, g_set &visited);
