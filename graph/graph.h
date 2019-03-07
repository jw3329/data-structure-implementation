#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "vertex.h"

class Graph {
   private:
    std::vector<Vertex *> vertices;

   public:
    void addEdge(int src, int dest);
    void addVertex(int v);
    void printGraph();
    ~Graph();
    void BFS(int v);
    void DFS(int v);
    Vertex *getVertex(int v);
};

#endif  // GRAPH_H