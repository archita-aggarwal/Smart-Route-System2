#pragma once

#include "Graph.h"
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>

class TopologicalSort
{
private:
    void dfs(const Graph &graph,
             const std::string &city,
             std::unordered_set<std::string> &visited,
             std::stack<std::string> &st);

public:
    std::vector<std::string> sort(const Graph &graph);
};