#include "D:/archita/CODES/Smart-Route-Planner/include/TopologicalSort.h"

void TopologicalSort::dfs(const Graph &graph,
                          const std::string &city,
                          std::unordered_set<std::string> &visited,
                          std::stack<std::string> &st)
{
    visited.insert(city);

    const auto &adj = graph.getGraph();

    for (const auto &neighbour : adj.at(city))
    {
        if (visited.find(neighbour.first) == visited.end())
        {
            dfs(graph,
                neighbour.first,
                visited,
                st);
        }
    }

    st.push(city);
}

std::vector<std::string>
TopologicalSort::sort(const Graph &graph)
{
    std::vector<std::string> order;

    std::unordered_set<std::string> visited;

    std::stack<std::string> st;

    const auto &adj = graph.getGraph();

    for (const auto &city : adj)
    {
        if (visited.find(city.first) == visited.end())
        {
            dfs(graph,
                city.first,
                visited,
                st);
        }
    }

    while (!st.empty())
    {
        order.push_back(st.top());
        st.pop();
    }

    return order;
}