#include "D:/archita/CODES/Smart-Route-Planner/include/FileLoader.h"

#include <fstream>

void FileLoader::load(Graph &graph,
                      const std::string &filename)
{
    std::ifstream file(filename);

    std::string source,destination;

    int weight;

    while(file>>source>>destination>>weight)
    {
        graph.addRoad(source,
                      destination,
                      weight);
    }

    file.close();
}