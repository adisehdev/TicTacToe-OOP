#include "Game.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
#include <memory>
using namespace std;

Game::Game()
{ // constructor to initialize the game
    board.showInstructions();
    board.reset(); // Reset the board to its initial state
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



void Game::run() {
    while (true) {
        // --- 1. Announce Turn & Show Board BEFORE Move ---
        cout << "\n----------------------------------------\n";
        cout << "Current Player: " << currentPlayer->getSymbol() << endl;
        cout << "Board state before move:" << endl;
        board.display();

        if(currentPlayer->getSymbol() == 'X') {
            board.humanStatus(); // Show empty cells for human player
        }

        // --- 2. Get a Valid Move ---
        // This loop ensures we only proceed once a valid move is entered.
        int move;
        bool movePlaced = false;
        do {
            move = currentPlayer->getMove(board); // Polymorphic call to get move
            
            // Try to place the move on the board
            if (board.placeMove(move, currentPlayer->getSymbol())) {
                movePlaced = true; // Move was successful
            } else {
                // Only show an error message for the human player.
                // The computer should theoretically never choose an invalid move.
                if (dynamic_cast<HumanPlayer*>(currentPlayer)) {
                    cout << "Invalid move. That cell is either taken or out of bounds. Try again." << endl;
                }
            }
        } while (!movePlaced);

        // --- 3. Show Board AFTER Move ---
        cout << "\nBoard state after move:" << endl;
        board.display();

        // For clarity, announce the computer's move
        if (dynamic_cast<ComputerPlayer*>(currentPlayer)) {
            cout << "COMPUTER (" << currentPlayer->getSymbol() << ") chose cell " << move << endl;
        }

        // --- 4. Check for Game Over Conditions ---
        if (board.checkWin(currentPlayer->getSymbol())) {
            cout << "\n>>> Player " << currentPlayer->getSymbol() << " wins! <<<" << endl;
            break; // Exit the game loop
        }

        if (board.isFull()) {
            cout << "\n>>> It's a draw! <<<" << endl;
            break; // Exit the game loop
        }

        // --- 5. Switch to the Next Player ---
        switchPlayer();
    }
}
