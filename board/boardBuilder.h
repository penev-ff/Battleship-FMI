/**
*  
* Solution to course project # 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 62535
* @compiler GCC
*
* Header with functions declarations for boardBuilder.cpp
*
*/

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
