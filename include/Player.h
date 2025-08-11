// header file for the player class

#pragma once
#include "Board.h"
using namespace std;

class Player
{
protected:
    char symbol; // Player's symbol (X or O)

public:
    Player(char symbol) : symbol(symbol) {}; // Constructor
    virtual ~Player() {}                     // Virtual destructor for polymorphism

    char getSymbol() const { return symbol; }

    // Pure virtual function: makes Player an abstract class
    virtual int getMove(const Board &board) = 0;
};


// --- Derived Classes ---

class HumanPlayer : public Player {
public:
    HumanPlayer(char sym) : Player(sym) {}
    int getMove(const Board& board) override;
};

class ComputerPlayer : public Player {
private:
    char opponentSymbol;
    int minimax(Board& board, bool isMaximizing,int alpha, int beta);

public:
    ComputerPlayer(char sym, char oppSym) : Player(sym), opponentSymbol(oppSym) {}
    int getMove(const Board& board) override;
};