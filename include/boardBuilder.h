#ifndef BOARD_FACTORY_H
#define BOARD_FACTORY_H

class Board;
class Hexagon;

class BoardBuilder{
    void addHexagon(Hexagon hex);
    void resetTiles();
    void resetConnections();
    void resetIntersections();
    void resetBoard();

    void randomSetup();
    Board defaultSetup();
};

#endif