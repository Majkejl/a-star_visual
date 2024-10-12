#pragma once
#include <vector>
#include <exception>
#include <set>

enum class blocks { empty, wall, start, target };

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

struct Node
{
	Node* parent = nullptr;
	Position p;
	blocks b;
	int g;
	int h;
	inline int f() const { return g + h; }

	friend bool operator<(Node lhs, Node other);
	friend bool operator>(Node lhs, Node other);
	bool operator==(Node& other);
};
using g_set = std::set<Node>;