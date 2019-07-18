#ifndef DEFAULT_GRID_BUILDER_H
#define DEFAULT_GRID_BUILDER_H

#include "hexagonGridBuilder.h"
class HexagonGrid;

class DefaultGridBuilder: public HexagonGridBuilder{
    public:
        HexagonGrid build() override;
};

#endif