#include "graph.h"
#include <iostream>
#include "../queue/queue.h"
using namespace std;

void Graph::printGraph() {
    for (auto &vertex : vertices) {
        cout << "Vertex " << vertex->getVertex() << " is adjacent to Vertex: ";
        for (auto &adjVertex : vertex->getAdjVertex()) {
            cout << adjVertex->getVertex() << " ";
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
                if (adjVertex->getVertex() == dest) return;
            }
            Vertex *v;
            for (auto &destVertex : vertices) {
                if (destVertex->getVertex() == dest) {
                    v = destVertex;
                    break;
                }
            }
            vertex->addEdge(v);
        }
    }
}

Graph::~Graph() {
    for (auto &vertex : vertices) {
        delete vertex;
    }
}

Vertex *Graph::getVertex(int v) {
    for (auto &vertex : vertices) {
        if (vertex->getVertex() == v) {
            return vertex;
        }
    }
    return nullptr;
}

void Graph::BFS(int v) {
    Vertex *root = getVertex(v);
    if (!root) return;
    Queue<Vertex *> queue(1000);
    queue.enqueue(root);
    cout << "BFS Printing starting at: " << v << endl;
    int n = vertices.size();
    bool visited[n] = {};
    while (!queue.isEmpty()) {
        Vertex *cur = queue.dequeue();
        int vertex = cur->getVertex();
        if (visited[vertex]) continue;
        visited[vertex] = true;
        cout << vertex << " ";
        for (auto &adjVertex : cur->getAdjVertex()) {
            queue.enqueue(adjVertex);
        }
    }
    cout << endl;
}

void DFSHelper(Vertex *vertex, bool *visited) {
    int v = vertex->getVertex();
    if (visited[v]) return;
    visited[v] = true;
    cout << v << " ";
    for (auto &adjVertex : vertex->getAdjVertex()) {
        DFSHelper(adjVertex, visited);
    }
}

void Graph::DFS(int v) {
    Vertex *root = getVertex(v);
    if (!root) return;
    cout << "DFS Printing starting at: " << v << endl;
    int n = vertices.size();
    bool visited[n] = {};
    DFSHelper(root, visited);
    cout << endl;
}