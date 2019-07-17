#ifndef BOARD_H
#define BOARD_H

#include <optional>
#include "hexagonGrid.h"

struct ResourceArray;

class Board {
		HexagonGrid hexGrid;
		std::optional<Hexagon> robber;
		std::vector<Hexagon> hexagonsWithNumber(int roll);
	public:
		Board(HexagonGrid hexGrid);
		void addSettlement(Vertex vertex, int playerID);
		void upgradeSettlement(Vertex vertex);
		void addRoad(Edge edge, int playerID);
		std::vector<ResourceArray> produceResources(int rollNum);
		std::vector<Edge> getRoads(int playerID);
		std::vector<Vertex> getSettlements(int playerID);
		std::vector<int> moveRobber(Hexagon location);
		Hexagon getRobber();

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
