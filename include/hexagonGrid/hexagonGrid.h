#include "hexagon.h"
#include "edge.h"
#include "vertex.h"
#include "unordered_map"
#include "vector"

template<class T1, class T2, class T3>
class HexagonGrid{
        std::unordered_map<Hexagon, T1> hexagons;
        std::unordered_map<Edge, T2> edges;
        std::unordered_map<Vertex, T3> vertices;
    public:
        HexagonGrid(size_t radius);
        std::vector<Hexagon> neighbours(const& Hexagon);
        std::vector<Edge> borders(const& Hexagon);
        std::vector<Vertex> corners(const& Hexagon);
        std::vector<Hexagon> joins(const& Edge);
        std::vector<Edge> continues(const& Edge);
        std::vector<Vertex> endpoints(const& Edge);
        std::vector<Hexagon> touches(const& Vertex);
        std::vector<Edge> protrudes(const& Vertex);
        std::vector<Vertex> adjacent(const& Vertex);

};