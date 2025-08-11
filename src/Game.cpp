#include "Game.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
#include <memory>
using namespace std;

Game::Game()
{ // constructor to initialize the game
    board.showInstructions();
    char choice;
    cout << "Do you want to start first? (y/n): ";
    cin >> choice;

    const char HUMAN_SYMBOL = 'X';
    const char AI_SYMBOL = 'O';

    // player 1 -> starts first
    // player 2 -> plays second
    //  If the user chooses to start first, they will be player 1 (HumanPlayer)
    //  If the user chooses to let the AI start first, they will be player 2

    if (choice == 'y' || choice == 'Y')
    {
        player1 = make_unique<HumanPlayer>(HUMAN_SYMBOL);
        player2 = make_unique<ComputerPlayer>(AI_SYMBOL, HUMAN_SYMBOL);
        currentPlayer = player1.get();
    }
    else
    {
        player1 = make_unique<ComputerPlayer>(AI_SYMBOL, HUMAN_SYMBOL);
        player2 = make_unique<HumanPlayer>(HUMAN_SYMBOL);
        currentPlayer = player1.get();
    }
}

void Game::switchPlayer()
{ // function to switch the current player
    currentPlayer = (currentPlayer == player1.get()) ? player2.get() : player1.get();
}

void Game::run()
{
    while (true)
    {
        board.display();                          // display the current state of the board
        int move = currentPlayer->getMove(board); // get the move from the current player
        if (!board.placeMove(move, currentPlayer->getSymbol()))
        { // place the move
            cout << "Invalid move. Try again." << endl;
            continue; // If the move is invalid, continue to the next iteration of the loop
        }
        if (currentPlayer->getSymbol() == 'O' && board.placeMove(move, currentPlayer->getSymbol()))
        { // If the current player is the computer
            cout << "COMPUTER has put a " << currentPlayer->getSymbol() << " in cell " << move << "\n";
        }
        if (board.checkWin(currentPlayer->getSymbol()))
        {                    // check if the current player has won
            board.display(); // display the final state of the board
            cout << "Player " << currentPlayer->getSymbol() << " wins!" << endl;
            break; // Exit the loop if a player has won
        }
        if (board.isFull())
        {                    // check if the board is full
            board.display(); // display the final state of the board
            cout << "It's a draw!" << endl;
            break; // Exit the loop if the game is a draw
        }
        switchPlayer(); // switch to the next player
    }
}
