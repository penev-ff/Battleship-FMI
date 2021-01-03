#pragma once
#include "./board.h"

enum direction { LEFT, RIGHT, UP, DOWN };

struct Coordinate {
  short row, col;
  short direction;
};

struct Ship {
  char name[15] = "";
  int size, count;
};

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void printBoardBuilderMenu();
void boardBuilderMenu(int board[BOARD_SIZE][BOARD_SIZE]);
void printShipsLoad(Ship ships[], const unsigned typesCount);
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], Ship ships[],
               const unsigned typesCount);
