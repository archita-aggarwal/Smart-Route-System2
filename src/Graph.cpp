#include "D:/archita/CODES/Smart-Route-Planner/include/Graph.h"
#include <iostream>

Graph::Graph(bool directed)
{
    this->directed = directed;
}

void Graph::addCity(const std::string &city)
{
    if (adjList.find(city) == adjList.end())
    {
        adjList[city] = {};
    }
}

void Graph::addRoad(const std::string &source,
                    const std::string &destination,
                    int weight)
{
    addCity(source);
    addCity(destination);

    bool exists = false;

    for (const auto &edge : adjList[source])
    {
        if (edge.first == destination)
        {
            exists = true;
            break;
        }
    }

    if (!exists)
    {
        adjList[source].push_back({destination, weight});
    }

    if (!directed)
    {
        exists = false;

        for (const auto &edge : adjList[destination])
        {
            if (edge.first == source)
            {
                exists = true;
                break;
            }
        }

        if (!exists)
        {
            adjList[destination].push_back({source, weight});
        }
    }
}

void Graph::display() const
{
    std::cout << "\n=============================\n";
    std::cout << "        GRAPH DISPLAY\n";
    std::cout << "=============================\n\n";

    for (const auto &city : adjList)
    {
        std::cout << city.first << "\n";

        if (city.second.empty())
        {
            std::cout << "   No Connections\n";
        }
        else
        {
            for (const auto &edge : city.second)
            {
                std::cout
                    << "   --> "
                    << edge.first
                    << " ("
                    << edge.second
                    << " km)"
                    << std::endl;
            }
        }

        std::cout << std::endl;
    }
}

const std::unordered_map<
    std::string,
    std::vector<std::pair<std::string, int>>
>& Graph::getGraph() const
{
    return adjList;
}