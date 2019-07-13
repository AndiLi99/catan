#ifndef BOARD_H
#define BOARD_H

#include <unordered_map>
#include <optional>

#include "hexagon.h"
#include "edge.h"
#include "vertex.h"
#include "tile.h"
#include "connection.h"
#include "intersection.h"

using TileMap = std::unordered_map<Hexagon, Tile, HexagonHash, HexagonEquals>;
using ConnectionMap = std::unordered_map<Edge, Connection, EdgeHash, EdgeEquals>;
using IntersectionMap = std::unordered_map<Vertex, Intersection, VertexHash, VertexEquals>;

class BoardBuilder;

class Board {
		TileMap tiles;
        ConnectionMap connections;
        IntersectionMap intersections;;
		std::optional<Hexagon> robber;
		friend BoardBuilder Board();
	public:
		void addSettlement(Vertex vertex, int playerID);
		void upgradeSettlement(Vertex vertex);
		void addRoad(Edge edge, int playerID);
		std::vector<Edge> getRoads(int playerID);
		std::vector<Vertex> getSettlements(int playerID);
		std::vector<int> moveRobber(Hexagon location);
};
#endif
