#include "D:/archita/CODES/Smart-Route-Planner/include/SCC.h"

void SCC::dfs1(const Graph &graph,
               const std::string &city,
               std::unordered_set<std::string> &visited,
               std::stack<std::string> &st)
{
    visited.insert(city);

    const auto &adj = graph.getGraph();

    for(const auto &edge : adj.at(city))
    {
        if(!visited.count(edge.first))
        {
            dfs1(graph, edge.first, visited, st);
        }
    }

    st.push(city);
}

void SCC::dfs2(
const std::unordered_map<
std::string,
std::vector<std::pair<std::string,int>>> &transpose,
const std::string &city,
std::unordered_set<std::string> &visited,
std::vector<std::string> &component)
{
    visited.insert(city);

    component.push_back(city);

    for(const auto &edge : transpose.at(city))
    {
        if(!visited.count(edge.first))
        {
            dfs2(transpose,
                 edge.first,
                 visited,
                 component);
        }
    }
}

std::vector<std::vector<std::string>>
SCC::kosaraju(const Graph &graph)
{
    const auto &adj = graph.getGraph();

    std::unordered_set<std::string> visited;

    std::stack<std::string> st;

    for(const auto &city : adj)
    {
        if(!visited.count(city.first))
        {
            dfs1(graph,
                 city.first,
                 visited,
                 st);
        }
    }

    std::unordered_map<
    std::string,
    std::vector<std::pair<std::string,int>>> transpose;

    for(const auto &city : adj)
    {
        transpose[city.first];

        for(const auto &edge : city.second)
        {
            transpose[edge.first].push_back(
            {
                city.first,
                edge.second
            });
        }
    }

    visited.clear();

    std::vector<std::vector<std::string>> result;

    while(!st.empty())
    {
        std::string city = st.top();

        st.pop();

        if(!visited.count(city))
        {
            std::vector<std::string> component;

            dfs2(transpose,
                 city,
                 visited,
                 component);

            result.push_back(component);
        }
    }

    return result;
}