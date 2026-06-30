#include <iostream>

#include "D:/archita/CODES/Smart-Route-Planner/include/Graph.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/FileLoader.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/BFS.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/DFS.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/ConnectedComponents.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/CycleDetection.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/TopologicalSort.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/Dijkstra.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/BellmanFord.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/FloydWarshall.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/Kruskal.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/Prim.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/Bridges.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/ArticulationPoint.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/SCC.h"
#include "D:/archita/CODES/Smart-Route-Planner/include/AStar.h"

int main()
{
    Graph graph;

    FileLoader loader;
    loader.load(graph, "input/graph.txt");

    BFS bfs;
    DFS dfs;
    ConnectedComponents cc;
    CycleDetection cycle;
    TopologicalSort topo;
    Dijkstra dijkstra;
    BellmanFord bellman;
    FloydWarshall fw;
    Kruskal kruskal;
    Prim prim;
    Bridges bridges;
    ArticulationPoint ap;
    SCC scc;
    AStar astar;

    int choice;

    do
    {
        std::cout << "\n====================================\n";
        std::cout << "      SMART ROUTE PLANNER\n";
        std::cout << "====================================\n";

        std::cout << "1. Display Graph\n";
        std::cout << "2. BFS\n";
        std::cout << "3. DFS\n";
        std::cout << "4. Connected Components\n";
        std::cout << "5. Cycle Detection\n";
        std::cout << "6. Topological Sort\n";
        std::cout << "7. Dijkstra\n";
        std::cout << "8. Bellman Ford\n";
        std::cout << "9. Floyd Warshall\n";
        std::cout << "10. Kruskal MST\n";
        std::cout << "11. Prim MST\n";
        std::cout << "12. Bridges\n";
        std::cout << "13. Articulation Points\n";
        std::cout << "14. SCC\n";
        std::cout << "15. A*\n";
        std::cout << "16. Exit\n";

        std::cout << "\nEnter Choice : ";
        std::cin >> choice;

        switch(choice)
        {
            case 1:
                graph.display();
                break;

            case 2:
                bfs.traverse(graph, "Delhi");
                break;

            case 3:
                dfs.traverse(graph, "Delhi");
                break;

            case 4:
                cc.findComponents(graph);
                break;

            case 5:
                cycle.hasCycle(graph);
                break;

            case 6:
                topo.sort(graph);
                break;

            case 7:
                dijkstra.shortestPath(graph, "Delhi");
                break;

            case 8:
                bellman.shortestPath(graph, "Delhi");
                break;

            case 9:
                fw.shortestPaths(graph);
                break;

            case 10:
                kruskal.minimumSpanningTree(graph);
                break;

            case 11:
                prim.minimumSpanningTree(graph, "Delhi");
                break;

            case 12:
                bridges.findBridges(graph);
                break;

            case 13:
                ap.findPoints(graph);
                break;

            case 14:
                scc.kosaraju(graph);
                break;

            case 15:
                astar.shortestPath(graph, "Delhi");
                break;

            case 16:

                std::cout<<"\nThank You!\n";

                break;

            default:
                std::cout<<"\nInvalid Choice\n";
        }

    }while(choice!=16);

    return 0;
}