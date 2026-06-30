#pragma once

#include <unordered_map>
#include <string>

class DSU
{
private:
    std::unordered_map<std::string, std::string> parent;
    std::unordered_map<std::string, int> rank;

public:
    void makeSet(const std::string &city);

    std::string find(const std::string &city);

    void unite(const std::string &u,
               const std::string &v);
};