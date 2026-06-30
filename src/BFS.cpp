#include "D:/archita/CODES/Smart-Route-Planner/include/BFS.h"

#include <iostream>
#include <queue>
#include <unordered_set>

void BFS::traverse(const Graph &graph,
                   const std::string &startCity)
{
    const auto &adj = graph.getGraph();

    if (adj.find(startCity) == adj.end())
    {
        std::cout << "City not found.\n";
        return;
    }

    std::queue<std::string> q;

    std::unordered_set<std::string> visited;

    visited.insert(startCity);

    q.push(startCity);

    while (!q.empty())
    {
        std::string current = q.front();

        q.pop();

        std::cout << current << " ";

        for (const auto &neighbour : adj.at(current))
        {
            std::string next = neighbour.first;

            if (visited.find(next) == visited.end())
            {
                visited.insert(next);

                q.push(next);
            }
        }
    }

    std::cout << std::endl;
}