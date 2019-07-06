#ifndef BOARD
#define BOARD
#include "hexagonGrid.h"
#include "tile.h"
#include "connection.h"
#include "intersection.h"

class Board {
		HexagonGrid<Tile, Connection, Intersection> hexGrid;
	public:

};
#endif
