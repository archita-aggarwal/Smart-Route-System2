#pragma once

#include "Graph.h"
#include <vector>
#include <string>
#include <unordered_set>

class DFS
{
private:
    void dfsHelper(const Graph &graph,
                   const std::string &city,
                   std::unordered_set<std::string> &visited,
                   std::vector<std::string> &result);

public:
    std::vector<std::string> traverse(const Graph &graph,
                                      const std::string &startCity);
};