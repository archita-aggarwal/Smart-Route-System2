#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

class Graph
{
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adj;
    bool directed;
    bool weighted;

public:
    Graph(bool isDirected = false, bool isWeighted = true);

    void addCity(const std::string &city);

    void addRoad(const std::string &source,
                 const std::string &destination,
                 int weight);

    void removeRoad(const std::string &source,
                    const std::string &destination);

    void updateRoad(const std::string &source,
                    const std::string &destination,
                    int newWeight);

    bool hasCity(const std::string &city) const;

    void display() const;

    const std::unordered_map<std::string,
          std::vector<std::pair<std::string,int>>>&
    getGraph() const;
};