#include "buildBoard.h"
#include "positionValidator.h"
#include "../preload/preBoardConfig.h"
#include <iostream>
#include <limits>
#include <vector>

const unsigned ShipTypesCount = 4;
std::vector<Log> shipsLog;
Ship ships[ShipTypesCount] = {{"Cruiser", 6, 1},
                              {"Battleship", 4, 2},
                              {"Submarine", 3, 3},
                              {"Destroyer", 2, 4}};

void buildBoard(int board[BOARD_SIZE][BOARD_SIZE]) {

  shipsLog.clear();
  ships[0].count = 1;
  ships[1].count = 2;
  ships[2].count = 3;
  ships[3].count = 4;

  // Fill empty board cells with '~'.
  clearBoard(board);

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
        placeShip(board, ships, ShipTypesCount);
        isNextOptionValid = true;
        break;
      case '2':
        if (shipsLog.size() > 0) {
          editShip(board);
        } else {
          std::cout << "There are no ships for editing!" << std::endl;
          std::cout << "Press ENTER to continue... " << std::flush;
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        isNextOptionValid = true;
        break;
      case '3':
        clearBoard(board);
        shipsLog.clear();
        ships[0].count = 1;
        ships[1].count = 2;
        ships[2].count = 3;
        ships[3].count = 4;
        isNextOptionValid = true;
        break;

      default:
        isNextOptionValid = false;
        std::cout << "Your option is invalid! \n"
                     "Please enter a valid option [1-3]:";
        break;
      }
    } while (!isNextOptionValid);

    int totalShipsCount =
        ships[0].count + ships[1].count + ships[2].count + ships[3].count;
    allShipsPlaced = totalShipsCount <= 0;
  } while (!allShipsPlaced);

  system("cls");
  std::cout << "Do you want to save this board?\n";
  std::cout << "1. Yes\n"
               "2. No\n"; 

  char saveOption;
  std::cin >> saveOption;
  std::cin.sync();
  if (saveOption == '1')
  {
    saveBoard(shipsLog);
  }
  
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

  char letterCoordinate, digitCoordinateChar, directionChar;
  int digitCoordinate;
  Position position;

  bool isShipPlaced = false;
  bool reselect = false;

  do
  {
  reselect = false;
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
      std::cout << "\nInvalid option selected. Please select a valid one "
                   "[1,5]:";
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


    system("cls");
    printBoard(board);

    std::cout << "You have selected ship: " << ships[selectedId].name
              << " with size " << ships[selectedId].size << "\n";

    std::cout << "Enter board coordinates to place it:\n";
    std::cout << "Enter Q to quit.\n";

    std::cout << "Capital letter: ";

    do {
      std::cin >> letterCoordinate;
      std::cin.sync();

      if (letterCoordinate == 'Q')
      {
        reselect = true; 
        break;
      }

      if (letterCoordinate < 'A' || letterCoordinate > 'J') {
        std::cout
            << "Invalid input! Please enter a valid capital letter [A, J]: ";
      }

    } while (letterCoordinate < 'A' || letterCoordinate > 'J');

    if (reselect)
    {
      continue;
    }
    
    digitCoordinateChar;
    std::cout << "Digit: ";
    do {
      std::cin >> digitCoordinateChar;
      std::cin.sync();

      if (digitCoordinateChar < '0' || digitCoordinateChar > '9') {
        std::cout << "Invalid input! Please enter a valid digit [0, 9]: ";
      }

    } while (digitCoordinateChar < '0' || digitCoordinateChar > '9');

    digitCoordinate = digitCoordinateChar - '0';

    std::cout << "Enter a direction (Left: 0, Right: 1, Up: 2, Down: 3): ";
    directionChar;
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

      for (unsigned i = 0; i < ships[selectedId].size; ++i) {
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
      Log lastPlacedShip = {position, ships[selectedId]};
      shipsLog.push_back(lastPlacedShip);

      ships[selectedId].count -= 1;
      isShipPlaced = true;
    } else {
      std::cout << "You can't place the selected ship on this position.\n";
    }

    std::cout << "Press ENTER to continue... " << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (!isShipPlaced);
}

void printShipLog(const int id) {
  Log curLog = shipsLog[id];
  std::cout << "Ship information:\n";
  std::cout << "Id: " << id << std::endl;
  std::cout << "Name: " << curLog.shipInfo.name
            << ", size: " << curLog.shipInfo.size << std::endl;
  std::cout << "Position information:\n";
  std::cout << "Coordinates: " << (char)('A' + curLog.positionInfo.col)
            << curLog.positionInfo.row << '\n';
  std::cout << "Direction: ";
  switch (curLog.positionInfo.direction) {
  case 0:
    std::cout << "LEFT";
    break;
  case 1:
    std::cout << "RIGHT";
    break;
  case 2:
    std::cout << "UP";
    break;
  case 3:
    std::cout << "DOWN";
    break;
  }
  std::cout << std::endl;
}

void removeShip(const int currentId, int board[BOARD_SIZE][BOARD_SIZE]) {

  const unsigned shipSize = shipsLog[currentId].shipInfo.size;
  const unsigned shipDirection = shipsLog[currentId].positionInfo.direction;
  const unsigned posRow = shipsLog[currentId].positionInfo.row;
  const unsigned posCol = shipsLog[currentId].positionInfo.col;

  for (unsigned i = 0; i < shipSize; ++i) {
    if (shipDirection == LEFT) {
      board[posRow][posCol - i] = 0;
    } else if (shipDirection == RIGHT) {
      board[posRow][posCol + i] = 0;
    } else if (shipDirection == UP) {
      board[posRow - i][posCol] = 0;
    } else if (shipDirection == DOWN) {
      board[posRow + i][posCol] = 0;
    }
  }

  if (shipSize == 6) {
    ships[0].count += 1;
  } else if (shipSize == 4) {
    ships[1].count += 1;
  } else if (shipSize == 3) {
    ships[2].count += 1;
  } else if (shipSize == 2) {
    ships[3].count += 1;
  }

  shipsLog.erase(shipsLog.begin() + currentId);
}

void editShip(int board[BOARD_SIZE][BOARD_SIZE]) {

  bool isShipSelected;
  int currentId = 0;
  do {
    system("cls");
    printBoard(board);
    printShipLog(currentId);

    std::cout << "1. Remove this ship\n"
              << "2. Next ship's ID\n"
              << "3. Previous ship's ID\n"
              << "4. Back to board menu" << std::endl;

    std::cout << "Select an option: ";

    char option;
    std::cin >> option;
    std::cin.sync();

    switch (option) {

    case '1':
      removeShip(currentId, board);
      isShipSelected = true;
      break;

    case '2':
      if (currentId < shipsLog.size() - 1) {
        currentId += 1;
      }
      break;

    case '3':
      if (currentId > 0) {
        currentId -= 1;
      }
      break;

    case '4':
      return;
    }
  } while (!isShipSelected);
}
