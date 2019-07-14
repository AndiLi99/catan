#ifndef BOARD_H
#define BOARD_H

#include <unordered_map>
#include <unordered_set>
#include <optional>

#include "hexagon.h"
#include "edge.h"
#include "vertex.h"
#include "tile.h"
#include "road.h"
#include "settlement.h"

using HexagonSet = std::unordered_set<Hexagon, HexagonHash, HexagonEquals>;
using EdgeSet = std::unordered_set<Edge, EdgeHash, EdgeEquals>;
using VertexSet = std::unordered_set<Vertex, VertexHash, VertexEquals>;
using TileMap = std::unordered_map<Hexagon, Tile, HexagonHash, HexagonEquals>;
using RoadMap = std::unordered_map<Edge, Road, EdgeHash, EdgeEquals>;
using SettlementMap = std::unordered_map<Vertex, Settlement, VertexHash, VertexEquals>;

class BoardBuilder;

class Board {
		HexagonSet validHexagons;
		EdgeSet validEdges;
		Vertex validVertices;
		/*
			tiles, connections and intersections invariant:
			The keys to these hashmaps must be in the set of their respective
			valid_ set.
		 */
		TileMap tiles;
        ConnectionMap connections;
        IntersectionMap intersections;
		std::optional<Hexagon> robber;
		friend BoardBuilder Board();
		std::vector<Hexagon> hexagonsWithNumber(int roll);
	public:
		void addSettlement(Vertex vertex, int playerID);
		void upgradeSettlement(Vertex vertex);
		void addRoad(Edge edge, int playerID);
		std::vector<std::tuple<int, int>> rollDice(int roll); //refactor into a command
		std::vector<Edge> getRoads(int playerID);
		std::vector<Vertex> getSettlements(int playerID);
		std::vector<int> moveRobber(Hexagon location);
};
#endif
