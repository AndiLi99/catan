#ifndef BOARD_FACTORY_H
#define BOARD_FACTORY_H

#include "board.h"
class BoardBuilder{
    void resetTiles();
    void resetConnections();
    void resetIntersections();
    void resetBoard();

    void defaultSetup();
    void randomSetup();
};

#endif