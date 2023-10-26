#include "Tile.h"

//Class Constructor
Tile::Tile() : value(0) {}

//Return Tile value
int Tile::getValue() {
    return value;
}

//Set Time Value
void Tile::setValue(int val) {
    value = val;
}
