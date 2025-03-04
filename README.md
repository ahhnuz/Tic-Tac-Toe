# Tic-Tac-Toe: A Classic Game with Persistent Data

Welcome to the Tic-Tac-Toe project! This is a simple yet engaging implementation of the classic game, written in C, with a twist: it remembers your progress!

## What is Tic-Tac-Toe?

Tic-Tac-Toe is a timeless game of strategy. Two players take turns marking spaces in a 3x3 grid. The goal? To get three of your marks (either 'X' or 'O') in a row – horizontally, vertically, or diagonally.

## Features

* **Persistent Game Data:**
    * Your win counts and the number of games played are stored in `tic_tac_toe_data.txt`, so you can track your progress across multiple sessions.
    * The final state of each game board is recorded in `tic_tac_toe_board.txt`, providing a history of your games.
* **Simple C Implementation:** The game is built using a straightforward 2D character array (`board[3][3]`) for the game board.
* **Win and Draw Detection:** The program efficiently checks for winning and draw conditions.
* **File I/O:** Utilizes `fopen()`, `fscanf()`, `fprintf()`, and `fclose()` for robust file handling.

## How it Works

1.  **Game Logic:**
    * The `board[3][3]` array stores the current state of the game.
    * `currentplayer` keeps track of the current player's turn.
    * `checkwin()` determines if a player has won.
    * `checkdraw()` checks if the game is a draw.

2.  **Data Persistence:**
    * `loadgamedata()` loads game statistics from `tic_tac_toe_data.txt` when the program starts.
    * `savegamedata()` updates the game statistics in `tic_tac_toe_data.txt` after each game.
    * `displayboard()` appends the final game board state to `tic_tac_toe_board.txt`.

## Getting Started

1.  **Compile:** Use a C compiler (like GCC) to compile the source code.
2.  **Run:** Execute the compiled program.
3.  **Play:** Follow the on-screen prompts to play the game.

## Files

* `tic_tac_toe_data.txt`: Stores game statistics (win counts and game count).
* `tic_tac_toe_board.txt`: Stores the final board state of each game.

Enjoy the game!
