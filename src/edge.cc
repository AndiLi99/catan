#include "hexagonGrid/edge.h"
#include "hexagonGrid/hexagon.h"
#include "hexagonGrid/vertex.h"
#include "hexagonGrid/side.h"
#include "hexagonGrid/corner.h"
#include <vector>
#include <iostream>

Edge::Edge(int a, int b, Side s): a{a}, b{b}, s{s} {}

bool Edge::operator==(const Edge& other){
    return (a == other.a && b == other.b && s == other.s);
}

bool Edge::operator!=(const Edge& other){
    return !(*this == other);
}
std::ostream& operator<<(std::ostream& out, const Edge& edge){
    out << "Edge(" << edge.a << ", " << edge.b << ", " << edge.s << ")" << std::endl;
}

/*
    @todo: finish implementing
    
 */
std::vector<Hexagon> Edge::joins(){
    return std::vector<Hexagon>{};
}

std::vector<Edge> Edge::continues(){
    return std::vector<Edge>{};
}

std::vector<Vertex> Edge::endpoints(){
    return std::vector<Vertex>{};
}

