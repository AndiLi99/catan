#ifndef HEXAGON
#define HEXAGON
#include "edge.h"
#include "vertex.h"

struct Hexagon {
	int a;
	int b;
	Hexagon(int a, int b): a{a}, b{b}{}
  bool operator==(const Hexagon);
  bool operator!=(const Hexagon);
  Hexagon operator+(const Hexagon);
  Hexagon operator-(const Hexagon);
  Hexagon operator*(const Hexagon);
  int length();
  std::vector<Hexagon> neighbours();
  std::vector<Edge> borders();
  std::vector<Vertex> corners();
};

//https://stackoverflow.com/questions/16792751/hashmap-for-2d3d-coordinates-i-e-vector-of-doubles
struct HexagonHash{
    size_t operator()(const Hexagon &h) const{
    size_t h1 = std::hash<int>()(h.a);
    size_t h2 = std::hash<int>()(h.b);
    return (h1 ^ (h2 << 1));
    }
};

struct HexagonEquals{
  bool operator()( const Hexagon& lhs, const Hexagon& rhs ) const{
    return (lhs.a == rhs.a) && (lhs.b == rhs.b);
  }
};

#endif
