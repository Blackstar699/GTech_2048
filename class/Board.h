#ifndef INC_2048CONSOLE_BOARD_H
#define INC_2048CONSOLE_BOARD_H

#include "../includes.h"
#include "Tile.h"

class Board {
private:
    vector<vector<Tile>> tiles;
    bool slideLine(vector<Tile>& line);

public:
    explicit Board();
    void print();
    bool addRandomTile();
    bool slideBoard();
    bool checkWin();
    bool checkGameOver();
};

#endif
