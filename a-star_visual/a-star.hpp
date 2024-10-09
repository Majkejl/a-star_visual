#pragma once
#include <vector>
#include <exception>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include "utils.hpp"

template<typename T>
Node a_star(T graph, g_set &visited);

template<typename T>
Node a_star(T graph, Position start, Position target, g_set &visited);
