#include "Board.h"

//Class Constructor
Board::Board() : tiles(SIZE, vector<Tile>(SIZE)) {}

bool Board::slideLine(vector<Tile> &line) {
    bool changed = true;
    vector<Tile> newLine(SIZE, Tile());

    int fillPos = 0;
    for (int i = 0; i < SIZE; i++) {
        if (line[i].getValue() != 0) {
            if (newLine[fillPos].getValue() == 0) {
                newLine[fillPos] = line[i];
            }
            else if (newLine[fillPos].getValue() == line[i].getValue()) {
                newLine[fillPos].setValue(newLine[fillPos].getValue() * 2);
                fillPos++;
            }
            else {
                fillPos++;
                newLine[fillPos] = line[i];
            }
            if (i != fillPos) changed = true;
        }
    }

    line = newLine;
    return changed;
}

void Board::print() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tiles[i][j].getValue() == 0) {
                cout << std::setw(5) << "." << " ";
            } else {
                cout << std::setw(5) << tiles[i][j].getValue() << " ";
            }
        }
        cout << endl;
    }
}

bool Board::addRandomTile() {
    vector<std::pair<int, int>> emptyCells;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tiles[i][j].getValue() == 0) {
                emptyCells.push_back({ i, j });
            }
        }
    }

    if (emptyCells.empty()) return false;

    int index = rand() % emptyCells.size();
    int randomValue = rand() % 100;
    if (randomValue < 70) {
        tiles[emptyCells[index].first][emptyCells[index].second].setValue(2);
    }
    else {
        tiles[emptyCells[index].first][emptyCells[index].second].setValue(4);
    }

    return true;
}

bool Board::slideBoard() {
    bool key = false;

    while (!key) {

        int c = 0;

        switch ( ( c = _getch() ) ) {
            case KEY_Z:
                for (int j = 0; j < SIZE; j++) {
                    vector<Tile> column;
                    for (int i = 0; i < SIZE; i++) {
                        column.push_back(tiles[i][j]);
                    }
                    if (slideLine(column)) {
                        for (int i = 0; i < SIZE; i++) {
                            tiles[i][j] = column[i];
                        }
                        key = true;
                    }
                }
                break;
            case KEY_Q:
                for (int i = 0; i < SIZE; i++) {
                    if (slideLine(tiles[i])) key = true;
                }
                break;
            case KEY_S:
                for (int j = 0; j < SIZE; j++) {
                    vector<Tile> column;
                    for (int i = SIZE - 1; i >= 0; i--) {
                        column.push_back(tiles[i][j]);
                    }
                    if (slideLine(column)) {
                        for (int i = SIZE - 1, k = 0; i >= 0; i--, k++) {
                            tiles[i][j] = column[k];
                        }
                        key = true;
                    }
                }
                break;
            case KEY_D:
                for (int i = 0; i < SIZE; i++) {
                    reverse(tiles[i].begin(), tiles[i].end());
                    if (slideLine(tiles[i])) key = true;
                    reverse(tiles[i].begin(), tiles[i].end());
                }
                break;
            default:
                key = false;
                cout << "Invalid move!" << endl;
                break;
        }
    }

    return key;
}

bool Board::checkWin() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tiles[i][j].getValue() == WINNING_TILE) {
                return true;
            }
        }
    }
    return false;
}

bool Board::checkGameOver() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tiles[i][j].getValue() == 0) return false;
            if (i > 0 && tiles[i][j].getValue() == tiles[i - 1][j].getValue()) return false;
            if (j > 0 && tiles[i][j].getValue() == tiles[i][j - 1].getValue()) return false;
        }
    }
    return true;
}
