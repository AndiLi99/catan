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

/*
    @todo: finish implementing
 */
std::vector<Hexagon> Vertex::touches(){
    switch (c){
        case Corner::L: return std::vector<Hexagon> {
            Hexagon{a, b}
            // Hexagon{}}
        };
    }
    
}
std::vector<Edge> Vertex::protrudes(){

}
std::vector<Vertex> Vertex::adjacent(){}