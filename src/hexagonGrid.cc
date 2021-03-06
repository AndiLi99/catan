#include "hexagonGrid.h"
#include <vector>
#include <queue>

HexagonGrid::HexagonGrid(int radius): radius{radius}{
    std::vector<Hexagon> hexes = getPointyTopHexOrder(radius);
    validHexagons.insert(hexes.begin(), hexes.end());

    for (Hexagon hex: validHexagons){
        std::vector<Edge> edges = hex.borders();
        validEdges.insert(edges.begin(), edges.end());
    }
    for (Hexagon hex: validHexagons){
        std::vector<Vertex> vertices = hex.corners();
        validVertices.insert(vertices.begin(), vertices.end());
    }
}

std::vector<Hexagon> HexagonGrid::getPointyTopHexOrder(int radius){
    std::vector<Hexagon> results;
    for (int z = -radius; z <=radius; ++z){
        for (int x = std::max(-radius, -z-radius); x <= std::min(radius, -z+radius); ++x){
            int y = -z-x;
            results.emplace_back(Hexagon(x, y, z));
        }
    }
    return results;
}

std::vector<Vertex> HexagonGrid::getPointyTopVertexOrder(int radius){
    std::vector<Hexagon> hexes = getPointyTopHexOrder(radius+1);
    std::deque<Vertex> verticesR;
    std::deque<Vertex> verticesL;
    for (Hexagon hex: hexes){
        Vertex v1 = hex.corner(Corner::R);
        if (validVertices.find(v1) != validVertices.end()){
            verticesR.push_back(v1);
        }
        Vertex v2 = hex.corner(Corner::L);
        if (validVertices.find(v2) != validVertices.end()){
            verticesL.push_back(v2);
        }
    }
    std::vector<Vertex> ret;
    int width = radius+1;
    bool up = true;
    Corner c = Corner::L;
    do {
        switch (c){
            case Corner::L:
                for (int i = 0; i < width; ++i){
                    ret.push_back(verticesL.front());
                    verticesL.pop_front();
                }
                if (width == (radius+1)*2){
                    up = false;
                }
                up? ++width: --width;
                c = Corner::R;
            break;
            case Corner::R:
                for (int i = 0; i < width; ++i){
                    ret.push_back(verticesR.front());
                    verticesR.pop_front();
                }
                c = Corner::L;
            break;
            
        }
    } while(!(width == 3 && c == Corner::L));
    return ret;
}

std::vector<Edge> HexagonGrid::getPointyTopEdgeOrder(int radius){
    std::vector<Hexagon> hexes = getPointyTopHexOrder(radius+1);
    std::deque<Edge> edgesW;
    std::deque<Edge> edgesNE;
    for (Hexagon hex: hexes){
        Edge e1 = hex.border(Side::W);
        if (validEdges.find(e1) != validEdges.end()){
            edgesW.push_back(e1);
        }
        Edge e2 = hex.border(Side::N);
        if (validEdges.find(e2) != validEdges.end()){
            edgesNE.push_back(e2);
        }
        Edge e3 = hex.border(Side::E);
        if (validEdges.find(e3) != validEdges.end()){
            edgesNE.push_back(e3);
        }
    }
    std::vector<Edge> ret;
    int width = radius+1;
    bool up = true;
    bool vertical_road = false;
    do {
        if (vertical_road)
        {
            for (int i = 0; i < width; ++i){
                ret.push_back(edgesW.front());
                edgesW.pop_front();
            }
            if (width == (radius+1)*2){
                up = false;
            }
            if (!up) --width; 
            vertical_road = !vertical_road;
        }
        else
        {
            for (int i = 0; i < width*2; ++i){
                ret.push_back(edgesNE.front());
                edgesNE.pop_front();
            }
            if (up) ++width;
            vertical_road = !vertical_road;
        } 
    } while(!(width == 3 && vertical_road));
    return ret;
}

std::vector<Hexagon> HexagonGrid::getHexPrintOrder(){
    return getPointyTopHexOrder(radius);
}
std::vector<Edge> HexagonGrid::getEdgePrintOrder(){
    return getPointyTopEdgeOrder(radius);
}
std::vector<Vertex> HexagonGrid::getVertexPrintOrder(){
    return getPointyTopVertexOrder(radius);
}

const Tile& HexagonGrid::cgetTile(Hexagon hex){
    return getTile(hex);
}
const Road& HexagonGrid::cgetRoad(Edge edge){
    return getRoad(edge);
}
const Settlement& HexagonGrid::cgetSettlement(Vertex vertex){
    return getSettlement(vertex);
}
Tile& HexagonGrid::getTile(Hexagon hex){
    return tiles.at(hex);
}
Road& HexagonGrid::getRoad(Edge edge){
    return roads.at(edge);
}
Settlement& HexagonGrid::getSettlement(Vertex vertex){
    return settlements.at(vertex);
}
bool HexagonGrid::emptyEdge(Edge edge){
    return roads.find(edge) == roads.end();
}
bool HexagonGrid::emptyVertex(Vertex vert){
    return settlements.find(vert) == settlements.end();
}
bool HexagonGrid::emptyHexagon(Hexagon hex){
    return tiles.find(hex) == tiles.end();
}

void HexagonGrid::addTile(Hexagon hex, Tile tile){
    tiles.insert_or_assign(hex, tile);
}
void HexagonGrid::addRoad(Edge edge, Road road){
    roads.insert_or_assign(edge, road);
}
void HexagonGrid::addSettlement(Vertex vertex, Settlement settlement){
    settlements.insert_or_assign(vertex, settlement);
}
void HexagonGrid::upgradeSettlement(Vertex vertex){
    if (!emptyVertex(vertex)){
        settlements.at(vertex).upgradeToCity();
    }
}
std::vector<Edge> HexagonGrid::getRoads(int playerID){
    std::vector<Edge> ret;
    for (auto pair: roads){
        if (pair.second.ownedBy() == playerID) ret.push_back(pair.first);
    }
    return ret;
}
std::vector<Vertex> HexagonGrid::getSettlements(int playerID){
    std::vector<Vertex> ret;
    for (auto pair: settlements){
        if (pair.second.ownedBy() == playerID) ret.push_back(pair.first);
    }
    return ret;
}

std::vector<Edge> HexagonGrid::adjacentEmptyRoads(int playerID){
    std::vector<Edge> ret;
    std::vector<Vertex> stack = getSettlements(playerID);
    VertexSet visitedVertices;
    EdgeSet visitedEdges;

    while(stack.size()){
        Vertex v = stack.back(); 
        stack.pop_back();

        if (visitedVertices.find(v) == visitedVertices.end()){
            visitedVertices.insert(v);
            if (emptyVertex(v) || cgetSettlement(v).ownedBy() == playerID){
                for (Edge e: v.protrudes()){
                    if (visitedEdges.find(e) == visitedEdges.end())
                    {
                        visitedEdges.insert(e);
                        if (emptyEdge(e))
                        {
                            ret.push_back(e);
                        }
                        else if (cgetRoad(e).ownedBy() == playerID)
                        {
                            stack.insert(stack.end(), e.endpoints().begin(), e.endpoints().end());
                        }
                    }
                }
            }
        }
    }
    return ret;
}
std::vector<Vertex> HexagonGrid::adjacentEmptySettlements(int playerID){
    std::vector<Vertex> ret;
    std::vector<Vertex> stack = getSettlements(playerID);
    VertexSet visitedVertices;
    EdgeSet visitedEdges;

    while(stack.size()){
        Vertex v = stack.back(); 
        stack.pop_back();

        if (visitedVertices.find(v) == visitedVertices.end()){
            visitedVertices.insert(v);
            if (emptyVertex(v) || cgetSettlement(v).ownedBy() == playerID){
                for (Edge e: v.protrudes()){
                    if (visitedEdges.find(e) == visitedEdges.end())
                    {
                        visitedEdges.insert(e);
                        if (cgetRoad(e).ownedBy() == playerID)
                        {
                            stack.insert(stack.end(), e.endpoints().begin(), e.endpoints().end());
                        }
                    }
                }
            }
            if (emptyVertex(v))
            {
                ret.push_back(v);
            }
        }
    }
    return ret;
}