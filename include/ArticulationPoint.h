#pragma once

#include "Graph.h"
#include <unordered_map>
#include <vector>
#include <string>

class ArticulationPoint
{
private:
    int timer;

    void dfs(const Graph &graph,
             const std::string &node,
             const std::string &parent,
             std::unordered_map<std::string,bool> &visited,
             std::unordered_map<std::string,int> &tin,
             std::unordered_map<std::string,int> &low,
             std::vector<std::string> &points);

public:
    std::vector<std::string>
    findPoints(const Graph &graph);
};