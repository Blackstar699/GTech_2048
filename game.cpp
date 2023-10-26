#include "game.h"

void game(Board& board) {
    board.addRandomTile();
    board.addRandomTile();

    char choice;
    do {
        board.print();

        cout << endl << "Enter direction (Z/Q/S/D): " << endl << endl;

        board.slideBoard();

        board.addRandomTile();

        if (board.checkWin()) {
            board.print();
            cout << "Congratulations! You win!" << endl;
            return;
        }

        if (board.checkGameOver()) {
            board.print();
            cout << "Game over!" << endl;
            return;
        }
    } while (true);
}
