#ifndef BOARD_H
#define BOARD_H

#include <optional>
#include "hexagonGrid.h"

struct ResourceArray;

class Board {
		HexagonGrid hexGrid;
		std::optional<Hexagon> robber;
	public:
		Board(HexagonGrid hexGrid);
		void addSettlement(Vertex vertex, int playerID);
		void upgradeSettlement(Vertex vertex);
		void addRoad(Edge edge, int playerID);
		std::vector<std::vector<int>> produceResources(int rollNum, int numPlayers);
		std::vector<Edge> getRoads(int playerID);
		std::vector<Vertex> getSettlements(int playerID);
		std::vector<int> moveRobber(Hexagon location);
		std::optional<Hexagon> getRobber();
		std::vector<Edge> adjacentEmptyRoads(int playerID);
		std::vector<Vertex> adjacentEmptySettlements(int playerID);
		std::vector<int> adjacentResources(Vertex vert);

		std::vector<Hexagon> getHexPrintOrder();
        std::vector<Edge> getEdgePrintOrder();
        std::vector<Vertex> getVertexPrintOrder();
		const Tile& cgetTile(Hexagon hex);
        const Road& cgetRoad(Edge edge);
        const Settlement& cgetSettlement(Vertex vertex);
        bool emptyEdge(Edge edge);
        bool emptyVertex(Vertex vert);
        bool emptyHexagon(Hexagon hexagon);
		bool adjacentVerticesEmpty(Vertex vert);
		bool canUpgrade(Vertex vertex, int playerID);
};
#endif
