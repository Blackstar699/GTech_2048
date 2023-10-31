#include "includes.h"
#include "class/Tile.h"
#include "class/Board.h"
#include "game.h"

int main() {
    srand(time(0));

    Board board;

    game(board);

    return 0;
}
