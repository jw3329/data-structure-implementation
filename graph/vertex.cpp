#include "vertex.h"

Vertex::Vertex(int v) { this->v = v; }

int Vertex::getVertex() { return v; }

std::vector<Vertex> Vertex::getAdjVertex() { return adjVertex; }

void Vertex::addEdge(Vertex dest) {
    for (auto &vertex : adjVertex) {
        if (vertex.v == dest.v) return;
    }
    adjVertex.push_back(dest);
}