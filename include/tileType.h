#ifndef TILE_TYPE_H
#define TILE_TYPE_H
#include <iosfwd>
enum class TileType{Forest, Hills, Fields, Pasture, Mountains, Desert};

std::ostream& operator<<(std::ostream& out, TileType TileType);
#endif