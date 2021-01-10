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
* Header file with functions declarations for positionValidator.cpp
*
*/

#pragma once
#include "./boardBuilder.h"
#include "./positionValidator.h"

bool insideBoardCheck(Position position, Ship selectedShip);
bool positionValidation(int board[BOARD_SIZE][BOARD_SIZE], Position position,
                        Ship selectedShip);
