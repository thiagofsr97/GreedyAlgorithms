//
// Created by thiagofsr on 24/04/18.
//

#ifndef GREEDYALGORITHMS_PRIM_H
#define GREEDYALGORITHMS_PRIM_H


#include <Graph.h>

class PRIM {
private:
    Graph *graph;
    bool solved;
    std::vector<Node*> mstTree;
    long result;
public:

    PRIM(Graph *graph);
    std::vector<unsigned int> getShortestPath();
    int getResult();
    void solveProblem();

};


#endif //GREEDYALGORITHMS_PRIM_H
