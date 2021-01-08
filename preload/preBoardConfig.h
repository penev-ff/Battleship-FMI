#pragma once
#include "../board/buildBoard.h"
#include <vector>

void saveBoard(std::vector<Log> shipsLog);
bool loadEntries();
void corruptedFileErrors(int errorCode);
bool loadBoard(int board[BOARD_SIZE][BOARD_SIZE]);