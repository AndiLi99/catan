#ifndef HEXAGON_GRID_H
#define HEXAGON_GRID_H

#include <unordered_map>
#include <unordered_set>
#include "hexagonGrid/hexagon.h"
#include "hexagonGrid/edge.h"
#include "hexagonGrid/vertex.h"
#include "tile.h"
#include "road.h"
#include "settlement.h"

using HexagonSet = std::unordered_set<Hexagon, HexagonHash, HexagonEquals>;
using EdgeSet = std::unordered_set<Edge, EdgeHash, EdgeEquals>;
using VertexSet = std::unordered_set<Vertex, VertexHash, VertexEquals>;
using TileMap = std::unordered_map<Hexagon, Tile, HexagonHash, HexagonEquals>;
using RoadMap = std::unordered_map<Edge, Road, EdgeHash, EdgeEquals>;
using SettlementMap = std::unordered_map<Vertex, Settlement, VertexHash, VertexEquals>;

class HexagonGrid{

        HexagonSet validHexagons;
        EdgeSet validEdges;
        VertexSet validVertices;
        /*
            tiles, connections and intersections invariant:
            The keys to these hashmaps must be in the set of their respective
            valid_ set.
            */
        TileMap tiles;
        RoadMap roads;
        SettlementMap settlements;
        int radius;
        std::vector<Hexagon> getPointyTopHexOrder(int radius);
        std::vector<Edge> getPointyTopEdgeOrder(int radius);
        std::vector<Vertex> getPointyTopVertexOrder(int radius);
    public:
        HexagonGrid(int radius);
        const Tile& cgetTile(Hexagon hex);
        const Road& cgetRoad(Edge edge);
        const Settlement& cgetSettlement(Vertex vertex);
        Tile& getTile(Hexagon hex);
        Road& getRoad(Edge edge);
        Settlement& getSettlement(Vertex vertex);
        bool emptyEdge(Edge edge);
        bool emptyVertex(Vertex vert);
        void addTile(Hexagon hex, Tile tile);
        void addRoad(Edge edge, Road road);
        void addSettlement(Vertex vertex, Settlement settlement);
        void upgradeSettlement(Vertex vertex);
        std::vector<Hexagon> getHexPrintOrder();
        std::vector<Edge> getEdgePrintOrder();
        std::vector<Vertex> getVertexPrintOrder();
};
#endif