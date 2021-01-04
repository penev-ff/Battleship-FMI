#include <iostream>
#include <limits>
#include "buildBoard.h"
#include "positionValidator.h"

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  std::cout << "Time to build now - TODO\n";

  const unsigned typesCount = 4;
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

  bool allShipsPlaced;
  do {
    system("cls");
    std::cout << "This is your current board:" << std::endl;
    printBoard(board);
    std::cout << "\nSelect an option:\n"
              << "1. Place a ship\n"
              << "2. Edit a ship's position\n"
              << "3. Clear board\n"
              << std::endl;
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
        isNextOptionValid = true;
        break;
      case '3':
        // TODO - clear board
        isNextOptionValid = true;
        break;

      default:
        isNextOptionValid = false;
        std::cout << "Your option is invalid! \n"
                     "Please enter a valid option [1-2]:";
        break;
      }
    } while (!isNextOptionValid);

    int totalShipsCount =
        ships[0].count + ships[1].count + ships[2].count + ships[3].count;
    allShipsPlaced = totalShipsCount <= 0;
  } while (!allShipsPlaced);
}

void printShipsLoad(Ship ships[], const unsigned typesCount) {
  std::cout << "\nShips load:\n";
  std::cout << "No. Ship Name \t Ship Size \t Ships Count" << std::endl;
  for (unsigned i = 0; i < typesCount; i++) {
    std::cout << i + 1 << ".  " << ships[i].name << "\t\t" << ships[i].size
              << "\t\t" << ships[i].count << "\n";
  }
}

void placeShip(int board[BOARD_SIZE][BOARD_SIZE], Ship ships[],
               const unsigned typesCount) {

  system("cls");
  printBoard(board);
  printShipsLoad(ships, typesCount);

  char inputShipId;
  short selectedId;
  bool isIdValid;
  std::cout << "Select 5 if you want to return to board menu.\n";
  std::cout << "Select a ship's No. to place on the board:\n";
  std::cout << "-> ";
  do {
    std::cin >> inputShipId;
    std::cin.sync();

    if (inputShipId == '5') {
      return;
    }

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

    bool isPositionValid =
        positionValidation(board, position, ships[selectedId]);

    if (isPositionValid) {

      for (size_t i = 0; i < ships[selectedId].size; ++i) {
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (!isShipPlaced);
}