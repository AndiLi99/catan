#include "hexagonGrid/edge.h"
#include "hexagonGrid/hexagon.h"
#include "hexagonGrid/vertex.h"
#include "hexagonGrid/side.h"
#include "hexagonGrid/corner.h"
#include <vector>
#include <iostream>

Vertex::Vertex(int a, int b, Corner c): a{a}, b{b}, c{c} {}

bool Vertex::operator==(const Vertex& other){
    return a == other.a && b == other.b && c == other.c;
}

bool Vertex::operator!=(const Vertex& other){
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Vertex& vertex){
    return out << "Vertex(" << vertex.a << ", " << vertex.b << ", " << vertex.c << ")" << std::endl;
}

std::vector<Hexagon> Vertex::touches(){
    switch (c){
        case Corner::L: return std::vector<Hexagon> {
            Hexagon{a, b},
            Hexagon{a-1, b},
            Hexagon{a-1, b+1}
        };
        case Corner::R: return std::vector<Hexagon> {
            Hexagon{a, b},
            Hexagon{a+1, b},
            Hexagon{a+1, b-1}
        };
    }
    
}
std::vector<Edge> Vertex::protrudes(){
    switch (c){
        case Corner::L: return std::vector<Edge> {
            Edge{a, b, Side::W},
            Edge{a-1, b, Side::E},
            Edge{a-1, b, Side::N}
        };
        case Corner::R: return std::vector<Edge> {
            Edge{a, b, Side::E},
            Edge{a+1, b-1, Side::W},
            Edge{a+1, b-1, Side::N}
        };
    }
}
std::vector<Vertex> Vertex::adjacent(){
        switch (c){
        case Corner::L: return std::vector<Vertex> {
            Vertex{a-1, b+1, Corner::R},
            Vertex{a-1, b, Corner::R},
            Vertex{a-2, b+1, Corner::R}
        };
        case Corner::R: return std::vector<Vertex> {
            Vertex{a+2, b-1, Corner::L},
            Vertex{a+1, b, Corner::L},
            Vertex{a+1, b-1, Corner::L}
        };
    }
}