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
        int numPlayers;
        DiceRoll dice;
        int turnPlayer;
        int lastRoll;
        std::vector<int> stealablePlayers;
        bool rolled;
        bool canMoveRobber;
        bool setupIDGoingUp;
        int indexFromPlayerID(int);
        Player& getPlayer(int playerID);
        Player& getTurnPlayer();
        bool canEndTurn();
        GamePhase gamePhase;
        void startSetupPhase();
        bool validSettlement(Vertex vertex);
        bool validRoad(Edge edge);
        bool setupIDHold;
        std::optional<Vertex> pregameLastSettle;
    public:
        GameState(Board board, std::vector<Player> players, DiceRoll dice);
        ~GameState();
        void buildSettlement(Vertex vertex);
        void buildCity(Vertex vertex);
        void buildRoad(Edge edge);
        void purchaseSettlement();
        void purchaseCity();
        void purchaseRoad();
        void stealResource(int playerID);
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
        int getTurnPlayerID();
        const Tile& cgetTile(Hexagon hex);
        const Road& cgetRoad(Edge edge);
        const Settlement& cgetSettlement(Vertex vertex);
        std::optional<Hexagon> getRobber();
        bool emptyEdge(Edge edge);
        bool emptyVertex(Vertex vert);
};

#endif