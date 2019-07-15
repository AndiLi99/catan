#ifndef BOARD_H
#define BOARD_H

#include <optional>
#include "hexagonGrid.h"

class BoardBuilder;
struct ResourceArray;

class Board {
		HexagonGrid hexGrid;
		std::optional<Hexagon> robber;
		Board();
		std::vector<Hexagon> hexagonsWithNumber(int roll);

	public:
		void addSettlement(Vertex vertex, int playerID);
		void upgradeSettlement(Vertex vertex);
		void addRoad(Edge edge, int playerID);
		std::vector<ResourceArray> produceResources(int rollNum);
		std::vector<Edge> getRoads(int playerID);
		std::vector<Vertex> getSettlements(int playerID);
		std::vector<int> moveRobber(Hexagon location);
		const HexagonGrid& getGrid();
		Hexagon getRobber();
		friend class BoardBuilder;
};
#endif
