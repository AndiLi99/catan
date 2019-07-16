#include "hexagonGrid/hexagon.h"
#include "hexagonGrid/edge.h"
#include "hexagonGrid/vertex.h"
#include "helpers.h"
#include "hexagonGrid/side.h"
#include "hexagonGrid/corner.h"
#include <cmath>
#include <vector>

const Hexagon Hexagon::HEX_DIRECTION[6] = {
    Hexagon {1,0},
    Hexagon {1,-1},
    Hexagon {0,-1},
    Hexagon {-1,0},
    Hexagon {-1,1},
    Hexagon {0,1}};

Hexagon::Hexagon(int a, int b): a{a}, b{b}, c{-a-b} {}

Hexagon Hexagon::hex_direction(int direction){
    return Hexagon::HEX_DIRECTION[positive_modulo(direction, 6)];
}

Hexagon Hexagon::neighbour(int direction){
    return *this + Hexagon::hex_direction(direction);
}

Edge Hexagon::border(Side s){
    return Edge{a, b, s};
}

Vertex Hexagon::corner(Corner c){
    return Vertex{a, b, c};
}

/*
    @returns: This function returns a vector of Hexagon which are neighbours of this Hexagon    
 */
std::vector<Hexagon> Hexagon::neighbours(){
    std::vector<Hexagon> ret;
    for (int i = 0; i < 6; ++i){
        ret.emplace_back(neighbour(i));
    }
    return ret;
}

/*
    @returns: This function returns a vector of Edges which border this Hexagon
 */
std::vector<Edge> Hexagon::borders(){
    return std::vector<Edge>
    {
        border(Side::W),
        border(Side::N),
        border(Side::E),
        neighbour(1).border(Side::W),
        neighbour(2).border(Side::N),
        neighbour(3).border(Side::E)
    };
}

/*
    @returns: This function returns a vector of Vertex which are vertices of this hexagon
 */
std::vector<Vertex> Hexagon::corners(){
    return std::vector<Vertex>
    {
        corner(Corner::L),
        corner(Corner::R),
        neighbour(4).corner(Corner::R),
        neighbour(0).corner(Corner::L),
        neighbour(3).corner(Corner::R),
        neighbour(1).corner(Corner::L)
        };
}

Hexagon Hexagon::operator+(const Hexagon& other){
    return Hexagon{a+other.a, b+other.b};
}

Hexagon Hexagon::operator-(const Hexagon& other){
    return Hexagon{a-other.a, b-other.b};
}

Hexagon Hexagon::operator*(int factor){
    return Hexagon{a*factor, b*factor};
}

bool Hexagon::operator==(const Hexagon& other){
    return a == other.a && b == other.b;
}

bool Hexagon::operator!=(const Hexagon& other){
    return !(*this == other);
}

int Hexagon::length(){
    return int((std::abs(a) + std::abs(b) + std::abs(c))/2);
}

Hexagon operator*(int factor, const Hexagon& hex){
    return Hexagon{hex.a*factor, hex.b*factor};
}

std::ostream& operator<<(std::ostream& out, const Hexagon& hex){
    return out << "Hex(" << hex.a << ", " << hex.b << ")" << std::endl;
}