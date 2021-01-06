#include "./boardBuilder.h"
#include "../preload/preBoardConfig.h"
#include "./buildBoard.h"
#include <iostream>
#include <limits>

void boardBuilderMenu(int board[BOARD_SIZE][BOARD_SIZE]) {

  printBoardBuilderMenu();

  std::cout << "Please select an option: ";
  bool isOptionValid;
  char option;
  do {
    std::cin >> option;
    std::cin.sync();
    switch (option) {
    case '1':
      buildBoard(board);
      isOptionValid = true;
      break;
    case '2': {
      // TODO - Load from file
      bool isLoaded = loadBoard(board);
      if (!isLoaded)
      {
        buildBoard(board);
      }
      isOptionValid = true;
    } break;

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
  std::cout << "Do you prefer to build now or load a board configuration?"
            << std::endl;
  std::cout << "1. Build now \n"
               "2. Load a board"
            << std::endl;
}
