#ifndef HEXAGON_GRID_BUILDER_H
#define HEXAGON_GRID_BUILDER_H

class HexagonGrid;

class HexagonGridBuilder{
    protected:
        static HexagonGrid emptyDefault();
    public:
        virtual HexagonGrid build() = 0;
};

#endif