#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "subject.h"
#include "player.h"
#include "board.h"
#include "diceRoll.h"
#include "resource.h"
#include <vector>

struct HexagonGrid;
enum class GamePhase{Setup, Play, Finished};
class GameState: public Subject{
        Board board;
        std::vector<Player> players;
        DiceRoll dice;
        int turnPlayer;
        int lastRoll;
        std::vector<int> stealablePlayers;
        bool rolled;
        int indexFromPlayerID(int);
        Player& getPlayer(int playerID);
        Player& getTurnPlayer();
    public:
        GameState(Board board, std::vector<Player> players, DiceRoll dice);
        ~GameState();
        void buildSettlement(Vertex vertex);
        void buildCity(Vertex vertex);
        void buildRoad(Edge edge);
        void purchaseSettlement();
        void purchaseCity();
        void purchaseRoad();
        Resource stealResource(int playerID);
        void rollDice();
        void endTurn();
        void moveRobber(Hexagon hex);
        std::vector<Hexagon> getHexPrintOrder();
        std::vector<Edge> getEdgePrintOrder();
        std::vector<Vertex> getVertexPrintOrder();
        std::vector<int> getResources();
        std::string getUsername();
        std::vector<int> getUnbuilt();
        int getVictoryPoints();
        int getLastDiceRoll();
        const Tile& cgetTile(Hexagon hex);
        const Road& cgetRoad(Edge edge);
        const Settlement& cgetSettlement(Vertex vertex);
        bool emptyEdge(Edge edge);
        bool emptyVertex(Vertex vert);
};

#endif