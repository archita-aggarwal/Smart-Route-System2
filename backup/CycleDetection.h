#pragma once

#include "Graph.h"
#include <unordered_set>
#include <string>

class CycleDetection
{
private:
    bool dfs(const Graph &graph,
             const std::string &current,
             const std::string &parent,
             std::unordered_set<std::string> &visited);

public:
    bool hasCycle(const Graph &graph);
};