#include "graph.h"
#include <iostream>
using namespace std;

void Graph::printGraph() {
    for (auto &vertex : vertices) {
        cout << "Vertex " << vertex->getVertex() << " is adjacent to Vertex: ";
        for (auto &adjVertex : vertex->getAdjVertex()) {
            cout << adjVertex.getVertex() << " ";
        }
        cout << endl;
    }
}

void Graph::addVertex(int v) {
    for (auto &vertex : vertices) {
        if (vertex->getVertex() == v) return;
    }
    vertices.push_back(new Vertex(v));
}

void Graph::addEdge(int src, int dest) {
    for (auto &vertex : vertices) {
        if (vertex->getVertex() == src) {
            for (auto &adjVertex : vertex->getAdjVertex()) {
                if (adjVertex.getVertex() == dest) return;
            }
            Vertex *v;
            for (auto &destVertex : vertices) {
                if (destVertex->getVertex() == dest) {
                    v = destVertex;
                    break;
                }
            }
            vertex->addEdge(*v);
        }
    }
}

Graph::~Graph() {
    for (auto &vertex : vertices) {
        delete vertex;
    }
}