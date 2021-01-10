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
* Header with functions declarations for board.cpp
*
*/

#pragma once

const unsigned BOARD_SIZE = 10;
void clearBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void printRowSeparator(char separateSymbol);
void printBoard(int board[BOARD_SIZE][BOARD_SIZE], bool isHid = false);
