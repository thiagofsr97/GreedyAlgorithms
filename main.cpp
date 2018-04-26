#include <iostream>
#include "FileReader/FileReader.h"
#include "Dijkstra/Dijsktra.h"
#include "PRIM/PRIM.h"
#include "Kruskal/Kruskal.h"

enum op{DIJKSTRA, KRUSKAL,PRIMS};

void PrintWrong(){
    std::cout << "Missing or wrong arguments, exiting program." << std::endl;
    exit(0);
}
int main(int argc, char* argv[]) {

    if(argc < 3){
        PrintWrong();
    }
    std::string command = argv[1];
    int op;

    if(command == "dij"){
        op = DIJKSTRA;
    }else if(command == "prim"){
        op = PRIMS;
    }else if(command ==  "kru"){
        op = KRUSKAL;
    }else{
        PrintWrong();
    }

    command = argv[2];
    FileReader file(command);
    Graph* graph = file.createGraph();
    std::cout<<std::endl;

    Dijsktra *dijsktra;
    PRIM *prim;
    Kruskal *kruskal1;

    switch (op){
        case DIJKSTRA:
            std::cout
                    << "========== Dijkstra Solution ==========\n";
            dijsktra = new Dijsktra(graph);
            dijsktra->solveProblem();
            std::cout << "Shortest Weight: " << dijsktra->getShortestWeight() << std::endl;
            std::cout << "Path: ";
            for (auto v:dijsktra->getShortestPath()) {
                std::cout << v << " ";
            }
            std::cout << std::endl<< "==============================\n";

            break;

        case KRUSKAL:
            std::cout << "========== Kruskal Solution ==========\n";
            kruskal1 = new Kruskal(graph);
            kruskal1->solveProblem();
            std::cout << "Result " << kruskal1->getResult() << std::endl;
            std::cout
                    << "==============================\n";
            break;

        case PRIMS:
            std::cout << "========== Prim Solution ==========\n";

            prim = new PRIM(graph);
            prim->solveProblem();
            std::cout << "MST Tree Result: " << prim->getResult() << std::endl;
            std::cout << "==============================\n";
            break;

        default:
            PrintWrong();
            break;

    }


      delete graph;

    return 0;
}
