//
// Created by thiagofsr on 26/04/18.
//

#include <algorithm>
#include <iostream>
#include "Kruskal.h"

struct comp {
    bool operator() ( std::pair<int,std::pair<Node*,Node*>> i,std::pair<int,std::pair<Node*,Node*>> j) {
        return (i.first<j.first);
    }
} myComp;

Kruskal::Kruskal(Graph *graph) {
    this->graph = graph;
    this->result = 0;
    for(auto node: graph->getAllNodes()){
        node->clearSettings();
    }
}


Node* Kruskal::findSet(Node* node) {
    Node* parent = graph->getNode(node->getPredecessorId());
    if(node->getIdentifier() != node->getPredecessorId()){
        return findSet(parent);
    }
    return parent;
}

void Kruskal::makeSet(Node *u, Node *v) {
    u = findSet(u);
    v = findSet(v);


    if(u->getRank() < v->getRank()){
        u->setPredecessorId(v->getIdentifier());
//        std::cout << "Lesser " << u->getIdentifier() << " Rank:" << u->getRank() << " " << v->getIdentifier() << " Rank:" << v->getRank() <<std::endl;
    }else if(u->getRank() > v->getRank()){
        v->setPredecessorId(u->getIdentifier());
        //std::cout << "Greater " << u->getIdentifier() << " Rank:" << u->getRank() << " " << v->getIdentifier() << " Rank:" << v->getRank() <<std::endl;
    }

    //if that happens then the the v node will always be set as the parent of u node
    if(u->getRank() == v->getRank()){
        v->setRank(v->getRank() + 1);
        u->setPredecessorId(v->getIdentifier());
    }

}



void Kruskal::addEdge(int weight, Node* u, Node* v) {

    if(v->getIdentifier() < u->getIdentifier()){
        Node* aux = v;
        v = u;
        u = aux;

    }
    bool found = false;
    //avoind duplicate insertions (u,v) = (v,u)
    if(!edges.empty()){
        for(auto edge:edges){
            if(u->getIdentifier() == edge.second.first->getIdentifier() && v->getIdentifier() == edge.second.second->getIdentifier()) {
                found = true;
                break;
            }
        }
    }

    if(!found){
        edges.push_back( {weight,{u,v}});

    }
}

void Kruskal::solveProblem() {

    //inserting edges to vector to be sorted according to weight of edges
    result = 0;
    for(auto node: graph->getAllNodes()){
        node->setPredecessorId(node->getIdentifier());
        for(auto neighbor:node->getNeighbors()){
            addEdge(graph->getWeigth(node->getIdentifier(),neighbor->getIdentifier()),node,neighbor);
        }
    }
    std::sort(edges.begin(),edges.end(),myComp);


    for(auto edge: edges){
        Node *u;
        Node *v;
        Node* setU;
        Node *setV;

        u = edge.second.first; // first Node
        v = edge.second.second; // second Node

        //searching for parents

        setU = findSet(u);
        setV = findSet(v);




        //if that happens, mean they have different parents, which means that doesnt make a cycle
        if(setU->getIdentifier() != setV->getIdentifier()){
            result += edge.first;
//            std::cout << "Parent: " << u->getPredecessorId() << " Child: " << u->getIdentifier() << std::endl;
//            std::cout << "Parent: " << v->getPredecessorId() << " Child: " << v->getIdentifier() << std::endl;
//            std::cout << std::endl << std::endl;

            makeSet(setU,setV);
            std::cout << u->getIdentifier() << "  -  " << v->getIdentifier() << " Weight: " << edge.first << std::endl;
        }



    }




}

int Kruskal::getResult(){
    return this->result;
}