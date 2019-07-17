#ifndef TILE
#define TILE

#include "tileType.h"
#include <optional>
class Tile {
		TileType type;
		std::optional<int> rollNumber;
	public:
		Tile(TileType type, std::optional<int> rollNumber);
		TileType getType() const;
		bool isRollNum(int number);
		int getRollNumber() const;
};

#endif
