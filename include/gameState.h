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
        GameState(Board board, std::vector<Player> players);
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
        vector<Hexagon> getHexPrintOrder();
        vector<Edge> getEdgePrintOrder();
        vector<Vertex> getVertexPrintOrder();
        const Tile& cgetTile(Hexagon hex);
        const Road& cgetRoad(Edge edge);
        const Settlement& cgetSettlement(Vertex vertex);
        bool emptyEdge(Edge edge);
        bool emptyVertex(Vertex vert);
};

#endif