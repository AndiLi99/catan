#ifndef HEXAGON_GRID_BUILDER_H
#define HEXAGON_GRID_BUILDER_H

class HexagonGrid;

struct HexagonGridBuilder{
    static HexagonGrid defaultGrid();
    static HexagonGrid randomGrid();
};

#endif