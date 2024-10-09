#include "graph.hpp"
#include "data.hpp"
#include "a_star.hpp"

int main()
{
	constexpr int width = 1280;
	constexpr int height = 720;

	Graph g(p1);
	Renderer r(width, height, g.width(), g.height());
	A_star<Graph> as(g, r);

	as.run();

	while (true);

	return 0;
}