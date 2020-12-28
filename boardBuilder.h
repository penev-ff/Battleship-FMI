#pragma once
#include <iostream>
#include "board.h"

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void printBoardBuilderMenu();
void boardBuilderMenu(int board[BOARD_SIZE][BOARD_SIZE]);

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]){
    std::cout << "Time to build now - TODO\n";
    //Fill with nulls (dynamic symbol = '~');
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (i == j)
            {
                board[i][i] = 1;
            } else {
              board[i][j] = 0;
            }
        }
    }

    board[0][0] = 2;
    board[0][5] = -1;
}

void boardBuilderMenu(int board[BOARD_SIZE][BOARD_SIZE]) {

  printBoardBuilderMenu();

  std::cout << "Please select an option: ";
  bool isOptionValid = false;
  char option;
  do {
    std::cin >> option;
    std::cin.sync();
    switch (option) {
    case '1':
    //TODO - Build Now
    buildBoard(board);
    isOptionValid = true;
      break;
    case '2':
    //TODO - Load from file
    std::cout << "Time to load a board now - TODO";
    isOptionValid = true;
      break;

    default:
      system("cls");
      printBoardBuilderMenu();
      isOptionValid = false;
      std::cout << "Your option is invalid! \n"
                   "Please enter a valid option [1-2]:"
                << std::endl;
      break;
    }
  } while (!isOptionValid);
}

void printBoardBuilderMenu() {
  std::cout << "Do you prefer to build now or load a board configuration?" << std::endl;
  std::cout << "1. Build now \n"
               "2. Load a board" << std::endl;
}