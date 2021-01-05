#pragma once
#include "./positionValidator.h"
#include "./boardBuilder.h"

bool insideBoardCheck(const Position position, const Ship selectedShip);
bool positionValidation(int board[BOARD_SIZE][BOARD_SIZE], Position position,
                        Ship selectedShip);
