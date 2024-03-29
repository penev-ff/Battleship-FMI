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
* Drawing board and other useful board functions
*
*/

#include "./board.h"
#include <iostream>

void clearBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (unsigned row = 0; row < BOARD_SIZE; ++row) {
    for (unsigned col = 0; col < BOARD_SIZE; ++col) {
      board[row][col] = 0;
    }
  }
}

void printRowSeparator(char separateSymbol) {
  for (int i = 0; i < 45; ++i) {
    std::cout << separateSymbol;
  }
  std::cout << std::endl;
}

void printBoard(int board[BOARD_SIZE][BOARD_SIZE], bool isHid) {
  // Printing the initial row with letters (A-J)
  printRowSeparator('-');
  // Empty edge (calibration)
  std::cout << "|   |";
  for (int i = 0; i < 10; ++i) {
    std::cout << " " << (char)('A' + i) << " |";
  }
  std::cout << std::endl;
  printRowSeparator('-');

  // Printing each row (first column is always a board index digit (0-9))
  for (int row = 0; row < BOARD_SIZE; ++row) {
    std::cout << "|";
    for (int col = 0; col < BOARD_SIZE + 1; ++col) {
      if (col == 0) {
        std::cout << " " << row << " |";
      } else {
        int placeHolder = board[row][col - 1];
        char dynamicSymbol;
        switch (placeHolder) {
        case 0:
          dynamicSymbol = '~';
          break;
        case 1:
          if (!isHid) {
            dynamicSymbol = 'S';
          } else {
            dynamicSymbol = '~';
          }
          break;
        case 2:
          dynamicSymbol = '#';
          break;
        case -1:
          dynamicSymbol = 'X';
          break;
        default:
          dynamicSymbol = '?';
          break;
        }
        std::cout << " " << dynamicSymbol << " |";
      }
    }
    std::cout << std::endl;
    printRowSeparator('-');
  }
}