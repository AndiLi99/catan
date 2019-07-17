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
		const HexagonGrid& getGrid();
		Hexagon getRobber();
};
#endif
