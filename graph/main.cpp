#include <iostream>
#include <vector>
#include "graph.h"
#include "vertex.h"

int main() {
    Graph graph;
    for (int i = 0; i < 10; i++) {
        graph.addVertex(i);
    }
    for (int i = 0; i < 10; i++) {
        graph.addEdge(i, (i + 1) % 10);
        graph.addEdge(i, (i + 2) % 10);
        graph.addEdge(i, (i + 3) % 10);
    }
    graph.printGraph();
}