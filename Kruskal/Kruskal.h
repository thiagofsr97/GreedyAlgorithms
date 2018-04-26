//
// Created by thiagofsr on 26/04/18.
//

#ifndef GREEDYALGORITHMS_KRUSKAL_H
#define GREEDYALGORITHMS_KRUSKAL_H


#include <vector>
#include <Graph.h>

class Kruskal {
private:
    Graph* graph;
    std::vector<std::pair<int,std::pair<Node*,Node*>>> edges;
    void addEdge(int weight,Node* u, Node* v);
    int result;
    Node* findSet(Node* nodeId);
    void makeSet(Node* u, Node* v);
public:
    Kruskal(Graph* graph);
    void solveProblem();
    int getResult();


};


#endif //GREEDYALGORITHMS_KRUSKAL_H
