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
* Header with functions declarations for preBoardConfig.cpp
*
*/

#pragma once
#include "../board/buildBoard.h"
#include <vector>

void saveBoard(std::vector<Log> shipsLog);
bool loadEntries();
void corruptedFileErrors(int errorCode);
bool loadBoard(int board[BOARD_SIZE][BOARD_SIZE]);