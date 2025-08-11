#include "Board.h"
#include <iostream>
using namespace std;

Board::Board(){
    cout<<"Initializing the board..."<<endl;
    reset(); // Initialize the board to empty state
}

void Board::reset() { //implementation of reset function
    board.assign(SIDE, vector<char>(SIDE, EMPTY_CELL));
}

void Board::display() const { //implementation of display function
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


void Board::showInstructions() const { //implementation of showInstructions function
    cout << "Choose a cell numbered from 1 to 9 as below and play" << endl;
    cout << "\t\t\t 1 | 2 | 3 \n";
    cout << "\t\t\t-----------\n";
    cout << "\t\t\t 4 | 5 | 6 \n";
    cout << "\t\t\t-----------\n";
    cout << "\t\t\t 7 | 8 | 9 \n\n";
}


bool Board::placeMove(int cell, char symbol) { //implementation of placeMove function

    if (cell < 1 || cell > SIDE * SIDE) {
        return false; // Invalid cell number
    }

    int row = (cell - 1) / SIDE;
    int col = (cell - 1) % SIDE;

    if (row < 0 || row >= SIDE || col < 0 || col >= SIDE || board[row][col] != EMPTY_CELL) {
        return false; // Invalid move
    }

    board[row][col] = symbol; // Place the move
    return true;
}


bool Board::checkWin(char symbol) const { //implementation of checkWin function
    // Check rows and columns
    for (int i = 0; i < SIDE; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }

    return false;
}

bool Board::isFull() const { //implementation of isFull function
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            if (board[i][j] == EMPTY_CELL) {
                return false; // Found an empty cell
            }
        }
    }
    return true; // No empty cells found
}

