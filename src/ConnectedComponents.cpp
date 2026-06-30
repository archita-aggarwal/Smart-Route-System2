#include "D:/archita/CODES/Smart-Route-Planner/include/ConnectedComponents.h"

void ConnectedComponents::dfs(const Graph &graph,
                              const std::string &city,
                              std::unordered_set<std::string> &visited,
                              std::vector<std::string> &component)
{
    visited.insert(city);
    component.push_back(city);

    const auto &adj = graph.getGraph();

    for (const auto &neighbour : adj.at(city))
    {
        if (visited.find(neighbour.first) == visited.end())
        {
            dfs(graph,
                neighbour.first,
                visited,
                component);
        }
    }
}

std::vector<std::vector<std::string>>
ConnectedComponents::findComponents(const Graph &graph)
{
    std::vector<std::vector<std::string>> components;

    std::unordered_set<std::string> visited;

    const auto &adj = graph.getGraph();

    for (const auto &city : adj)
    {
        if (visited.find(city.first) == visited.end())
        {
            std::vector<std::string> component;

            dfs(graph,
                city.first,
                visited,
                component);

            components.push_back(component);
        }
    }

    return components;
}