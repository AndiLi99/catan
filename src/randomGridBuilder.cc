#include "randomGridBuilder.h"
#include "hexagonGrid.h"
#include <random>
#include <algorithm>

HexagonGrid RandomGridBuilder::build(){
    HexagonGrid hexGrid =  HexagonGridBuilder::emptyDefault();
    std::vector<TileType> tileTypes{
        TileType::Forest,
        TileType::Pasture,
        TileType::Fields,
        TileType::Hills,
        TileType::Mountains,
        TileType::Hills,
        TileType::Pasture,
        TileType::Desert,
        TileType::Forest,
        TileType::Fields,
        TileType::Forest,
        TileType::Fields,
        TileType::Hills,
        TileType::Pasture,
        TileType::Pasture,
        TileType::Mountains,
        TileType::Mountains,
        TileType::Fields,
        TileType::Forest,
    };
    auto rng = std::default_random_engine {time(0)};
    std::shuffle(std::begin(tileTypes), std::end(tileTypes), rng);
    std::vector<int> numberOrder{
        11,
        12,
        9,
        4,
        6,
        5,
        10,
        3,
        11,
        4,
        8,
        8,
        10,
        9,
        3,
        5,
        2,
        6,
    };
    bool seenDesert = false;
    int i = 0;
    for (Hexagon hex: hexGrid.getHexPrintOrder()){
        if (tileTypes[i] == TileType::Desert)
        {
            Tile tile{tileTypes[i], 0};
            hexGrid.addTile(hex, tile);
            seenDesert = true;
        }
        else if (seenDesert)
        {
            Tile tile{tileTypes[i], numberOrder[i-1]};
            hexGrid.addTile(hex, tile);

        }
        else
        {
            Tile tile{tileTypes[i], numberOrder[i]};
            hexGrid.addTile(hex, tile);
        }
        ++i;
    }
    return hexGrid;
}