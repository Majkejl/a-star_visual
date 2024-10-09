#include "a-star.hpp"
#include "renderer.hpp"
#include "graph.hpp"
#include "data.hpp"

int main()
{
	constexpr int width = 1280;
	constexpr int height = 720;

	Graph g(p1);
	Renderer r(width, height, g.width(), g.height());
	A_star<Graph> as(g, r);

	as.run();

	return 0;
}