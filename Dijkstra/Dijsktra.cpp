#include <queue>
#include "Dijsktra.h"



bool compareNode(Node *a, Node* b){
    if(a->getWeight() == b->getWeight()) // to guarantee a stable sorting process
        return true;
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


    graph->getAllNodes().front()->setWeight(0);

    std::priority_queue<Node*,std::vector<Node*>,decltype(&compareNode)> queue(&compareNode);

    queue.push(graph->getAllNodes().front());


    while(!queue.empty()){

        auto c = queue.top();
        if(c->getIdentifier() == graph->getAllNodes().back()->getIdentifier())
            solved = true;
        queue.pop();
        c->switchState();

            for (auto v: c->getNeighbors()) {
                int newWeight = c->getWeight() + graph->getWeigth(c->getIdentifier(), v->getIdentifier());
                if (!v->beenVisited() && newWeight < v->getWeight()) {
                    v->setPredecessorId(c->getIdentifier());
                    v->setWeight(newWeight);
                    queue.push(v);

                }
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
