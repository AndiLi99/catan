#include "gameState.h"

GameState::GameState(Board board, std::vector<Player> players, DiceRoll dice): 
board{board}, players{players}, dice{dice}{
    turnPlayer = 1;
}
GameState::~GameState(){}

int GameState::indexFromPlayerID(int playerID){
    return playerID -1;
}
void GameState::buildSettlement(Vertex vertex){
    board.addSettlement(vertex, turnPlayer);
}
void GameState::buildCity(Vertex vertex){
    board.upgradeSettlement(vertex);
}
void GameState::buildRoad(Edge edge){
    board.addRoad(edge, turnPlayer);
}
void GameState::purchaseSettlement(){
    
}
void GameState::purchaseCity(){
    
}
void GameState::purchaseRoad(){
    
}

void GameState::moveRobber(Hexagon hex){

}
Resource GameState::stealResource(int playerID){

}
void GameState::rollDice(){
    
}
void GameState::endTurn(){
    ++turnPlayer;
    if (turnPlayer > players.size()){
        turnPlayer -= players.size();
    }
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
