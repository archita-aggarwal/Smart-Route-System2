#include "D:/archita/CODES/Smart-Route-Planner/include/CycleDetection.h"

bool CycleDetection::dfs(const Graph &graph,
                         const std::string &current,
                         const std::string &parent,
                         std::unordered_set<std::string> &visited)
{
    visited.insert(current);

    const auto &adj = graph.getGraph();

    for (const auto &neighbour : adj.at(current))
    {
        std::string next = neighbour.first;

        if (visited.find(next) == visited.end())
        {
            if (dfs(graph,
                    next,
                    current,
                    visited))
            {
                return true;
            }
        }
        else if (next != parent)
        {
            return true;
        }
    }

    return false;
}

bool CycleDetection::hasCycle(const Graph &graph)
{
    std::unordered_set<std::string> visited;

    const auto &adj = graph.getGraph();

    for (const auto &city : adj)
    {
        if (visited.find(city.first) == visited.end())
        {
            if (dfs(graph,
                    city.first,
                    "",
                    visited))
            {
                return true;
            }
        }
    }

    return false;
}