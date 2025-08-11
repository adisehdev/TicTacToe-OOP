//this is the header file to the Board class

#pragma once //to load this file only once
#include <iostream>
#include <vector>
using namespace std;


const int SIDE = 3; // Length of the board
const char EMPTY_CELL = ' ';


class Board {
private:
    vector<vector<char>> board; //this is the board represented as a 2D vector

public:
    Board(); //constructor to initialize the board

    void display() const; //function to display the current state of the board
    void showInstructions() const; //function to show the instructions for playing
    bool placeMove(int cell, char symbol); //function to place a move on the board
    bool checkWin(char symbol) const; //function to check if a player has won
    bool isFull() const; //function to check if the board is full
    void reset(); //function to reset the board to its initial state

    // Friend class declaration for ComputerPlayer to access the grid for minimax
    friend class ComputerPlayer; 



};

