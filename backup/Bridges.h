#pragma once

#include "Graph.h"
#include <unordered_map>
#include <vector>
#include <string>

class Bridges
{
private:
    int timer;

    void dfs(const Graph &graph,
             const std::string &node,
             const std::string &parent,
             std::unordered_map<std::string,bool> &visited,
             std::unordered_map<std::string,int> &tin,
             std::unordered_map<std::string,int> &low,
             std::vector<std::pair<std::string,std::string>> &bridges);

public:
    std::vector<std::pair<std::string,std::string>>
    findBridges(const Graph &graph);
};