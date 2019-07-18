#include "gameState.h"
#include <algorithm>
#include "helpers.h"

GameState::GameState(Board board, std::vector<Player> players, DiceRoll dice): 
board{board}, players{players}, numPlayers{players.size()}, dice{dice}{
    turnPlayer = 1;
    rolled = false;
    canMoveRobber = false;
    lastRoll = 0;
    gamePhase = GamePhase::Setup;
    setupIDGoingUp = true;
    setupIDHold = true;
    startSetupPhase();
}
GameState::~GameState(){}

void GameState::startSetupPhase(){
    for (Player& p: players){
        p.addSettlement();
        p.addRoad();
    }
}
int GameState::indexFromPlayerID(int playerID){
    return playerID -1;
}

Player& GameState::getPlayer(int playerID){
    return players[indexFromPlayerID(playerID)];
}
Player& GameState::getTurnPlayer(){
    return getPlayer(turnPlayer);
}
bool GameState::validSettlement(Vertex vertex){
    if (gamePhase == GamePhase::Setup)
    {
        return board.adjacentVerticesEmpty(vertex);
    }
    else
    {
        if (board.adjacentVerticesEmpty(vertex)){
            std::vector<Vertex> possibleBuilds = board.adjacentEmptySettlements(turnPlayer);
            return std::find(possibleBuilds.begin(), possibleBuilds.end(), vertex) != possibleBuilds.end();
        }
        return false;
    }
}
bool GameState::validRoad(Edge edge){
    if (gamePhase == GamePhase::Setup)
    {
        if (getTurnPlayer().canBuildSettlement())
        {
            return false;
        }
        else 
        {
            std::vector<Edge> possibleRoads = pregameLastSettle.value().protrudes();
            return std::find(possibleRoads.begin(), possibleRoads.end(), edge) != possibleRoads.end();
        }
    }
    else 
    {
        std::vector<Edge> possibleRoads = board.adjacentEmptyRoads(turnPlayer);
        return std::find(possibleRoads.begin(), possibleRoads.end(), edge) != possibleRoads.end();
    }
}
void GameState::buildSettlement(Vertex vertex){
    if (getTurnPlayer().canBuildSettlement() && validSettlement(vertex)){
        if (gamePhase == GamePhase::Setup){
            pregameLastSettle = vertex;
        }
        getTurnPlayer().subtractSettlement();
        board.addSettlement(vertex, turnPlayer);
        getTurnPlayer().addVictoryPoints(1);
    }
}
void GameState::buildCity(Vertex vertex){
    if (getTurnPlayer().canBuildCity() && board.canUpgrade(vertex, turnPlayer)){
        getTurnPlayer().subtractCity();
        board.upgradeSettlement(vertex);
        getTurnPlayer().addVictoryPoints(1);
    }
}
void GameState::buildRoad(Edge edge){
    if (getTurnPlayer().canBuildRoad() && validRoad(edge)){
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
    if (canMoveRobber && board.getRobber() != hex){
        stealablePlayers = board.moveRobber(hex);
        canMoveRobber = false;
    }
}
void GameState::stealResource(int playerID){
    if (std::find(stealablePlayers.begin(), stealablePlayers.end(), playerID) !=
    stealablePlayers.end()){
        if (getPlayer(playerID).handSize() > 0){
            Resource stolen = getPlayer(playerID).stealResource();
            getTurnPlayer().addResource(stolen);
        }
        stealablePlayers.clear();
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
    if (gamePhase == GamePhase::Play){
        if (!rolled){
            lastRoll = dice.rollDice();
            rolled = true;
            if (lastRoll == 7){
                canMoveRobber = true;
            } else {
                std::vector<std::vector<int>> production = board.produceResources(lastRoll, numPlayers);
                for (int i=0;i<numPlayers;++i){
                    players[i].addResources(production[i]);
                }
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

    if (gamePhase == GamePhase::Setup)
    {
        return !(player.canBuildCity() ||
            player.canBuildRoad() ||
            player.canBuildSettlement());
    }
    else
    {
    return !(player.canBuildCity() ||
            player.canBuildRoad() ||
            player.canBuildSettlement())
            && rolled
            && !canMoveRobber
            && !stealablePlayers.size();
    }
}
void GameState::endTurn(){
    if (canEndTurn()){
        if (gamePhase == GamePhase::Setup)
        {
            if (setupIDGoingUp)
            {
                getTurnPlayer().addSettlement();
                getTurnPlayer().addRoad();
                ++turnPlayer;
            }
            else 
            {
                if (setupIDHold)
                {
                    getTurnPlayer().addSettlement();
                    getTurnPlayer().addRoad();
                    setupIDHold = false;
                }
                else 
                {
                getTurnPlayer().addResources(board.adjacentResources(pregameLastSettle.value()));
                    --turnPlayer;
                }
            }

            if (turnPlayer == numPlayers){
                setupIDGoingUp = false;
            } else if(turnPlayer == 0 && !setupIDGoingUp){
                gamePhase = GamePhase::Play;
                turnPlayer = 1;
            }
        } 
        else if (gamePhase == GamePhase::Play)
        {
        ++turnPlayer;
        if (turnPlayer > players.size()){
            turnPlayer -= players.size();
        }
        rolled = false;

        }
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