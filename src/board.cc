#include "board.h"

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