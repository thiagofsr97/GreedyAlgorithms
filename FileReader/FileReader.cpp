//
// Created by thiagofsr on 22/04/18.
//


#include <sstream>
#include "FileReader.h"

FileReader::FileReader(const std::string &pathFile) {
    this->inputFile = new std::fstream(pathFile,std::ios::in);
    if(!inputFile->is_open()){
        std::cout << "Error opening file, check path.\n";
        exit(1);
    }

}

FileReader::~FileReader() {
    delete this->inputFile;

}

Graph *FileReader::createGraph() {
    int offset = 0;
    int count = 0;
    int currentLine = 0;
    int j;
    int matrixSize = 0;
    std::string line,numbers;
    getline(*inputFile,line);
    std::vector<std::string> weights;
    matrixSize = std::stoi(line);
    for(int i = 0; i < matrixSize;i++){
        offset+=(i+1);
    }
    Graph *graph = new Graph(matrixSize,(matrixSize*matrixSize)-offset);

    for(int i = 0; i < matrixSize;i++)
        graph->addNode(new Node(i));



    while(!inputFile->eof()){
      getline(*inputFile,line);
      if(!line.empty()){
          std::stringstream ss{line};

          while(ss >> numbers) weights.push_back(numbers);

          j = currentLine + 1; //offset


          while(!weights.empty()){
              //setting the adjacency matrix
              graph->addWeightMatrix(count++,std::stol(weights.front()));


              //setting neighbors of a node
              graph->getNode((unsigned int)currentLine)->addNeighbor(graph->getNode((unsigned int)j));
              graph->getNode((unsigned int)j)->addNeighbor(graph->getNode((unsigned int)currentLine));


              weights.erase(weights.begin());
              j++;

          }

          currentLine++;
      }
    }

//    graph->showMatrix();
//    graph->showNeighbors();

    return graph;
}


