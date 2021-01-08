#pragma once
#include "./boardBuilder.h"
#include "./positionValidator.h"

bool insideBoardCheck(Position position, Ship selectedShip);
bool positionValidation(int board[BOARD_SIZE][BOARD_SIZE], Position position,
                        Ship selectedShip);
