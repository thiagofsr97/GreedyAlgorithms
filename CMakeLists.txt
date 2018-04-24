cmake_minimum_required(VERSION 3.10)
project(GreedyAlgorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories(Dijkstra)
include_directories(FileReader)
include_directories(Graph)
include_directories(Heap)
include_directories(Node)

add_executable(GreedyAlgorithms
        Dijkstra/Dijsktra.cpp
        Dijkstra/Dijsktra.h
        FileReader/FileReader.cpp
        FileReader/FileReader.h
        Graph/Graph.cpp
        Graph/Graph.h
        Heap/Heap.h
        Node/Node.cpp
        Node/Node.h
        main.cpp PRIM/PRIM.cpp PRIM/PRIM.h)
