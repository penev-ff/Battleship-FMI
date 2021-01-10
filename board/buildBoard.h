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
* Header with functions declarations for buildBoard.cpp
*
*/

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