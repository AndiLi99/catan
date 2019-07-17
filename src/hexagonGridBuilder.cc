#include "hexagonGridBuilder.h"
#include "hexagonGrid.h"

HexagonGrid HexagonGridBuilder::defaultGrid(){
    HexagonGrid hexGrid{2};
    for (Hexagon hex: hexGrid.validHexagons){
        hexGrid.addTile(hex, Tile{TileType::Forest, 5});
    }
    return hexGrid;
}