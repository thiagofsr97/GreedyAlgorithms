//
// Created by thiagofsr on 22/04/18.
//

#ifndef GREEDYALGORITHMS_NODE_H
#define GREEDYALGORITHMS_NODE_H

#include <string>
#include <map>
#include <climits>
#include <vector>

class Node {
private:
    int identifier;
    bool visited;
    int weight;
    int predecessorId;
    std::vector<Node*> neighbors;
public:
    Node(const int& id);

    void addNeighbor(Node* node);
    std::vector<Node*> getNeighbors();
    int getIdentifier();
    bool beenVisited();
    void switchState();
    int getWeight();
    void setWeight(int weight);
    void setPredecessorId(int id);
    int getPredecessorId();
    void clearSettings();
    void clearVisited();


    bool operator<(const Node& other);
};

#endif //GREEDYALGORITHMS_NODE_H
