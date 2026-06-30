#include "D:/archita/CODES/Smart-Route-Planner/include/AStar.h"
#include <queue>
#include <limits>

std::unordered_map<std::string,int>
AStar::shortestPath(const Graph &graph,
                    const std::string &source)
{
    const auto &adj = graph.getGraph();

    std::unordered_map<std::string,int> dist;

    for(const auto &city : adj)
    {
        dist[city.first] =
        std::numeric_limits<int>::max();
    }

    dist[source]=0;

    using Node=std::pair<int,std::string>;

    std::priority_queue<
    Node,
    std::vector<Node>,
    std::greater<Node>> pq;

    pq.push({0,source});

    while(!pq.empty())
    {
        auto current=pq.top();

        pq.pop();

        for(auto &edge:adj.at(current.second))
        {
            if(dist[current.second]+edge.second
               < dist[edge.first])
            {
                dist[edge.first]=
                dist[current.second]+edge.second;

                pq.push(
                {
                    dist[edge.first],
                    edge.first
                });
            }
        }
    }

    return dist;
}