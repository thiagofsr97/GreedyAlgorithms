#include <iostream>
#include "FileReader/FileReader.h"
#include "Dijkstra/Dijsktra.h"
#include "PRIM/PRIM.h"

int main() {


    FileReader file("test.txt");
    Graph* graph = file.createGraph();
    graph->showMatrix();
//    Dijsktra dijsktra(graph);
//    dijsktra.solveProblem();
//    std::cout<< "Shortest Weight: " << dijsktra.getShortestWeight() <<std::endl;
//    std::cout << "Path: ";
//    for(auto v:dijsktra.getShortestPath()){
//        std::cout << v << " ";
//    }
//    std::cout << std::endl;
    PRIM prim(graph);
    prim.solveProblem();
    std::cout << "Result " << prim.getResult() <<std::endl;

    delete graph;

    return 0;
}