#include "board.h"

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