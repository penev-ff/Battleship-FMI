#pragma once
#include "board.h"
#include <iostream>
#include <limits>

struct Coordinate {
  short row, col;
  short direction;
};

struct Ship {
  char name[15] = "";
  int size, count;
};

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void printBoardBuilderMenu();
void boardBuilderMenu(int board[BOARD_SIZE][BOARD_SIZE]);
void printShipsLoad(Ship ships[], const unsigned typesCount);
bool isPositionValid(int board[BOARD_SIZE][BOARD_SIZE], Coordinate position,
                     Ship selectedShip);
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], Ship ships[],
               const unsigned typesCount);

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  std::cout << "Time to build now - TODO\n";

  unsigned typesCount = 4;
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
    std::cout << "\nSelect an option:\n"
              << "1. Place a ship\n"
              << "2. Edit a ship's position" << std::endl;
    std::cout << "-> ";
    char nextOption;
    bool isNextOptionValid = false;
    do {
      std::cin >> nextOption;
      std::cin.sync();

      switch (nextOption) {
      case '1':
        // TODO - add ship to the board
        placeShip(board, ships, typesCount);
        isNextOptionValid = true;
        break;
      case '2':
        // TODO - edit ship's position
        break;

      default:
        isNextOptionValid = false;
        std::cout << "Your option is invalid! \n"
                     "Please enter a valid option [1-2]:";
        break;
      }
    } while (!isNextOptionValid);

    int totalShipsCount = ships[0].count + ships[1].count + 
                          ships[2].count + ships[3].count;
    allShipsPlaced = totalShipsCount <= 0;
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
  std::cout << "\nShips load:\n";
  std::cout << "No. Ship Name \t Ship Size \t Ships Count" << std::endl;
  for (unsigned i = 0; i < typesCount; i++) {
    std::cout << i + 1 << ".  " << ships[i].name << "\t\t" << ships[i].size
              << "\t\t" << ships[i].count << "\n";
  }
}

bool isPositionValid(int board[BOARD_SIZE][BOARD_SIZE], Coordinate position,
                     Ship selectedShip) {

  //Is ship outside of the board check
  enum direction { LEFT, RIGHT, UP, DOWN };

  switch (position.direction) {
  case LEFT:
    if (position.col < selectedShip.size - 1) {
      return false;
    }
    break;
  case RIGHT:
    if (position.col + (selectedShip.size - 1) > 9) {
      return false;
    }
    break;
  case UP:
    if (position.row < selectedShip.size - 1) {
      return false;
    }
    break;
  case DOWN:
    if (position.row + (selectedShip.size - 1) > 9) {
      return false;
    }
    break;
  default:
    return false;
    break;
  }

  //Other ships collision check
  for (size_t i = 0; i < selectedShip.size; ++i) {
    if (position.direction == LEFT) {
      if (board[position.row][position.col - i] == 1) {
        return false;
      }
    } else if (position.direction == RIGHT) {
      if (board[position.row][position.col + i] == 1) {
        return false;
      }
    } else if (position.direction == UP) {
      if (board[position.row - i][position.col] == 1) {
        return false;
      }

    } else if (position.direction == DOWN) {
      if (board[position.row + i][position.col] == 1) {
        return false;
      }
    }
  }

  // Placing the ship after inside board check and ships collision check
  for (size_t i = 0; i < selectedShip.size; ++i) {
    if (position.direction == LEFT) {
      board[position.row][position.col - i] = 1;
    } else if (position.direction == RIGHT) {
      board[position.row][position.col + i] = 1;
    } else if (position.direction == UP) {
      board[position.row - i][position.col] = 1;
    } else if (position.direction == DOWN) {
      board[position.row + i][position.col] = 1;
    }
  }
  return true;
}

void placeShip(int board[BOARD_SIZE][BOARD_SIZE], Ship ships[],
               const unsigned typesCount) {

  system("cls");
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
        std::cout << "\nThere are no " << ships[selectedId].name << "s left.\n";
        std::cout << "Please select another one:";
        isIdValid = false;
      }
    }

  } while (!isIdValid);

  bool isShipPlaced = false;

  do {
    system("cls");
    printBoard(board);

    std::cout << "You have selected ship: " << ships[selectedId].name
              << " with size " << ships[selectedId].size << "\n";

    std::cout << "Enter board coordinates to place it:\n";
    Coordinate position;

    char letterCoordinate;
    std::cout << "Capital letter: ";
    do {
      std::cin >> letterCoordinate;
      std::cin.sync();

      if (letterCoordinate < 'A' || letterCoordinate > 'J') {
        std::cout
            << "Invalid input! Please enter a valid capital letter [A, J]: ";
      }

    } while (letterCoordinate < 'A' || letterCoordinate > 'J');

    char digitCoordinateChar;
    std::cout << "Digit: ";
    do {
      std::cin >> digitCoordinateChar;
      std::cin.sync();

      if (digitCoordinateChar < '0' || digitCoordinateChar > '9') {
        std::cout << "Invalid input! Please enter a valid digit [0, 9]: ";
      }

    } while (digitCoordinateChar < '0' || digitCoordinateChar > '9');

    int digitCoordinate = digitCoordinateChar - '0';

    std::cout << "Enter a direction (Left: 0, Right: 1, Up: 2, Down: 3): ";
    char directionChar;
    do {
      std::cin >> directionChar;
      std::cin.sync();

      if (directionChar < '0' || directionChar > '3') {
        std::cout << "Invalid input! Please enter a valid direction [0, 3]\n"
                  << "(Left: 0, Right: 1, Up: 2, Down: 3): ";
      }

    } while (directionChar < '0' || directionChar > '3');

    short direction = directionChar - '0';

    int letterToColIndex = letterCoordinate - 'A';
    position.col = letterToColIndex;
    position.row = digitCoordinate;
    position.direction = direction;

    bool isPlaced = isPositionValid(board, position, ships[selectedId]);

    if (isPlaced) {
      system("cls");
      printBoard(board);
      std::cout << ships[selectedId].name << " placed successfully!\n";
      ships[selectedId].count -= 1;
      isShipPlaced = true;
    } else {
      std::cout << "You can't place the selected ship on this position.\n";
      std::cout << "Choose another position to place it.\n";
    }

    std::cout << "Press ENTER to continue... " << std::flush;
    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
  } while (!isShipPlaced);
}