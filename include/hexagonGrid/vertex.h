#ifndef VERTEX
#define VERTEX

#include <vector>
#include "corner.h"

class Hexagon;
class Edge;

class Vertex{
  public:
    int a;
    int b;
    Corner c;
    Vertex(int a, int b, Corner c): a{a}, b{b}, c{c} {}
    bool operator==(const Vertex);
    bool operator!=(const Vertex);
    std::vector<Hexagon> touches();
    std::vector<Edge> protrudes();
    std::vector<Vertex> adjacent();
};

//https://stackoverflow.com/questions/16792751/hashmap-for-2d3d-coordinates-i-e-vector-of-doubles
struct VertexHash{
    size_t operator()(const Vertex &v) const{
    size_t h1 = std::hash<int>()(v.a);
    size_t h2 = std::hash<int>()(v.b);
    size_t h3 = std::hash<Corner>()(v.c);
    return (h1 ^ (h2 << 1)) ^ h3;
    }
};

struct VertexEquals{
  bool operator()( const Vertex& lhs, const Vertex& rhs ) const{
    return (lhs.a == rhs.a) && (lhs.b == rhs.b) && (lhs.c == rhs.c);
  }
};

#endif
