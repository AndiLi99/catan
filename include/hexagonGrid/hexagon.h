#ifndef HEXAGON
#define HEXAGON
#include <vector>
#include <iostream>
#include "corner.h"
#include "side.h"
class Edge;
class Vertex;

class Hexagon {
  private:
    static const Hexagon HEX_DIRECTION[6];
  public:
    int a;
    int b;
    int c;
    Hexagon(int a, int b);
    Hexagon(int a, int b, int c);
    bool operator==(const Hexagon& other) const;
    bool operator!=(const Hexagon& other) const;
    Hexagon operator+(const Hexagon& other) const;
    Hexagon operator-(const Hexagon& other) const;
    Hexagon operator*(int factor) const;
    friend std::ostream& operator<<(std::ostream& out, const Hexagon& hex);
    friend Hexagon operator*(const int factor, const Hexagon& other);
    int length() const;
    std::vector<Hexagon> neighbours() const;
    std::vector<Edge> borders() const;
    std::vector<Vertex> corners() const;
    static Hexagon hex_direction(int direction);
    Hexagon neighbour(int direction) const;
    Edge border(Side side) const;
    Vertex corner(Corner corner) const;
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
