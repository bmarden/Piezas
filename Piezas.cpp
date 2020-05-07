#include "Piezas.h"

#include <stdexcept>
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/

/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas() {
    board.resize(BOARD_ROWS, std::vector<Piece>(BOARD_COLS, Blank));
    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset() {
    for (auto row = board.begin(); row != board.end(); row++) {
        for (auto col = row->begin(); col != row->end(); col++) {
            *col = Blank;
        }
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column) {
    try {
        for (auto row = board.begin(); row != board.end(); row++) {
            if (row->at(column) == Blank) {
                row->at(column) = turn;
                turn == X ? turn = O : turn = X;
                return turn;
            }
        }
    } catch (const std::out_of_range& error) {
        return Invalid;
    }
    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column) {
    try {
        return board.at(row).at(column);
    } catch (const std::out_of_range& error) {
        return Invalid;
    }
    return Blank;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState() {
    // Check for incomplete game
    for (auto row = board.begin(); row != board.end(); row++) {
        for (auto col = row->begin(); col != row->end(); col++) {
            if (*col == Blank) {
                return Invalid;
            }
        }
    }

    // Check for winner

    int greatestX = 1;
    int greatestO = 1;

    for (size_t i = 0; i < board.size(); i++) {
        int curXMax = 1;
        int curOMax = 1;
        Piece tmp = board[i][0];
        for (size_t j = 1; j < board[i].size(); j++) {
            if (board[i][j] == tmp) {
                tmp == X ? curXMax++ : curOMax++;
            }
            tmp = board[i][j];
        }
        if (curXMax > greatestX) {
            greatestX = curXMax;
        }
        if (curOMax > greatestO) {
            greatestO = curOMax;
        }
    }
    // If either value has greater than 3 points then they win

    for (size_t j = 0; j < 4; j++) {
        int curXMax = 1;
        int curOMax = 1;
        Piece tmp = board[0][j];
        for (size_t i = 1; i < 3; i++) {
            if (tmp == board[i][j]) {
                board[i][j] == X ? curXMax++ : curOMax++;
            }
            tmp = board[i][j];
        }
        if (curXMax > greatestX) {
            greatestX = curXMax;
        }
        if (curOMax > greatestO) {
            greatestO = curOMax;
        }
    }

    if (greatestX > greatestO) {
        return X;
    }
    if (greatestO > greatestX) {
        return O;
    }

    return Blank;
}