#if !defined(VERTEX_H)
#define VERTEX_H

#include <vector>

class Vertex {
   private:
    int v;
    std::vector<Vertex *> adjVertex;

   public:
    Vertex(int v);
    int getVertex();
    std::vector<Vertex *> getAdjVertex();
    void addEdge(Vertex *dest);
};

#endif  // VERTEX_H
