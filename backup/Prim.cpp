#include "D:/archita/CODES/Smart-Route-Planner/include/Prim.h"

#include <queue>
#include <unordered_set>
#include <iostream>

void Prim::minimumSpanningTree(const Graph &graph,
                               const std::string &start)
{
    using Edge=
    std::pair<int,
    std::pair<std::string,std::string>>;

    std::priority_queue<
    Edge,
    std::vector<Edge>,
    std::greater<Edge>
    > pq;

    std::unordered_set<std::string> visited;

    const auto &adj=graph.getGraph();

    visited.insert(start);

    for(auto &edge:adj.at(start))
    {
        pq.push(
        {
            edge.second,
            {
                start,
                edge.first
            }
        });
    }

    int total=0;

    std::cout<<"\nPrim MST\n\n";

    while(!pq.empty())
    {
        auto current=pq.top();

        pq.pop();

        int weight=current.first;

        std::string from=current.second.first;

        std::string to=current.second.second;

        if(visited.count(to))
            continue;

        visited.insert(to);

        total+=weight;

        std::cout
        <<from
        <<" - "
        <<to
        <<" : "
        <<weight
        <<'\n';

        for(auto &edge:adj.at(to))
        {
            if(!visited.count(edge.first))
            {
                pq.push(
                {
                    edge.second,
                    {
                        to,
                        edge.first
                    }
                });
            }
        }
    }

    std::cout<<"\nTotal Cost = "
             <<total
             <<'\n';
}