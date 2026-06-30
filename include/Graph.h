#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Graph
{
private:
    bool directed;

    std::unordered_map<
        std::string,
        std::vector<std::pair<std::string, int>>
    > adjList;

public:

    Graph(bool directed = false);

    void addCity(const std::string &city);

    void addRoad(const std::string &source,
                 const std::string &destination,
                 int weight);

    void display() const;

    const std::unordered_map<
        std::string,
        std::vector<std::pair<std::string, int>>
    >& getGraph() const;
};