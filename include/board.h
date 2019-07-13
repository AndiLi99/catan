#ifndef BOARD_H
#define BOARD_H

#include <unordered_map>
#include "hexagon.h"
#include "edge.h"
#include "vertex.h"
#include "tile.h"
#include "connection.h"
#include "intersection.h"

class Board {
		std::unordered_map<Hexagon, Tile, HexagonHash, HexagonEquals> tiles;
        std::unordered_map<Edge, Connection, EdgeHash, EdgeEquals> connections;
        std::unordered_map<Vertex, Intersection, VertexHash, VertexEquals> intersections;;
		Hexagon robber;
		void resetTiles();
		void resetConnections();
		void resetIntersections();
	public:
		void resetBoard();
		void defaultSetup();
		void randomSetup();
		void addSettlement(Vertex vertex, int playerID);
		void upgradeSettlement(Vertex vertex);
		void addRoad(Edge edge, int playerID);

};
#endif
