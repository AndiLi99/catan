#include <iostream>
#include "hexagonGrid/edge.h"
#include "hexagonGrid/hexagon.h"
#include "hexagonGrid/vertex.h"
#include "hexagonGrid.h"

void complain(const char* name){
    std::cout << "Test failed: " << name << std::endl;
}

void equal_hex(const char* name, Hexagon hex1, Hexagon hex2){
    if (!(hex1.a == hex2.a && hex1.b == hex2.b)){
        complain(name);
    }
}

void equal_int(const char* name, int a, int b){
    if (a != b) complain(name);
}
void equal_edge(const char* name, Edge e1, Edge e2){
    if (!(e1.a == e2.a && e1.b == e2.b && e1.s == e2.s)){
        complain(name);
    }
}

void equal_vertex(const char* name, Vertex v1, Vertex v2){
    if (!(v1.a == v2.a && v1.b == v2.b && v1.c == v2.c)){
        complain(name);
    }
}

void test_hex_math(){
    equal_hex("hex_add_1", Hexagon(1,2) + Hexagon(2, 3), Hexagon(3,5));
    equal_hex("hex_subtract_1", Hexagon(2, 3) - Hexagon(5,5), Hexagon(-3,-2));
    equal_hex("hex_multiply_1", Hexagon(3,1) * 4, Hexagon(12,4));
}

void test_hex_equals(){
    if (Hexagon(2,3) != Hexagon(2,3)){
        complain("hex_inequality");
    }
    if (Hexagon(1,1) == Hexagon (0,1)){
        complain("hex_equality");
    }
}

void test_edge_equals(){
    if (Edge(2,3, Side::W) != Edge(2,3, Side::W)){
        complain("edge_inequality");
    }
    if (Edge(1,1, Side::W) == Edge (0,1, Side::W)){
        complain("edge_equality_1");
    }
    if (Edge(1,1, Side::W) == Edge (1,1, Side::N)){
        complain("edge_equality_2");
    }
}

void test_vertex_equals(){
    if (Vertex(2,3, Corner::L) != Vertex(2,3, Corner::L)){
        complain("Vertex_inequality");
    }
    if (Vertex(1,1, Corner::L) == Vertex (0,1, Corner::L)){
        complain("Vertex_equality_1");
    }
    if (Vertex(1,1, Corner::R) == Vertex (1,1, Corner::L)){
        complain("Vertex_equality_2");
    }
}

void test_hex_directions(){
    equal_hex("hex_direction_0", Hexagon(1,0), Hexagon::hex_direction(0));
    equal_hex("hex_direction_1", Hexagon(1,-1), Hexagon::hex_direction(1));
    equal_hex("hex_direction_2", Hexagon(0,-1), Hexagon::hex_direction(2));
    equal_hex("hex_direction_3", Hexagon(-1,0), Hexagon::hex_direction(3));
    equal_hex("hex_direction_4", Hexagon(-1,1), Hexagon::hex_direction(4));
    equal_hex("hex_direction_5", Hexagon(0,1), Hexagon::hex_direction(5));
}

void test_hex_neighbour(){
    equal_hex("hex_neighbour", Hexagon(1,-1), Hexagon(1,-2).neighbour(5).neighbour(2).neighbour(5));
    equal_hex("hex_neighbour_1", Hexagon(4,3), Hexagon(1,1) + 3 * Hexagon::hex_direction(0) + 2*Hexagon::hex_direction(5));
}

void test_hex_length(){
    equal_int("hex_length", 2, Hexagon(2,-1).length());
}

void print_relationships(){
    std::cout << "Testing Hexagon neighbours" << std::endl;
    for (Hexagon h: Hexagon(0,0).neighbours()){
        std::cout << h;
    }
    std::cout << "Testing Hexagon borders" << std::endl;
    for (Edge h: Hexagon(0,0).borders()){
        std::cout << h;
    }
    std::cout << "Testing Hexagon corners" << std::endl;
    for (Vertex h: Hexagon(0,0).corners()){
        std::cout << h;
    }
    std::cout << "Testing Edge joins" << std::endl;
    for (Hexagon h: Edge(0,0, Side::N).joins()){
        std::cout << h;
    }
    std::cout << "Testing Edge continues" << std::endl;
    for (Edge h: Edge(0,0, Side::N).continues()){
        std::cout << h;
    }
    std::cout << "Testing Edge endpoints" << std::endl;
    for (Vertex h: Edge(0,0, Side::N).endpoints()){
        std::cout << h;
    }
    std::cout << "Testing Vertex touches" << std::endl;
    for (Hexagon h: Vertex(0,0, Corner::R).touches()){
        std::cout << h;
    }
    std::cout << "Testing Vertex protrudes" << std::endl;
    for (Edge h: Vertex(0,0, Corner::R).protrudes()){
        std::cout << h;
    }
    std::cout << "Testing Vertex adjacent" << std::endl;
    for (Vertex h: Vertex(0,0, Corner::R).adjacent()){
        std::cout << h;
    }
}
void printHexVect(std::vector<Hexagon> vect){
    for (Hexagon h: vect){
        std::cout << h;
    }
}
void printVertVect(std::vector<Vertex> vect){
    for (Vertex h: vect){
        std::cout << h;
    }
}
void test_hexagon_gen(){
    HexagonGrid hexagonGrid(2);
    std::vector<Hexagon> vect = hexagonGrid.getPointyTopHexOrder(2);
    printHexVect(vect);
}
void test_vertex_gen(){
    HexagonGrid hexagonGrid(2);
    std::vector<Vertex> vect = hexagonGrid.getPointyTopVertexOrder(2);
    printVertVect(vect);
    std::cout << vect.size() << std::endl;
}


void test_all(){
    test_hex_equals();
    test_hex_directions();
    test_hex_math();
    test_hex_neighbour();
    test_hex_length();
    test_edge_equals();
    test_vertex_equals();
    test_hexagon_gen();
    test_vertex_gen();
}

/*
int main(){
    test_all();
}
*/