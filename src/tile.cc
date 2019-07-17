#include "tile.h"

Tile::Tile(TileType type, std::optional<int> rollNumber): type{type}, rollNumber{rollNumber}{}

TileType Tile::getType() const{
    return type;
}

bool Tile::isRollNum(int number){
    return number == rollNumber;
}

int Tile::getRollNumber() const{
    return rollNumber? rollNumber.value() : -1;
}
