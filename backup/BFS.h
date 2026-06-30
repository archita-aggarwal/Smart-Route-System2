#pragma once

#include "Graph.h"
#include <string>

class BFS
{
public:
    void traverse(const Graph &graph, const std::string &startCity);
};