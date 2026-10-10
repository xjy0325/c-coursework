# Knight's Tour

## Description
Simulates a knight's tour on an 8x8 chessboard. Starting from each square, the knight makes greedy moves and the program reports the total number of moves possible before it gets stuck.

## Features
- Tries the tour from every starting square
- Greedy move strategy
- Prints the number of moves for each starting position

## How to Run
Compile with: gcc src/main.c src/knights_tour.c -Iinclude -o main
Then run: ./main

## Concepts
- 2D arrays and board representation
- Greedy algorithm
- Modular code with header files

## Files
- src/main.c — entry point
- src/knights_tour.c / include/knights_tour.h — tour logic
- flow chart.drawio.png — program flowchart