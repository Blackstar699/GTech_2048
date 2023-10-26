#include "game.h"

void game(Board& board) {
    int end = 0;
    bool close = false;
    int c = 0;

    board.addRandomTile();
    board.addRandomTile();

    do {
        board.print();

        cout << endl << "Enter direction (Z/Q/S/D): " << endl << endl;

        board.slideBoard();

        board.addRandomTile();

        if(board.checkWin()) end = 1;
        if(board.checkGameOver()) end = 2;

        if(end != 0){
            board.print();

            if(end == 1) cout << "Congratulations! You win!" << endl;
            else if(end == 2) cout << "Game over!" << endl;

            cout << "Press ENTER to close game" << endl;

            while(!close){
                switch ( ( c = _getch() ) ) {
                    case ENTER:
                        close = true;
                        break;
                    default:
                        close = false;
                        break;
                }
            }

            return;
        }

    } while (true);
}
