//
// Created by thiagofsr on 22/04/18.
//

#include <queue>
#include "Dijsktra.h"



bool compareNode(Node *a, Node* b){
    return a->getWeight() > b->getWeight();

}

Dijsktra::Dijsktra(Graph *graph):graph(graph) {
    this->solved = false;
    this->source= graph->getAllNodes().front();
    this->destiny = graph->getAllNodes().back();
    for(auto v: graph->getAllNodes()){
        v->clearSettings();
    }
}



void Dijsktra::solveProblem() {

    Node* currentNode;

    std::vector<Node*> allNodes = graph->getAllNodes();
    allNodes.front()->setWeight(0);


    Heap<Node*> queue = Heap<Node*>(allNodes.size(),MIN);
    for(auto node: allNodes){
        queue.Insert(node);
    }



    while(currentNode = queue.ExtractTop(nullptr)){
        if(currentNode == destiny)
            this->solved = true;
        if(!currentNode->beenVisited()){
            std::cout << "Visited: "<< currentNode->getIdentifier() << std::endl;
                for(auto neighbor:currentNode->getNeighbors()){
                    if(!neighbor->beenVisited()){
                        long newWeight =  currentNode->getWeight() + graph->getWeigth(currentNode->getIdentifier(),neighbor->getIdentifier());
                        if( newWeight < neighbor->getWeight()){
                            neighbor->setWeight(newWeight);
                            neighbor->setPredecessorId(currentNode->getIdentifier());
                            queue.BuildHeapfied();
                        }

                    }
                }
                currentNode->switchState();



        }
    }


}

std::vector <unsigned int> Dijsktra::getShortestPath() {
    if(!solved)
        return std::vector<unsigned int>();
    std::vector<unsigned int> path;


    Node* current = this->destiny;
    while(current != this->source){
        path.insert(path.begin(),current->getIdentifier());
        current = graph->getNode(current->getPredecessorId());
    }
    path.insert(path.begin(),source->getIdentifier());
    return path;
}

long Dijsktra::getShortestWeight() {
    if(!solved)
        return -1;
   return this->destiny->getWeight();
}
