#include "board.h"
#include "resourceArray.h"

Board::Board(HexagonGrid hexGrid): hexGrid{hexGrid}{}

void Board::addSettlement(Vertex vertex, int playerID){
    hexGrid.addSettlement(vertex, Settlement{playerID});
}

void Board::upgradeSettlement(Vertex vertex){
    hexGrid.upgradeSettlement(vertex);
}

void Board::addRoad(Edge edge, int playerID){
    hexGrid.addRoad(edge, Road{playerID});
}

std::vector<Edge> Board::getEdgePrintOrder(){
    return hexGrid.getEdgePrintOrder();
}
std::vector<Hexagon> Board::getHexPrintOrder(){
    return hexGrid.getHexPrintOrder();
}
std::vector<Vertex> Board::getVertexPrintOrder(){
    return hexGrid.getVertexPrintOrder();
}
const Tile& Board::cgetTile(Hexagon hex){
    return hexGrid.cgetTile(hex);
}
const Road& Board::cgetRoad(Edge edge){
    return hexGrid.cgetRoad(edge);
}
const Settlement& Board::cgetSettlement(Vertex vertex){
    return hexGrid.cgetSettlement(vertex);
}
bool Board::emptyEdge(Edge edge){
    return hexGrid.emptyEdge(edge);
}
bool Board::emptyVertex(Vertex vert){
    return hexGrid.emptyVertex(vert);
}
bool Board::emptyHexagon(Hexagon hex){
    return hexGrid.emptyHexagon(hex);
}

std::vector<std::vector<int>> Board::produceResources(int roll, int numPlayers){
    std::vector<std::vector<int>> ret;
    for (int i = 0; i < numPlayers; ++i){
        ret.push_back(std::vector<int>{0,0,0,0,0});
    }

    std::vector<Hexagon> hexagons = hexGrid.getHexPrintOrder();
    for (Hexagon hex: hexagons){
        if (robber != hex && hexGrid.cgetTile(hex).getRollNumber() == roll){
            const Tile& tile = hexGrid.cgetTile(hex);
            for (Vertex vert: hex.corners()){
                if (!hexGrid.emptyVertex(vert)){
                    int playerID = hexGrid.cgetSettlement(vert).ownedBy();
                    int prodRate = hexGrid.cgetSettlement(vert).getProductionRate();
                    int index = playerID -1;
                    switch(tile.getType()){
                        case TileType::Forest: ret[index][0] += prodRate;
                        break;
                        case TileType::Hills: ret[index][1] += prodRate;
                        break;
                        case TileType::Fields: ret[index][2] += prodRate;
                        break;
                        case TileType::Pasture: ret[index][3] += prodRate;
                        break;
                        case TileType::Mountains: ret[index][4] += prodRate;
                        break;
                        case TileType::Desert: break;

                    }
                }
            }
        }
    }
    return ret;
}
std::vector<int> Board::moveRobber(Hexagon hex){
    robber = hex;
    std::vector<Vertex> vertices = hex.corners();
    std::vector<int> ret;
    for (Vertex v: vertices){
        if (!hexGrid.emptyVertex(v)){
            ret.push_back(hexGrid.cgetSettlement(v).ownedBy());
        }
    }
    return ret;
}

std::optional<Hexagon> Board::getRobber(){
    return robber;
}

std::vector<Edge> Board::adjacentEmptyRoads(int playerID){
    return hexGrid.adjacentEmptyRoads(playerID);
}
std::vector<Vertex> Board::adjacentEmptySettlements(int playerID){
    return hexGrid.adjacentEmptySettlements(playerID);
}

std::vector<Edge> Board::getRoads(int playerID){
    return hexGrid.getRoads(playerID);
}
std::vector<Vertex> Board::getSettlements(int playerID){
    return hexGrid.getSettlements(playerID);
}
std::vector<int> Board::adjacentResources(Vertex vert){
    std::vector<int> ret{0,0,0,0,0};
    for (Hexagon hex: vert.touches()){
        if (!emptyHexagon(hex)){
            const Tile& tile = cgetTile(hex);
            switch(tile.getType()){
                case TileType::Forest: ++ret[0]; break;
                case TileType::Hills: ++ret[1]; break;
                case TileType::Fields: ++ret[2]; break;
                case TileType::Pasture: ++ret[3]; break;
                case TileType::Mountains: ++ret[4]; break;
                case TileType::Desert: break;
            }
        }
    }
    return ret;
}
bool Board::adjacentVerticesEmpty(Vertex vert){
    for (Vertex others: vert.adjacent()){
        if (!emptyVertex(others)) return false;
    }
    return true;
}
bool Board::canUpgrade(Vertex vertex, int playerID){
    return (!emptyVertex(vertex) && 
    cgetSettlement(vertex).ownedBy() == playerID &&
    !cgetSettlement(vertex).isCity()
    );
}