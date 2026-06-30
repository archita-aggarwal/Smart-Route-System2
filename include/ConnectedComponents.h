#pragma once

#include "Graph.h"
#include <vector>
#include <string>
#include <unordered_set>

class ConnectedComponents
{
private:
    void dfs(const Graph &graph,
             const std::string &city,
             std::unordered_set<std::string> &visited,
             std::vector<std::string> &component);

public:
    std::vector<std::vector<std::string>>
    findComponents(const Graph &graph);
};