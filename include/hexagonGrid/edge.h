#ifndef EDGE
#define EDGE

#include "hexagon.h"
#include "vertex.h"
enum class Side{W, N, E};

struct Edge {
	int a;
	int b;
	Side s;
	Edge(int a, int b, Side s): a{a}, b{b}, s{s} {}
  bool operator==(const Edge);
  bool operator!=(const Edge);
  std::vector<Hexagon> joins();
  std::vector<Edge> continues();
  std::vector<Vertex> endpoints();
};

//https://stackoverflow.com/questions/16792751/hashmap-for-2d3d-coordinates-i-e-vector-of-doubles
struct EdgeHash{
    size_t operator()(const Edge &e) const{
    size_t h1 = std::hash<int>()(e.a);
    size_t h2 = std::hash<int>()(e.b);
    size_t h3 = std::hash<Side>()(e.s);
    return (h1 ^ (h2 << 1)) ^ h3;
    }
};

struct EdgeEquals{
  bool operator()( const Edge& lhs, const Edge& rhs ) const{
    return (lhs.a == rhs.a) && (lhs.b == rhs.b) && (lhs.s == rhs.s);
  }
};

#endif
