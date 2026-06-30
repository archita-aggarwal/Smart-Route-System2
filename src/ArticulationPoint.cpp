#include "D:/archita/CODES/Smart-Route-Planner/include/ArticulationPoint.h"

#include <algorithm>

void ArticulationPoint::dfs(
    const Graph &graph,
    const std::string &node,
    const std::string &parent,
    std::unordered_map<std::string,bool> &visited,
    std::unordered_map<std::string,int> &tin,
    std::unordered_map<std::string,int> &low,
    std::vector<std::string> &points)
{
    visited[node] = true;

    tin[node] = low[node] = timer++;

    int children = 0;

    const auto &adj = graph.getGraph();

    for(const auto &edge : adj.at(node))
    {
        std::string next = edge.first;

        if(next == parent)
            continue;

        if(visited[next])
        {
            low[node] = std::min(low[node],
                                 tin[next]);
        }
        else
        {
            dfs(graph,next,node,
                visited,tin,low,points);

            low[node] = std::min(low[node],
                                 low[next]);

            if(parent != "" &&
               low[next] >= tin[node])
            {
                points.push_back(node);
            }

            children++;
        }
    }

    if(parent == "" && children > 1)
    {
        points.push_back(node);
    }
}

std::vector<std::string>
ArticulationPoint::findPoints(
const Graph &graph)
{
    timer = 0;

    std::unordered_map<std::string,bool> visited;
    std::unordered_map<std::string,int> tin;
    std::unordered_map<std::string,int> low;

    std::vector<std::string> points;

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
                points);
        }
    }

    std::sort(points.begin(), points.end());

    points.erase(
        std::unique(points.begin(), points.end()),
        points.end());

    return points;
}