#pragma once
#include "boardBuilder.h"

struct Log {
  Position positionInfo;
  Ship shipInfo;
};

void reloadShips();
void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void printShipsLoad(Ship ships[], unsigned typesCount);
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], Ship ships[],
               unsigned typesCount);
void printShipLog(int id);
void removeShip(int currentId, int board[BOARD_SIZE][BOARD_SIZE]);
void editShip(int board[BOARD_SIZE][BOARD_SIZE]);