#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "subject.h"
#include "player.h"
#include "board.h"
#include <vector>

struct HexagonGrid;
enum class GamePhase{};
class GameState: public Subject{
        Board board;
        std::vector<Player> players;
        int turnPlayer;
    public:
        GameState(Board board, std::vector<Player> players, int numPlayers);
        void buildSettlement(Vertex vertex);
        void buildCity(Vertex vertex);
        void buildRoad(Edge edge);
        void purchaseSettlement();
        void purchaseCity();
        void purchaseRoad();
        ResourceArray getResources();
        void rollDice();
        void endTurn();
        const HexagonGrid& getGrid();
};

#endif