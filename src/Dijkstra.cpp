#include "D:/archita/CODES/Smart-Route-Planner/include/Dijkstra.h"

#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>

void Dijkstra::shortestPath(const Graph &graph,
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

    using P = std::pair<int, std::string>;

    std::priority_queue<
        P,
        std::vector<P>,
        std::greater<P>> pq;

    pq.push({0, source});

    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();

        int currentDistance = current.first;
        std::string currentCity = current.second;

        if (currentDistance > distance[currentCity])
            continue;

        for (const auto &edge : adj.at(currentCity))
        {
            std::string next = edge.first;
            int weight = edge.second;

            if (distance[currentCity] != std::numeric_limits<int>::max() &&
                distance[currentCity] + weight < distance[next])
            {
                distance[next] = distance[currentCity] + weight;
                parent[next] = currentCity;

                pq.push({distance[next], next});
            }
        }
    }

    std::cout << "\n========================================\n";
    std::cout << "        DIJKSTRA SHORTEST PATH\n";
    std::cout << "========================================\n\n";

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