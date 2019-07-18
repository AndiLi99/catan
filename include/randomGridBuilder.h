#ifndef RANDOM_GRID_BUILDER_H
#define RANDOM_GRID_BUILDER_H

#include "hexagonGridBuilder.h"
class HexagonGrid;

class RandomGridBuilder: public HexagonGridBuilder{
    public:
        HexagonGrid build() override;
};

#endif