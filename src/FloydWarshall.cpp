#include "D:/archita/CODES/Smart-Route-Planner/include/FloydWarshall.h"

#include <iostream>
#include <limits>

void FloydWarshall::shortestPaths(const Graph &graph)
{
    const auto &adj = graph.getGraph();

    std::vector<std::string> cities;
    std::unordered_map<std::string, int> index;

    int id = 0;

    for (const auto &city : adj)
    {
        cities.push_back(city.first);
        index[city.first] = id++;
    }

    int n = cities.size();

    const int INF = 1e9;

    std::vector<std::vector<int>> dist(
        n,
        std::vector<int>(n, INF));

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (const auto &city : adj)
    {
        int u = index[city.first];

        for (const auto &edge : city.second)
        {
            int v = index[edge.first];

            dist[u][v] = edge.second;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] =
                        dist[i][k] + dist[k][j];
                }
            }
        }
    }

    std::cout << "\nAll Pair Shortest Path\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout
                << cities[i]
                << " -> "
                << cities[j]
                << " = ";

            if (dist[i][j] == INF)
                std::cout << "INF";
            else
                std::cout << dist[i][j];

            std::cout << '\n';
        }
        std::cout << '\n';
    }
}