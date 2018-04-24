//
// Created by thiagofsr on 24/04/18.
//


#include <iostream>
#include <queue>
#include "PRIM.h"


class comp
{
public:
    bool operator() ( Node* lhs, Node* rhs) const
    {
        if(lhs->getWeight() == rhs->getWeight())
            return true;

        return (lhs->getWeight()>rhs->getWeight());
    }
};

void PRIM::solveProblem() {

    Node* currentNode = graph->getNode(0);
    currentNode->setWeight(0);
    std::priority_queue<Node*,std::vector<Node*>,comp> queue;

    queue.push(currentNode);

    while(!queue.empty()){
        auto current = queue.top();
        queue.pop();


        current->switchState();

        for(auto c: current->getNeighbors()){
            int newWeight = graph->getWeigth(current->getIdentifier(),c->getIdentifier());
            if(!c->beenVisited() && newWeight < c->getWeight()){

                c->setWeight(newWeight);
                c->setPredecessorId(current->getIdentifier());
                queue.push(c);
            }
        }
    }


}

PRIM::PRIM(Graph *graph) {
    this->graph = graph;
    this->solved = false;
    for(auto v:graph->getAllNodes()){
        v->clearSettings();
    }


}

int PRIM::getResult() {

    auto allNodes = graph->getAllNodes();
    Node* parent;
    Node *child;
    result = 0;
    for(int i = 0; i <allNodes.size();i++ ){
        child = allNodes.at(i);
        if(child->getPredecessorId() == -1)
            parent = nullptr;
        else
            parent = graph->getNode(child->getPredecessorId());
       if(parent != nullptr && child != nullptr){
           result += graph->getWeigth(parent->getIdentifier(),child->getIdentifier());
       }

    }
    return result;
}
