#include "./preBoardConfig.h"
#include "../board/board.h"
#include "../board/buildBoard.h"
#include "../board/positionValidator.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

std::vector<std::string> loadedEntries;
const unsigned ALL_SHIPS_COUNT = 10;

void corruptedFileErrors(int errorCode) {
  std::string errorMessage;

  switch (errorCode) {
  case 1:
    errorMessage = "Error: Your preBoardEntries file is corrupted.\n";
    break;
  case 2:
    errorMessage = "Failed to load a board.\nInvalid selection\n";
    break;
  case 3:
    errorMessage = "Error: cannot save this board.\n";
    break;
  case 4:
    errorMessage = "Error: this board is invalid.\n";
    break;
  case 5:
    errorMessage = "There are no saved boards!\n";
    break;
  default:
    errorMessage = "Error with loading board.\n";
    break;
  }

  std::cout << errorMessage << std::endl;
  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void saveBoard(std::vector<Log> shipsLog) {
  std::cout << "Enter board name:\n";
  std::string boardName = "default";

  do {
    std::cin >> boardName;
    if (boardName.size() <= 3) {
      std::cout << "Name size should be at least 3.\n";
    }
  } while (boardName.size() <= 3);

  boardName += ".txt";

  std::ofstream save;
  save.open("preload/" + boardName, std::ios_base::app);

  if (!save.is_open()) {
    corruptedFileErrors(3);
    return;
  }

  for (auto log : shipsLog) {
    std::string info = std::to_string(log.positionInfo.row) + " " +
                       std::to_string(log.positionInfo.col) + " " +
                       std::to_string(log.positionInfo.direction) + " " +
                       std::to_string(log.shipInfo.size) + " " +
                       std::to_string(log.shipInfo.count) + "\n";
    save << info;
  }

  save.close();

  std::ofstream entries;
  entries.open("preload/preBoardEntries.txt", std::ios::app);
  if (!entries.is_open()) {
    corruptedFileErrors(1);
    return;
  }

  entries << "\n";
  entries << boardName;

  entries.close();

  std::cout << "Board saved successfully!\n";
  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool loadEntries() {
  std::cout << "These are your preload saved boards:" << std::endl;

  std::ifstream entries;
  entries.open("preload/preBoardEntries.txt", std::ios::in);

  if (!entries.is_open()) {
    corruptedFileErrors(1);
    return false;
  }

  std::string boardEntrie;
  while (getline(entries, boardEntrie)) {
    std::cin.clear();

    if (boardEntrie[0] != '\0') {
      loadedEntries.push_back(boardEntrie);
    }
  }

  entries.close();
  return true;
}

bool loadBoard(int board[BOARD_SIZE][BOARD_SIZE]) {

  bool isLoadSuccessfull;

  if (loadedEntries.size() <= 0) {
    isLoadSuccessfull = loadEntries();
    if (!isLoadSuccessfull) {
      return false;
    }
  }

  for (unsigned i = 0; i < loadedEntries.size(); i++) {
    std::string loadedBoard = loadedEntries[i];

    if (!(loadedBoard.find(".txt") != std::string::npos)) {
      corruptedFileErrors(1);
      return false;
    }

    std::cout << i << '.';
    int prtIndex = 0;
    while (loadedBoard[prtIndex] != '.') {
      std::cout << loadedBoard[prtIndex];
      ++prtIndex;
    }
    std::cout << std::endl;
  }

  if (loadedEntries.size() <= 0) {
    corruptedFileErrors(5);
    return false;
  }

  char selectedIndexChar;
  std::cout << "Select a board to load:\n"
            << "-> ";
  std::cin >> selectedIndexChar;
  std::cin.sync();
  bool isIndexValid =
      selectedIndexChar >= '0' &&
      selectedIndexChar <= (char)('0' + (loadedEntries.size() - 1));

  if (!isIndexValid) {
    corruptedFileErrors(2);
    return false;
  }

  const unsigned boardIndex = selectedIndexChar - '0';
  std::string boardName = loadedEntries[boardIndex];

  std::ifstream choseBoard;
  choseBoard.open("preload/" + boardName, std::ios::in);
  if (!choseBoard.is_open()) {
    corruptedFileErrors(0);
    return false;
  }

  // Validating
  clearBoard(board);
  bool isLoadedBoardValid;
  std::string line;
  unsigned lineCount = 0;
  while (getline(choseBoard, line) && lineCount <= 9) {
    if ((line == "" && lineCount <= 9) || line.size() < 9) {
      corruptedFileErrors(4);
      clearBoard(board);
      return false;
    }

    Position posToValidate;
    posToValidate.row = line[0] - '0';
    posToValidate.col = line[2] - '0';
    posToValidate.direction = line[4] - '0';

    Ship shipToValidate;
    shipToValidate.size = line[6] - '0';
    shipToValidate.count = line[8] - '0';

    bool isPositionValid =
        positionValidation(board, posToValidate, shipToValidate);

    if (!isPositionValid) {
      corruptedFileErrors(4);
      clearBoard(board);
      return false;
    } else {
      for (unsigned i = 0; i < shipToValidate.size; ++i) {
        if (posToValidate.direction == LEFT) {
          board[posToValidate.row][posToValidate.col - i] = 1;
        } else if (posToValidate.direction == RIGHT) {
          board[posToValidate.row][posToValidate.col + i] = 1;
        } else if (posToValidate.direction == UP) {
          board[posToValidate.row - i][posToValidate.col] = 1;
        } else if (posToValidate.direction == DOWN) {
          board[posToValidate.row + i][posToValidate.col] = 1;
        }
      }
    }
    ++lineCount;
  }

  choseBoard.close();

  isLoadSuccessfull = true;
  std::cout << "Board loaded successfully!" << std::endl;
  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return isLoadSuccessfull;
}