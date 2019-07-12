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
            Edge{a, b-1, Side::E},
            Edge{a+1, b, Side::W},
        };
        case Side::E: return std::vector<Edge>{
            Edge{a, b, Side::N},
            Edge{a, b+1, Side::W},
            Edge{a, b+1, Side::N},
            Edge{a+1, b, Side::W},
        };
        case Side::W: return std::vector<Edge>{
            Edge{a, b, Side::N},
            Edge{a-1, b, Side::E},
            Edge{a-1, b, Side::N},
            Edge{a, b-1, Side::E},
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

