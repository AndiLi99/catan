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
        void buySettlement(Vertex vertex);
        void buyCity(Vertex vertex);
        void buyRoad(Edge edge);
        ResourceArray getResources();
        void rollDice();
        void endTurn();
        const HexagonGrid& getGrid();
};

#endif