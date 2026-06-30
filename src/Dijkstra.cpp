#include "D:/archita/CODES/Smart-Route-Planner/include/Dijkstra.h"

#include <queue>
#include <limits>

std::unordered_map<std::string, int>
Dijkstra::shortestPath(const Graph &graph,
                       const std::string &source)
{
    const auto &adj = graph.getGraph();

    std::unordered_map<std::string, int> distance;

    for (const auto &city : adj)
    {
        distance[city.first] = std::numeric_limits<int>::max();
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

            if (distance[currentCity] + weight < distance[next])
            {
                distance[next] =
                    distance[currentCity] + weight;

                pq.push({distance[next], next});
            }
        }
    }

    return distance;
}