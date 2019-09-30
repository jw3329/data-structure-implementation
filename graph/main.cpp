#include <ctime>
#include <iostream>
#include <vector>
#include "graph.h"
#include "vertex.h"

int main() {
    srand(time(nullptr));
    Graph graph;
    for (int i = 0; i < 50; i++) {
        graph.addVertex(i);
    }
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 25; j++) {
            graph.addEdge(i, rand() % 50);
        }
    }
    graph.printGraph();
    graph.BFS(0);
    graph.DFS(0);
}