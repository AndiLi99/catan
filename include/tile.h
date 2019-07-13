#ifndef TILE
#define TILE

#include "hexagonGrid/hexagon.h"
#include "resource.h"
#include <optional>
class Tile {
		std::optional<Resource> resource;
		std::optional<int> rollNumber;
	public:
		bool isResource(Resource resource);
		bool isRollNum(int roll);
};

#endif
