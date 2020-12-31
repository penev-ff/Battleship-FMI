#pragma once
#include <iostream>
#include "board.h"


struct Ship {
  char name[15] = "";
  int size, count;
};

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void printBoardBuilderMenu();
void boardBuilderMenu(int board[BOARD_SIZE][BOARD_SIZE]);
void printShipsLoad(Ship ships[], const unsigned typesCount);

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  system("cls");
  std::cout << "Time to build now - TODO\n";
  unsigned typesCount = 4;
  /*
  No. Class of ship Size
  0 	1xCruiser	     6
  1 	2xBattleship   4
  2 	3xSubmarine    3
  3 	4xDestroyer    2
  */
  Ship ships[typesCount] = {{"Cruiser", 6, 1},
                            {"Battleship", 4, 2},
                            {"Submarine", 3, 3},
                            {"Destroyer", 2, 4}};

  // Fill empty board cells with '~'.
  for (unsigned row = 0; row < BOARD_SIZE; ++row) {
    for (unsigned col = 0; col < BOARD_SIZE; ++col) {
      board[row][col] = 0;
    }
  }

  bool allShipsPlaced = false;
  do {
    system("cls");
    std::cout << "This is your current board:" << std::endl;
    printBoard(board);

    printShipsLoad(ships, typesCount);

    char inputShipId;
    short selectedId;
    bool isIdValid = true;
    std::cout << "Select a ship's No. to place on the board:";
    do {
      std::cin >> inputShipId;
      std::cin.sync();

      isIdValid = true;

      if (inputShipId < '1' || inputShipId > '4') {
        std::cout << "\nInvalid ship's No. selected. Please select a valid one "
                     "[1,4]:";
        isIdValid = false;
      } else {
        selectedId = (inputShipId - 1) - '0';
        if (ships[selectedId].count <= 0) {
          std::cout << "\nThere are no " << ships[selectedId].name
                    << "s left.\n";
          std::cout << "Please select another one:";
          isIdValid = false;
        }
      }

    } while (!isIdValid);

    std::cout << "You have selected ship: "
              << ships[selectedId].name << " with size "
              << ships[selectedId].size << "\n";

    std::cout << "Enter board coordinates to place it:";
    // TODO
    //Debug - remove it
    int stopClear = 0;
    std::cin >> stopClear;
    //
  
  } while (!allShipsPlaced);
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
      // TODO - Build Now
      buildBoard(board);
      isOptionValid = true;
      break;
    case '2':
      // TODO - Load from file
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
  std::cout << "Do you prefer to build now or load a board configuration?"
            << std::endl;
  std::cout << "1. Build now \n"
               "2. Load a board"
            << std::endl;
}

void printShipsLoad(Ship ships[], const unsigned typesCount) {
  std::cout << std::endl;
  std::cout << "No. Ship Name \t Ship Size \t Ships Count" << std::endl;
  for (unsigned i = 0; i < typesCount; i++) {
    std::cout << i + 1 << ".  " << ships[i].name << "\t\t" << ships[i].size
              << "\t\t" << ships[i].count << "\n";
  }
}