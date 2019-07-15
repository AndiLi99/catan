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

struct HexagonGrid{
    HexagonSet validHexagons;
    EdgeSet validEdges;
    Vertex validVertices;
    /*
        tiles, connections and intersections invariant:
        The keys to these hashmaps must be in the set of their respective
        valid_ set.
        */
    TileMap tiles;
    RoadMap roads;
    SettlementMap settlements;
};
#endif