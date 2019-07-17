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
        int indexFromPlayerID(int);
    public:
        GameState(Board board, std::vector<Player> players);
        ~GameState();
        void buildSettlement(Vertex vertex);
        void buildCity(Vertex vertex);
        void buildRoad(Edge edge);
        void purchaseSettlement();
        void purchaseCity();
        void purchaseRoad();
        ResourceArray getResources();
        void rollDice();
        void endTurn();
        std::vector<Hexagon> getHexPrintOrder();
        std::vector<Edge> getEdgePrintOrder();
        std::vector<Vertex> getVertexPrintOrder();
        const Tile& cgetTile(Hexagon hex);
        const Road& cgetRoad(Edge edge);
        const Settlement& cgetSettlement(Vertex vertex);
        bool emptyEdge(Edge edge);
        bool emptyVertex(Vertex vert);
};

#endif