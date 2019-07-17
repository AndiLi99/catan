#include "gameState.h"

GameState::GameState(Board board, std::vector<Player> players): board{board}, players{players}{}
GameState::~GameState(){}

void GameState::buildSettlement(Vertex vertex){
    
}
void GameState::buildCity(Vertex vertex){
    
}
void GameState::buildRoad(Edge edge){
    notifyObservers();
}
void GameState::purchaseSettlement(){
    
}
void GameState::purchaseCity(){
    
}
void GameState::purchaseRoad(){
    
}
void GameState::rollDice(){
    
}
void GameState::endTurn(){
    
}

std::vector<Edge> GameState::getEdgePrintOrder(){
    return board.getEdgePrintOrder();
}
std::vector<Hexagon> GameState::getHexPrintOrder(){
    return board.getHexPrintOrder();
}
std::vector<Vertex> GameState::getVertexPrintOrder(){
    return board.getVertexPrintOrder();
}
const Tile& GameState::cgetTile(Hexagon hex){
    return board.cgetTile(hex);
}
const Road& GameState::cgetRoad(Edge edge){
    return board.cgetRoad(edge);
}
const Settlement& GameState::cgetSettlement(Vertex vertex){
    return board.cgetSettlement(vertex);
}
bool GameState::emptyEdge(Edge edge){
    return board.emptyEdge(edge);
}
bool GameState::emptyVertex(Vertex vert){
    return board.emptyVertex(vert);
}
