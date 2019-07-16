#include "hexagonGrid/edge.h"
#include "hexagonGrid/hexagon.h"
#include "hexagonGrid/vertex.h"
#include "hexagonGrid/side.h"
#include "hexagonGrid/corner.h"
#include <vector>
#include <iostream>

Edge::Edge(int a, int b, Side s): a{a}, b{b}, s{s} {}
Edge::Edge(Hexagon hex, Side s): a{hex.a}, b{hex.b}, s{s} {}

bool Edge::operator==(const Edge& other){
    return (a == other.a && b == other.b && s == other.s);
}

bool Edge::operator!=(const Edge& other){
    return !(*this == other);
}
std::ostream& operator<<(std::ostream& out, const Edge& edge){
    return out << "Edge(" << edge.a << ", " << edge.b << ", " << edge.s << ")" << std::endl;
}

Hexagon Edge::hex(){
    return Hexagon{a, b};
}

/*
    @todo: finish implementing
    
 */
std::vector<Hexagon> Edge::joins(){
    switch(s){
        case Side::N: return std::vector<Hexagon>{
            Hexagon{a,b},
            Hexagon{a,b+1}
        };
        case Side::E: return std::vector<Hexagon>{
            Hexagon{a,b},
            Hexagon{a+1,b}
        };
        case Side::W: return std::vector<Hexagon>{
            Hexagon{a,b},
            Hexagon{a-1,b+1}
        };
    }
}

std::vector<Edge> Edge::continues(){
    switch(s){
        case Side::N: return std::vector<Edge>{
            Edge{a, b, Side::W},
            Edge{a, b, Side::E},
            Edge{hex().neighbour(4), Side::E},
            Edge{hex().neighbour(0), Side::W},
        };
        case Side::E: return std::vector<Edge>{
            Edge{a, b, Side::N},
            Edge{hex().neighbour(1), Side::W},
            Edge{hex().neighbour(0), Side::W},
            Edge{hex().neighbour(1), Side::N},
        };
        case Side::W: return std::vector<Edge>{
            Edge{a, b, Side::N},
            Edge{hex().neighbour(3), Side::E},
            Edge{hex().neighbour(3), Side::N},
            Edge{hex().neighbour(4), Side::E},
        };
    }
    
}

std::vector<Vertex> Edge::endpoints(){
    switch(s){
        case Side::N: return std::vector<Vertex>{
            Vertex{a+1,b, Corner::L},
            Vertex{a-1,b+1, Corner::R}
        };
        case Side::E: return std::vector<Vertex>{
            Vertex{a,b, Corner::R},
            Vertex{a+1,b, Corner::L}
        };
        case Side::W: return std::vector<Vertex>{
            Vertex{a,b, Corner::L},
            Vertex{a-1,b+1, Corner::R}
        };
    }
}

