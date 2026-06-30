#include "D:/archita/CODES/Smart-Route-Planner/include/Graph.h"
#include <iostream>

Graph::Graph(bool isDirected, bool isWeighted)
{
    directed = isDirected;
    weighted = isWeighted;
}

bool Graph::hasCity(const std::string &city) const
{
    return adj.find(city) != adj.end();
}

void Graph::addCity(const std::string &city)
{
    if (!hasCity(city))
    {
        adj[city] = {};
    }
}

void Graph::addRoad(const std::string &source,
                    const std::string &destination,
                    int weight)
{
    // Agar city exist nahi karti to bana do
    addCity(source);
    addCity(destination);

    // Source -> Destination
    adj[source].push_back({destination, weight});

    // Agar graph undirected hai to reverse edge bhi add hogi
    if (!directed)
    {
        adj[destination].push_back({source, weight});
    }
}

void Graph::removeRoad(const std::string &source,
                       const std::string &destination)
{
    if (!hasCity(source) || !hasCity(destination))
        return;

    auto &neighbours = adj[source];

    for (auto it = neighbours.begin(); it != neighbours.end(); it++)
    {
        if (it->first == destination)
        {
            neighbours.erase(it);
            break;
        }
    }

    if (!directed)
    {
        auto &reverseNeighbours = adj[destination];

        for (auto it = reverseNeighbours.begin(); it != reverseNeighbours.end(); it++)
        {
            if (it->first == source)
            {
                reverseNeighbours.erase(it);
                break;
            }
        }
    }
}

void Graph::updateRoad(const std::string &source,
                       const std::string &destination,
                       int newWeight)
{
    if (!hasCity(source) || !hasCity(destination))
        return;

    for (auto &edge : adj[source])
    {
        if (edge.first == destination)
        {
            edge.second = newWeight;
            break;
        }
    }

    if (!directed)
    {
        for (auto &edge : adj[destination])
        {
            if (edge.first == source)
            {
                edge.second = newWeight;
                break;
            }
        }
    }
}

void Graph::display() const
{
    std::cout << "\n========== GRAPH ==========\n\n";

    for (const auto &city : adj)
    {
        std::cout << city.first << " -> ";

        for (const auto &edge : city.second)
        {
            std::cout << "("
                      << edge.first
                      << ", "
                      << edge.second
                      << ") ";
        }

        std::cout << "\n";
    }

    std::cout << "\n===========================\n";
}

const std::unordered_map<std::string,
std::vector<std::pair<std::string,int>>>&
Graph::getGraph() const
{
    return adj;
}