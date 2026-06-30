#include "D:/archita/CODES/Smart-Route-Planner/include/BellmanFord.h"

#include <limits>

std::unordered_map<std::string, int>
BellmanFord::shortestPath(const Graph &graph,
                          const std::string &source)
{
    const auto &adj = graph.getGraph();

    std::unordered_map<std::string, int> distance;

    for (const auto &city : adj)
    {
        distance[city.first] = std::numeric_limits<int>::max();
    }

    distance[source] = 0;

    int vertices = adj.size();

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
                }
            }
        }
    }

    return distance;
}