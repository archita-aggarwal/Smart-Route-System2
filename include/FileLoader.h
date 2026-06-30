#pragma once

#include "Graph.h"
#include <string>

class FileLoader
{
public:
    void load(Graph &graph,
              const std::string &filename);
};