#include "hexagon.h"
#include "edge.h"
#include "vertex.h"
#include "unordered_map"
#include "vector"
#include "algorithm"

template<typename T1, typename T2, typename T3>
class HexagonGrid{
        std::unordered_map<Hexagon, T1, HexagonHash, HexagonEquals> hexagons;
        std::unordered_map<Edge, T2, EdgeHash, EdgeEquals> edges;
        std::unordered_map<Vertex, T3, VertexHash, VertexEquals> vertices;
    public:
        HexagonGrid();
        std::vector<Hexagon> neighbours(Hexagon);
        std::vector<Edge> borders(Hexagon);
        std::vector<Vertex> corners(Hexagon);
        std::vector<Hexagon> joins(Edge);
        std::vector<Edge> continues(Edge);
        std::vector<Vertex> endpoints(Edge);
        std::vector<Hexagon> touches(Vertex);
        std::vector<Edge> protrudes(Vertex);
        std::vector<Vertex> adjacent(Vertex);

};

template<typename T1, typename T2, typename T3>
std::vector<Hexagon> HexagonGrid<T1, T2, T3>::neighbours(Hexagon hex){
    std::vector<Hexagon> ret{hex.neighbours()};
    // Remove faces which are not part of the board
    std::remove_if(ret.begin, ret.end(), [](Hexagon h){return hexagons.find(h) == hexagons.end()})
    return ret;
}
template<typename T1, typename T2, typename T3>
std::vector<Edge> HexagonGrid<T1, T2, T3>::borders(Hexagon hex){
    std::vector<Edge> ret{hex.borders()};
    // Remove edges which are not part of the board
    std::remove_if(ret.begin, ret.end(), [](Edge e){return edges.find(e) == edges.end()})
    return ret;
}
template<typename T1, typename T2, typename T3>
std::vector<Vertex> HexagonGrid<T1, T2, T3>::corners(Hexagon hex){
    std::vector<Vertex> ret{hex.corners()};
    // Remove vertices which are not part of the board
    std::remove_if(ret.begin, ret.end(), [](Vertex v){return vertices.find(v) == vertices.end()})
    return ret;
}

template<typename T1, typename T2, typename T3>
std::vector<Hexagon> HexagonGrid<T1, T2, T3>::joins(Edge edge){
    std::vector<Hexagon> ret{edge.joins()};
    // Remove faces which are not part of the board
    std::remove_if(ret.begin, ret.end(), [](Hexagon h){return hexagons.find(h) == hexagons.end()})
    return ret;
}
template<typename T1, typename T2, typename T3>
std::vector<Edge> HexagonGrid<T1, T2, T3>::continues(Edge edge){
    std::vector<Edge> ret{edge.continues()};
    // Remove edges which are not part of the board
    std::remove_if(ret.begin, ret.end(), [](Edge e){return edges.find(e) == edges.end()})
    return ret;
}
template<typename T1, typename T2, typename T3>
std::vector<Vertex> HexagonGrid<T1, T2, T3>::endpoints(Edge edge){
    std::vector<Vertex> ret{edge.endpoints()};
    // Remove vertices which are not part of the board
    std::remove_if(ret.begin, ret.end(), [](Vertex v){return vertices.find(v) == vertices.end()})
    return ret;
}

template<typename T1, typename T2, typename T3>
std::vector<Hexagon> HexagonGrid<T1, T2, T3>::touches(Vertex vertex){
    std::vector<Hexagon> ret{vertex.touches()};
    // Remove faces which are not part of the board
    std::remove_if(ret.begin, ret.end(), [](Hexagon h){return hexagons.find(h) == hexagons.end()})
    return ret;
}
template<typename T1, typename T2, typename T3>
std::vector<Edge> HexagonGrid<T1, T2, T3>::protrudes(Vertex vertex){
    std::vector<Edge> ret{vertex.protrudes()};
    // Remove edges which are not part of the board
    std::remove_if(ret.begin, ret.end(), [](Edge e){return edges.find(e) == edges.end()})
    return ret;
}
template<typename T1, typename T2, typename T3>
std::vector<Vertex> HexagonGrid<T1, T2, T3>::adjacent(Vertex vertex){
    std::vector<Vertex> ret{vertex.adjacent()};
    // Remove vertices which are not part of the board
    std::remove_if(ret.begin, ret.end(), [](Vertex v){return vertices.find(v) == vertices.end()})
    return ret;
}