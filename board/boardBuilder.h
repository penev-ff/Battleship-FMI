#pragma once
#include "./board.h"

enum direction { LEFT, RIGHT, UP, DOWN };

struct Position {
  short row, col;
  short direction;
};

struct Ship {
  char name[15] = "";
  int size, count;
};

void printBoardBuilderMenu();
void boardBuilderMenu(int board[BOARD_SIZE][BOARD_SIZE]);
