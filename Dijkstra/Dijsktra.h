//
// Created by thiagofsr on 22/04/18.
//

#ifndef GREEDYALGORITHMS_DIJSKTRA_H
#define GREEDYALGORITHMS_DIJSKTRA_H


#include "../Graph/Graph.h"
#include "../Heap/Heap.h"

class Dijsktra {
private:
    Graph *graph;
    Node *source;
    Node* destiny;
    bool solved;
public:

    Dijsktra(Graph *graph);
    std::vector<unsigned int> getShortestPath();
    long getShortestWeight();
    void solveProblem();
};


#endif //GREEDYALGORITHMS_DIJSKTRA_H
