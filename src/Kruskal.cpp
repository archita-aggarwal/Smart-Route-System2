#include "D:/archita/CODES/Smart-Route-Planner/include/Kruskal.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/DSU.h"

#include <algorithm>
#include <iostream>

void Kruskal::minimumSpanningTree(const Graph &graph)
{
    std::vector<
    std::tuple<int,std::string,std::string>
    > edges;

    const auto &adj = graph.getGraph();

    for(const auto &city : adj)
    {
        for(const auto &edge : city.second)
        {
            edges.push_back(
            {
                edge.second,
                city.first,
                edge.first
            });
        }
    }

    std::sort(edges.begin(),
              edges.end());

    DSU dsu;

    for(const auto &city : adj)
    {
        dsu.makeSet(city.first);
    }

    std::cout<<"\nKruskal MST\n\n";

    int total=0;

    for(auto &edge : edges)
    {
        int weight;

        std::string u,v;

        std::tie(weight,u,v)=edge;

        if(dsu.find(u)!=dsu.find(v))
        {
            dsu.unite(u,v);

            total+=weight;

            std::cout
            <<u
            <<" - "
            <<v
            <<" : "
            <<weight
            <<'\n';
        }
    }

    std::cout<<"\nTotal Cost = "
             <<total
             <<'\n';
}