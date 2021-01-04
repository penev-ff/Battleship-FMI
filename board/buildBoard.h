#pragma once
#include "boardBuilder.h"

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void printShipsLoad(Ship ships[], const unsigned typesCount);
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], Ship ships[],
               const unsigned typesCount);