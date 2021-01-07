#pragma once
#include <vector>
#include "../board/buildBoard.h"

void saveBoard(std::vector<Log> shipsLog);
bool loadEntries();
void corruptedFileError();
bool loadBoard(int board[BOARD_SIZE][BOARD_SIZE]);