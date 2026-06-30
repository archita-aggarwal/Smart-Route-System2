#include "D:/archita/CODES/Smart-Route-Planner/include/DFS.h"

void DFS::dfsHelper(const Graph &graph,
                    const std::string &city,
                    std::unordered_set<std::string> &visited,
                    std::vector<std::string> &result)
{
    visited.insert(city);
    result.push_back(city);

    const auto &adj = graph.getGraph();

    for (const auto &neighbour : adj.at(city))
    {
        if (visited.find(neighbour.first) == visited.end())
        {
            dfsHelper(graph,
                      neighbour.first,
                      visited,
                      result);
        }
    }
}

std::vector<std::string> DFS::traverse(const Graph &graph,
                                       const std::string &startCity)
{
    std::vector<std::string> result;

    const auto &adj = graph.getGraph();

    if (adj.find(startCity) == adj.end())
        return result;

    std::unordered_set<std::string> visited;

    dfsHelper(graph,
              startCity,
              visited,
              result);

    return result;
}