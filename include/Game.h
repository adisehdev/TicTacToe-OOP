//header file for the game class

#pragma once
#include "Board.h"
#include "Player.h"
#include <memory> // For std::unique_ptr
using namespace std;

class Game {
private:
    Board board;
    unique_ptr<Player> player1;
    unique_ptr<Player> player2;
    Player* currentPlayer;

    void switchPlayer();

public:
    Game();
    void run();
    
};