# C++ Tic-Tac-Toe with Minimax AI

This project is an object-oriented implementation of the classic Tic-Tac-Toe game in C++. It features an unbeatable AI opponent powered by the **Minimax algorithm**, a fundamental concept in game theory and artificial intelligence.

The code is structured using modern C++ practices, including classes for the `Board`, `Player`, and `Game` to ensure a clean, modular, and extensible design.

![image](https://github.com/adisehdev/TIC-TAC-TOE/assets/97792541/b270f7d6-2f9e-4dfc-b994-069c2e3a59d6)

---
## The Minimax Algorithm: Creating an Unbeatable AI

The core of the AI's intelligence is the Minimax algorithm. It's a recursive, decision-making algorithm used in two-player, zero-sum games (where one player's gain is another's loss). Minimax builds a complete tree of every possible move and chooses the optimal one by assuming the opponent will also play optimally.

The algorithm has two key players:
* **The Maximizer:** Our AI, which tries to get the **highest** possible score.
* **The Minimizer:** The human opponent, who the AI assumes will always try to pick the move with the **lowest** possible score.

### How It Works

Minimax works by exploring a game tree from the current state down to all possible "terminal" states (win, lose, or draw).



1.  **Generate a Game Tree:** Starting from the current board, the algorithm recursively generates all possible future states of the game, forming a tree structure.

2.  **Assign Scores to Terminal States:** When a branch of the tree reaches an end-state, we assign it a numerical score from the AI's perspective:
    * **+10:** The AI (Maximizer) wins.
    * **-10:** The Human (Minimizer) wins.
    * **0:** The game is a draw.

3.  **Backpropagate Scores:** The algorithm then works its way back up the tree from the leaves, calculating the optimal score for each node based on the scores of its children.
    * At a **Maximizer node** (the AI's turn), it will select the child move with the **maximum** score. It asks, "Which move gives me the best possible outcome?"
    * At a **Minimizer node** (the Human's turn), it will select the child move with the **minimum** score. The AI assumes, "My opponent will now make the move that is worst for me."

By doing this, the score from a terminal state bubbles all the way up to the initial set of choices. The AI then simply picks the move that leads to the branch with the highest score, guaranteeing at worst a draw.

---
## Complexity Analysis

The performance of Minimax is determined by the size of the game tree.

* **Time Complexity: $O(b^d)$**
    This is where $b$ is the branching factor (the number of legal moves per turn) and $d$ is the maximum depth of the game tree. In Tic-Tac-Toe, the branching factor decreases at each turn and the depth is at most 9. While for a trivial game like Tic-Tac-Toe the total number of states is small (less than $9!$), this exponential complexity makes vanilla Minimax impractical for more complex games like Chess or Go without optimizations (e.g., Alpha-Beta Pruning).

* **Space Complexity: $O(d)$**
    The space required is proportional to the maximum depth of the game tree, as this is the largest the recursion call stack will get. For Tic-Tac-Toe, this is at most 9, making the space requirement minimal.

---


## How to Compile and Run

### Prerequisites
You need a C++ compiler that supports the C++17 standard, such as `g++`.

### 1. Compilation
Navigate to the root directory of the project (`tic-tac-toe-oop/`) in your terminal and run the following command:

```sh
g++ src/*.cpp -Iinclude -o tictactoe -std=c++17

```

### 2. Run the compiled code
Navigate to the root directory of the project (`tic-tac-toe-oop/`) in your terminal and run the following command:

```sh
./tictactoe

```
----




