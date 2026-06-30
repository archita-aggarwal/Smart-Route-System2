#include "D:/archita/CODES/Smart-Route-Planner/include/DSU.h"

void DSU::makeSet(const std::string &city)
{
    parent[city] = city;
    rank[city] = 0;
}

std::string DSU::find(const std::string &city)
{
    if(parent[city] == city)
        return city;

    parent[city] = find(parent[city]);

    return parent[city];
}

void DSU::unite(const std::string &u,
               const std::string &v)
{
    std::string rootU = find(u);
    std::string rootV = find(v);

    if(rootU == rootV)
        return;

    if(rank[rootU] < rank[rootV])
    {
        parent[rootU] = rootV;
    }
    else if(rank[rootU] > rank[rootV])
    {
        parent[rootV] = rootU;
    }
    else
    {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}