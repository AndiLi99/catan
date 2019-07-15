#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "subject.h"
#include "player.h"
#include "board.h"
#include <vector>

struct HexagonGrid;
enum class GamePhase{};
class GameState: public Subject{
        int turnPlayer;
        Board board;
        std::vector<Player> players;
    public:
        GameState(Board board, int numPlayers);
        void buySettlement(Vertex vertex);
        void buyCity(Vertex vertex);
        void buyRoad(Edge edge);
        ResourceArray getResources();
        void rollDice();
        void endTurn();
};

#endif