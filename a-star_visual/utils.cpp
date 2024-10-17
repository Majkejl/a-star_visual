#include "utils.hpp"

Position::Position(int _x, int _y) : x(_x), y(_y) {}
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

bool operator<(Position lhs, Position other)
{
	if (lhs.x != other.x) return lhs.x < other.x;
	return lhs.y < other.y;
}

bool operator>(Node lhs, Node other)
{
	if (lhs.f() != other.f()) return lhs.f() > other.f();
	if (lhs.p.x != other.p.x) return lhs.p.x > other.p.x;
	return lhs.p.y > other.p.y;
}

bool N_cmp::operator()(const Node* lhs, const Node* other) const
{
	return (*lhs) > (*other);
}


bool Node::operator==(Node& other)
{
	return p == other.p;
}

