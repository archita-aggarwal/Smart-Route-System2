#pragma once

#include "Graph.h"
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>

class SCC
{
private:
    void dfs1(const Graph &graph,
              const std::string &city,
              std::unordered_set<std::string> &visited,
              std::stack<std::string> &st);

    void dfs2(const std::unordered_map<
              std::string,
              std::vector<std::pair<std::string,int>>> &transpose,
              const std::string &city,
              std::unordered_set<std::string> &visited,
              std::vector<std::string> &component);

public:
    std::vector<std::vector<std::string>>
    kosaraju(const Graph &graph);
};