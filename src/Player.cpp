#include "Player.h"
#include "Board.h"
#include <iostream>

using namespace std;

int HumanPlayer::getMove(const Board &board)
{

    int move;

    while (true)
    {
        cout << " Enter your move (1-9): ";
        cin >> move;

        if (cin.fail() || move < 1 || move > 9)
        {
            cout << "Invalid move. Please enter a number between 1 and 9." << endl;
            cin.clear();                                         // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            continue;
        }
        else
        {
            break; // Valid move
        }
    }

    return move; // Return the valid move
}

int ComputerPlayer::minimax(Board &board, bool isMaximising, int alpha, int beta)
{
    if (board.checkWin(symbol))
    {
        return 10; // Maximizing player wins
    }
    else if (board.checkWin(opponentSymbol))
    {
        return -10; // Minimizing player wins
    }
    else if (board.isFull())
    {
        return 0; // Draw
    }

    if (isMaximising)
    {
        int bestScore = -1000; // Start with a very low score
        for (int i = 0; i < SIDE; i++)
        {
            for (int j = 0; j < SIDE; j++)
            {
                if (board.board[i][j] == EMPTY_CELL)
                {                               // Check for empty cell
                    board.board[i][j] = symbol; // Place maximizing player's symbol

                    bestScore = max(bestScore, minimax(board, false, alpha, beta)); // Recursively call minimax for minimizing player
                    board.board[i][j] = EMPTY_CELL;                                 // Undo move
                    alpha = max(alpha, bestScore);                                  // Update alpha
                    if (beta <= alpha)
                    {                     // we have already found a better move
                        return bestScore; // Beta cut-off
                    }
                }
            }
        }

        return bestScore; // Return the best score for maximizing player
    }

    else
    {
        int bestScore = 1000; // Start with a very high score
        for (int i = 0; i < SIDE; i++)
        {
            for (int j = 0; j < SIDE; j++)
            {
                if (board.board[i][j] == EMPTY_CELL)
                {                                       // Check for empty cell
                    board.board[i][j] = opponentSymbol; // Place minimizing player's symbol

                    bestScore = min(bestScore, minimax(board, true, alpha, beta)); // Recursively call minimax for maximizing player
                    beta = min(beta, bestScore);                                   // Update beta
                    board.board[i][j] = EMPTY_CELL;                                // Undo move

                    if (beta <= alpha) // we have already found a better move
                    {
                        return bestScore; // Alpha cut-off
                    }
                }
            }
        }
        return bestScore; // Return the best score for minimizing player
    }
}

int ComputerPlayer::getMove(const Board &board)
{
    Board tempBoard = board; // Create a temporary copy to simulate moves
    int bestMove = -1;
    int bestScore = -1000;

    std::cout << "Computer " << symbol << " is thinking..." << std::endl;

    for (int i = 0; i < SIDE; ++i)
    {
        for (int j = 0; j < SIDE; ++j)
        {
            if (tempBoard.board[i][j] == EMPTY_CELL)
            {
                tempBoard.board[i][j] = symbol;
                int moveScore = minimax(tempBoard, false, -1000, 1000); // Call minimax for minimizing player
                tempBoard.board[i][j] = EMPTY_CELL;                     // Undo move

                if (moveScore > bestScore)
                {
                    bestScore = moveScore;
                    bestMove = i * SIDE + j + 1;
                }
            }
        }
    }
    return bestMove;
}