#include "Game.h"
#include <iostream>
using namespace std;

void printHeader() {
    cout << "\n-------------------------------------------------\n";
    cout << "\t\tTic-Tac-Toe (OOP Version)\n";
    cout << "-------------------------------------------------\n\n";
}

int main() {
    printHeader();
    
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        Game game; // Creates a new game instance
        game.run();   // Runs the game to completion

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing!\n";
    return 0;
}