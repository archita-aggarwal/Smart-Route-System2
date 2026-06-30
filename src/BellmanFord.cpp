#include "D:/archita/CODES/Smart-Route-Planner/include/BellmanFord.h"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>

void BellmanFord::shortestPath(const Graph &graph,
                               const std::string &source)
{
    const auto &adj = graph.getGraph();

    std::unordered_map<std::string, int> distance;
    std::unordered_map<std::string, std::string> parent;

    for (const auto &city : adj)
    {
        distance[city.first] = std::numeric_limits<int>::max();
        parent[city.first] = "";
    }

    if (adj.find(source) == adj.end())
    {
        std::cout << "Source city not found.\n";
        return;
    }

    distance[source] = 0;

    int vertices = adj.size();

    // Relax all edges V-1 times
    for (int i = 1; i < vertices; i++)
    {
        for (const auto &city : adj)
        {
            std::string u = city.first;

            if (distance[u] == std::numeric_limits<int>::max())
                continue;

            for (const auto &edge : city.second)
            {
                std::string v = edge.first;
                int weight = edge.second;

                if (distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Negative Cycle Detection
    bool negativeCycle = false;

    for (const auto &city : adj)
    {
        std::string u = city.first;

        if (distance[u] == std::numeric_limits<int>::max())
            continue;

        for (const auto &edge : city.second)
        {
            std::string v = edge.first;
            int weight = edge.second;

            if (distance[u] + weight < distance[v])
            {
                negativeCycle = true;
            }
        }
    }

    std::cout << "\n========================================\n";
    std::cout << "         BELLMAN FORD\n";
    std::cout << "========================================\n\n";

    if (negativeCycle)
    {
        std::cout << "Negative Cycle Detected!\n";
        std::cout << "Shortest Paths cannot be determined.\n";
        return;
    }

    std::cout << "No Negative Cycle Found\n\n";

    for (const auto &city : distance)
    {
        std::cout << "Destination : "
                  << city.first << "\n";

        if (city.second == std::numeric_limits<int>::max())
        {
            std::cout << "Distance : INF\n";
            std::cout << "Path : Not Reachable\n\n";
            continue;
        }

        std::cout << "Distance : "
                  << city.second
                  << " km\n";

        std::vector<std::string> path;

        std::string current = city.first;

        while (current != "")
        {
            path.push_back(current);
            current = parent[current];
        }

        std::reverse(path.begin(), path.end());

        std::cout << "Path : ";

        for (size_t i = 0; i < path.size(); i++)
        {
            std::cout << path[i];

            if (i != path.size() - 1)
                std::cout << " -> ";
        }

        std::cout << "\n";
        std::cout << "----------------------------------------\n";
    }
}