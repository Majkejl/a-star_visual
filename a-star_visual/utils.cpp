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

bool operator<(Node lhs, Node other)
{
	if (lhs.p.x != other.p.x) return lhs.p.x < other.p.x;
	return lhs.p.y < other.p.y;
}

bool Node::operator==(Node& other)
{
	return p == other.p;
}

