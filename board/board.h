#pragma once

const unsigned BOARD_SIZE = 10;
void clearBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void printRowSeparator(char separateSymbol);
void printBoard(int board[BOARD_SIZE][BOARD_SIZE], bool isHid = false);
