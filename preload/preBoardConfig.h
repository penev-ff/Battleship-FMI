#pragma once
#include <vector>
#include "../board/board.h"

bool loadEntries();
void corruptedFileError();
bool loadBoard(int board[BOARD_SIZE][BOARD_SIZE]);