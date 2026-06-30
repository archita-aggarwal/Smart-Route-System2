#pragma once

#include "Graph.h"

class BellmanFord
{
public:
    void shortestPath(const Graph &graph,
                      const std::string &source);
};