#pragma once

#include "Graph.h"
#include <unordered_map>
#include <string>

class AStar
{
public:
    std::unordered_map<std::string,int>
    shortestPath(const Graph &graph,
                 const std::string &source);
};