#pragma once

bool insideBoardCheck(const Coordinate position, const Ship selectedShip);
bool positionValidation(int board[BOARD_SIZE][BOARD_SIZE], Coordinate position,
                        Ship selectedShip);

