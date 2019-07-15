#ifndef TILE
#define TILE

#include "tileType.h"
#include <optional>
class Tile {
		TileType type;
		std::optional<int> rollNumber;
	public:
		Tile(TileType type, std::optional<int> rollNumber);
		TileType getType();
		bool isRollNum(int number);
};

#endif
