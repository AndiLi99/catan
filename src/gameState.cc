#include "gameState.h"
#include <algorithm>

GameState::GameState(Board board, std::vector<Player> players, DiceRoll dice): 
board{board}, players{players}, numPlayers{players.size()}, dice{dice}{
    turnPlayer = 1;
    rolled = false;
    canMoveRobber = false;
    lastRoll = 0;
}
GameState::~GameState(){}

int GameState::indexFromPlayerID(int playerID){
    return playerID -1;
}

Player& GameState::getPlayer(int playerID){
    return players[indexFromPlayerID(playerID)];
}
Player& GameState::getTurnPlayer(){
    return getPlayer(turnPlayer);
}
void GameState::buildSettlement(Vertex vertex){
    if (getTurnPlayer().canBuildSettlement()){
        getTurnPlayer().subtractSettlement();
        board.addSettlement(vertex, turnPlayer);
        getTurnPlayer().addVictoryPoints(1);
    }
}
void GameState::buildCity(Vertex vertex){
    if (getTurnPlayer().canBuildCity()){
        getTurnPlayer().subtractCity();
        board.upgradeSettlement(vertex);
        getTurnPlayer().addVictoryPoints(1);
    }
}
void GameState::buildRoad(Edge edge){
    if (getTurnPlayer().canBuildRoad()){
        getTurnPlayer().subtractRoad();
        board.addRoad(edge, turnPlayer);
    }
}
void GameState::purchaseSettlement(){
    if (getTurnPlayer().canPurchaseSettlement()){
        getTurnPlayer().subtractResources(Settlement::cost);
        getTurnPlayer().addSettlement();
    }
    
}
void GameState::purchaseCity(){
    if (getTurnPlayer().canPurchaseCity()){
        getTurnPlayer().subtractResources(Settlement::upgradeCost);
        getTurnPlayer().addCity();
    }
}
void GameState::purchaseRoad(){    
    if (getTurnPlayer().canPurchaseRoad()){
        getTurnPlayer().subtractResources(Road::cost);
        getTurnPlayer().addRoad();
    }
}

void GameState::moveRobber(Hexagon hex){
    if (canMoveRobber){
        stealablePlayers = board.moveRobber(hex);
        canMoveRobber = false;
    }
}
Resource GameState::stealResource(int playerID){
    if (std::find(stealablePlayers.begin(), stealablePlayers.end(), playerID) !=
    stealablePlayers.end()){
        if (getPlayer(playerID).handSize() > 0){
            Resource stolen = getPlayer(playerID).stealResource();
            getTurnPlayer().addResource(stolen);
        }
    }
}

int GameState::getVictoryPoints(){
    return getTurnPlayer().getVictoryPoints();
}
std::vector<int> GameState::getResources(){
    return getTurnPlayer().getResources();
}
std::vector<int> GameState::getUnbuilt(){
    return getTurnPlayer().getUnbuilt();
}
std::string GameState::getUsername(){
    return getTurnPlayer().getUsername();
}

void GameState::rollDice(){
    if (!rolled){
        lastRoll = dice.rollDice();
        rolled = true;
        if (lastRoll == 7){
            canMoveRobber = true;
        } else {
            getTurnPlayer().addResources({std::vector<int>{1,1,1,1,1}});
            std::vector<std::vector<int>> production = board.produceResources(lastRoll, numPlayers);
            for (int i=0;i<numPlayers;++i){
                players[i].addResources(production[i]);
            }
        }
    }
}

int GameState::getLastDiceRoll(){
    return lastRoll;
}

int GameState::getTurnPlayerID(){
    return turnPlayer;
}

bool GameState::canEndTurn(){
    Player& player = getTurnPlayer();
    return !(player.canBuildCity() ||
            player.canBuildRoad() ||
            player.canBuildSettlement())
            && rolled
            && !canMoveRobber
            && !stealablePlayers.size();
}
void GameState::endTurn(){
    if (canEndTurn()){
        ++turnPlayer;
        if (turnPlayer > players.size()){
            turnPlayer -= players.size();
        }
        rolled = false;
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
std::optional<Hexagon> GameState::getRobber(){
    return board.getRobber();
}