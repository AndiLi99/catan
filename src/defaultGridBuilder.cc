#include "defaultGridBuilder.h"
#include "hexagonGrid.h"

HexagonGrid DefaultGridBuilder::build(){
    HexagonGrid hexGrid =  HexagonGridBuilder::emptyDefault();
    std::vector<Tile> defaultLayout{
        Tile{TileType::Forest, 11},
        Tile{TileType::Pasture, 12},
        Tile{TileType::Fields, 9},
        Tile{TileType::Hills, 4},
        Tile{TileType::Mountains, 6},
        Tile{TileType::Hills, 5},
        Tile{TileType::Pasture, 10},
        Tile{TileType::Desert, std::nullopt},
        Tile{TileType::Forest, 3},
        Tile{TileType::Fields, 11},
        Tile{TileType::Forest, 4},
        Tile{TileType::Fields, 8},
        Tile{TileType::Hills, 8},
        Tile{TileType::Pasture, 10},
        Tile{TileType::Pasture, 9},
        Tile{TileType::Mountains, 3},
        Tile{TileType::Mountains, 5},
        Tile{TileType::Fields, 2},
        Tile{TileType::Forest, 6},
    };
    int i = 0;
    for (Hexagon hex: hexGrid.getHexPrintOrder()){
        hexGrid.addTile(hex, defaultLayout[i]);
        ++i;
    }
    return hexGrid;
}