#include "./preBoardConfig.h"
#include "../board/board.h"
#include "../board/buildBoard.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

std::vector<std::string> loadedEntries;
const unsigned ALL_SHIPS_COUNT = 10;

void saveBoard(std::vector<Log> shipsLog){
  std::cout << "Enter board name:\n";
  std::string boardName = "default";

  do
  {
    std::cin >> boardName;
    if (boardName.size() <= 3)
    {
      std::cout << "Name size should be at least 3.\n";
    }
  } while (boardName.size() <= 3);
  
  boardName += ".txt";
  
  std::ofstream save;
  save.open("preload/" + boardName, std::ios_base::app);

  if (!save.is_open())
  {
    std::cout << "Error: cannot save this board.";
    std::cout << "Press ENTER to continue... " << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
  }
  
  for (auto log : shipsLog)
  {
    std::string info = std::to_string(log.positionInfo.row) + " " +
                       std::to_string(log.positionInfo.col) + " " +
                       std::to_string(log.positionInfo.direction) + "\n";
    save << info;
  }

  save.close();

  std::ofstream entries;
  entries.open("preload/preBoardEntries.txt", std::ios::app);
  if (!entries.is_open()) {
    corruptedFileError();
    return;
  }

  entries << "\n";
  entries << boardName;

  entries.close();

  std::cout << "Board saved successfully!\n";
  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void corruptedFileError() {
  std::cout << "Error: Your preBoardEntries file is corrupted." << std::endl;
  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool loadEntries() {
  std::cout << "These are your preload saved boards:" << std::endl;

  std::ifstream entries;
  entries.open("preload/preBoardEntries.txt", std::ios::in);

  if (!entries.is_open()) {
    corruptedFileError();
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
    std::cout << i << '.';
    int prtIndex = 0;
    while (loadedBoard[prtIndex] != '.') {
      std::cout << loadedBoard[prtIndex];
      ++prtIndex;
    }
    std::cout << std::endl;
  }

  char selectedIndex;
  std::cout << "Select a board to load:\n"
            << "-> ";
  std::cin >> selectedIndex;
  std::cin.sync();
  if (selectedIndex < '0' || selectedIndex > (char)('0' + (loadedEntries.size() - 1))) {
    std::cout << "Failed to load a board.\n";
    std::cout << "Invalid selection\n";
    std::cout << "Press ENTER to continue... " << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    isLoadSuccessfull = false;
  }

  if (!isLoadSuccessfull)
  {
    return false;
  }


  std::cout << "Board loaded successfully!" << std::endl;
  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return isLoadSuccessfull;
}