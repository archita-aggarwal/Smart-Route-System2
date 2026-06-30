#include "D:/archita/CODES/Smart-Route-Planner/include/Bridges.h"

void Bridges::dfs(const Graph &graph,
                  const std::string &node,
                  const std::string &parent,
                  std::unordered_map<std::string,bool> &visited,
                  std::unordered_map<std::string,int> &tin,
                  std::unordered_map<std::string,int> &low,
                  std::vector<std::pair<std::string,std::string>> &bridges)
{
    visited[node] = true;

    tin[node] = low[node] = timer++;

    const auto &adj = graph.getGraph();

    for(const auto &edge : adj.at(node))
    {
        std::string next = edge.first;

        if(next == parent)
            continue;

        if(!visited[next])
        {
            dfs(graph,next,node,
                visited,tin,low,bridges);

            low[node] = std::min(low[node],
                                 low[next]);

            if(low[next] > tin[node])
            {
                bridges.push_back({node,next});
            }
        }
        else
        {
            low[node] = std::min(low[node],
                                 tin[next]);
        }
    }
}

std::vector<std::pair<std::string,std::string>>
Bridges::findBridges(const Graph &graph)
{
    timer = 0;

    std::unordered_map<std::string,bool> visited;
    std::unordered_map<std::string,int> tin;
    std::unordered_map<std::string,int> low;

    std::vector<std::pair<std::string,std::string>> ans;

    const auto &adj = graph.getGraph();

    for(const auto &city : adj)
    {
        if(!visited[city.first])
        {
            dfs(graph,
                city.first,
                "",
                visited,
                tin,
                low,
                ans);
        }
    }

    return ans;
}