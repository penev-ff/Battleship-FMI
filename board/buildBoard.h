#pragma once
#include "boardBuilder.h"


struct Log {
  Position positionInfo;
  Ship shipInfo;
};

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void printShipsLoad(Ship ships[], const unsigned typesCount);
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], Ship ships[],
               const unsigned typesCount);
void printShipLog(int id);
void removeShip(const int currentId, int board[BOARD_SIZE][BOARD_SIZE]);
void editShip(int board[BOARD_SIZE][BOARD_SIZE]);