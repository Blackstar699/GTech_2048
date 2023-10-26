#ifndef INC_2048CONSOLE_TILE_H
#define INC_2048CONSOLE_TILE_H

class Tile {
private:
    int value;

public:
    explicit Tile();
    int getValue();
    void setValue(int val);
};

#endif
