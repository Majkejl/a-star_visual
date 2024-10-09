#pragma once
#include "graph.hpp"

const plane_t p1{
	{blocks::start, blocks::empty, blocks::empty, blocks::wall,  blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty},
	{blocks::wall,  blocks::wall,  blocks::empty, blocks::wall,  blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty},
	{blocks::empty, blocks::empty, blocks::empty, blocks::wall,  blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty},
	{blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty},
	{blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::wall,  blocks::wall,  blocks::wall,  blocks::empty, blocks::empty, blocks::empty},
	{blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::wall,  blocks::target,blocks::wall,  blocks::wall, blocks::empty, blocks::empty},
	{blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::wall,  blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty},
	{blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::wall,  blocks::wall,  blocks::wall,  blocks::empty, blocks::empty, blocks::empty},
	{blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty},
	{blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty, blocks::empty}
};
