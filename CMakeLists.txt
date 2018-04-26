cmake_minimum_required(VERSION 3.4)
project(GreedyAlgorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories(Dijkstra)
include_directories(FileReader)
include_directories(Graph)
include_directories(Heap)
include_directories(Kruskal)
include_directories(Node)
include_directories(PRIM)

add_executable(GreedyAlgorithms
        Dijkstra/Dijsktra.cpp
        Dijkstra/Dijsktra.h
        FileReader/FileReader.cpp
        FileReader/FileReader.h
        Graph/Graph.cpp
        Graph/Graph.h
        Heap/Heap.h
        Kruskal/Kruskal.cpp
        Kruskal/Kruskal.h
        Node/Node.cpp
        Node/Node.h
        PRIM/PRIM.cpp
        PRIM/PRIM.h
        main.cpp)
