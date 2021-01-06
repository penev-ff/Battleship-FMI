#include "../board/board.h"
#include <fstream>
#include <iostream>
#include <limits>

const unsigned MAX_LINE_SIZE = 15;

void corruptedFileError() {
  std::cout << "Error: Your preBoardEntries file is corrupted." << std::endl;
  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool printSavedBoards() {
  std::cout << "These are your preload saved boards:" << std::endl;

  std::ifstream entries;
  entries.open("preload/preBoardEntries.txt", std::ios::in);

  if (!entries.is_open()) {
    corruptedFileError();
    return false;
  }

  char boardEntrie[MAX_LINE_SIZE] = "";
  while (entries.getline(boardEntrie, MAX_LINE_SIZE)) {
    std::cin.clear();
    if (boardEntrie[0] != '\0') {
      std::cout << boardEntrie << std::endl;
    }
  }
  return true;
}

bool loadBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  bool loadPreBoardEntries = printSavedBoards();
  if (!loadPreBoardEntries) {
    return false;
  }

  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return true;
}