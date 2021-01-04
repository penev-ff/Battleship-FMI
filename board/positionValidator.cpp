#include "./boardBuilder.h"
#include "./positionValidator.h"

bool insideBoardCheck(const Coordinate position, const Ship selectedShip) {
  switch (position.direction) {
  case LEFT:
    if (position.col < selectedShip.size - 1) {
      return false;
    }
    break;
  case RIGHT:
    if (position.col + (selectedShip.size - 1) > 9) {
      return false;
    }
    break;
  case UP:
    if (position.row < selectedShip.size - 1) {
      return false;
    }
    break;
  case DOWN:
    if (position.row + (selectedShip.size - 1) > 9) {
      return false;
    }
    break;
  default:
    return false;
  }

  return true;
}

bool positionValidation(int board[BOARD_SIZE][BOARD_SIZE], Coordinate position,
                        Ship selectedShip) {

  // Is ship inside the board check
  bool isInsideBoard = insideBoardCheck(position, selectedShip);

  if (!isInsideBoard) {
    return false;
  }

  switch (position.direction) {
  case LEFT: {
    // Check Right Bound
    int shipStart = position.col;
    if (shipStart < BOARD_SIZE - 1) {
      if (board[position.row][shipStart + 1] == 1) {
        return false;
      }

      if (position.row > 0) {
        if (board[position.row - 1][shipStart + 1] == 1) {
          return false;
        }
      }

      if (position.row < BOARD_SIZE - 1) {
        if (board[position.row + 1][shipStart + 1] == 1) {
          return false;
        }
      }
    }

    // Check the two sides next to the ship
    for (int i = 0; i < selectedShip.size; i++) {
      if (board[position.row][position.col - i] == 1) {
        return false;
      }

      if (position.row > 0) {
        if (board[position.row - 1][position.col - i] == 1) {
          return false;
        }
      }

      if (position.row < BOARD_SIZE - 1) {
        if (board[position.row + 1][position.col - i] == 1) {
          return false;
        }
      }
    }

    // Check left bound
    int shipEnd = position.col - selectedShip.size + 1;

    if (shipEnd > 0) {
      if (board[position.row][shipEnd - 1] == 1) {
        return false;
      }

      if (position.row > 0) {
        if (board[position.row - 1][shipEnd - 1] == 1) {
          return false;
        }
      }
      if (position.row < BOARD_SIZE - 1) {
        if (board[position.row + 1][shipEnd - 1] == 1) {
          return false;
        }
      }
    }
  } break;

  case RIGHT: {
    // Check Left Bound
    int shipStart = position.col;
    if (shipStart > 0) {
      if (board[position.row][shipStart - 1] == 1) {
        return false;
      }

      if (position.row > 0) {
        if (board[position.row - 1][shipStart - 1] == 1) {
          return false;
        }
      }
      if (position.row < BOARD_SIZE - 1) {
        if (board[position.row + 1][shipStart - 1] == 1) {
          return false;
        }
      }
    }

    // Check the two sides next to the ship
    for (int i = 0; i < selectedShip.size; i++) {
      if (board[position.row][position.col + i] == 1) {
        return false;
      }

      if (position.row > 0) {
        if (board[position.row - 1][position.col + i] == 1) {
          return false;
        }
      }

      if (position.row < BOARD_SIZE - 1) {
        if (board[position.row + 1][position.col + i] == 1) {
          return false;
        }
      }
    }

    // Check right bound
    int shipEnd = position.col + selectedShip.size - 1;
    if (shipEnd < BOARD_SIZE - 1) {
      if (board[position.row][shipEnd + 1] == 1) {
        return false;
      }

      if (position.row > 0) {
        if (board[position.row - 1][shipEnd + 1] == 1) {
          return false;
        }
      }

      if (position.row < BOARD_SIZE - 1) {
        if (board[position.row + 1][shipEnd + 1] == 1) {
          return false;
        }
      }
    }
  } break;

  case UP: {
    // Check Lower Bound
    int shipStart = position.row;
    if (shipStart < BOARD_SIZE - 1) {
      if (board[shipStart + 1][position.col] == 1) {
        return false;
      }

      if (position.col > 0) {
        if (board[shipStart + 1][position.col - 1] == 1) {
          return false;
        }
      }
      if (position.col < BOARD_SIZE - 1) {
        if (board[shipStart + 1][position.col + 1] == 1) {
          return false;
        }
      }
    }

    // Check the two sides next to the ship
    for (int i = 0; i < selectedShip.size; i++) {
      if (board[position.row - i][position.col] == 1) {
        return false;
      }

      if (position.col > 0) {
        if (board[position.row - i][position.col - 1] == 1) {
          return false;
        }
      }

      if (position.col < BOARD_SIZE - 1) {
        if (board[position.row - i][position.col + 1] == 1) {
          return false;
        }
      }
    }

    // Check upper bound
    int shipEnd = position.row - selectedShip.size + 1;
    if (shipEnd > 0) {
      if (board[shipEnd - 1][position.col] == 1) {
        return false;
      }

      if (position.col > 0) {
        if (board[shipEnd - 1][position.col - 1] == 1) {
          return false;
        }
      }

      if (position.col < BOARD_SIZE - 1) {
        if (board[shipEnd - 1][position.col + 1] == 1) {
          return false;
        }
      }
    }
  } break;

  case DOWN: {
    // Check Upper Bound
    int shipStart = position.row;
    if (shipStart > 0) {
      if (board[shipStart - 1][position.col] == 1) {
        return false;
      }

      if (position.col > 0) {
        if (board[shipStart - 1][position.col - 1] == 1) {
          return false;
        }
      }
      if (position.col < BOARD_SIZE - 1) {
        if (board[shipStart - 1][position.col + 1] == 1) {
          return false;
        }
      }
    }

    // Check the two sides next to the ship
    for (int i = 0; i < selectedShip.size; i++) {
      if (board[position.row + i][position.col] == 1) {
        return false;
      }

      if (position.col > 0) {
        if (board[position.row + i][position.col - 1] == 1) {
          return false;
        }
      }

      if (position.col < BOARD_SIZE - 1) {
        if (board[position.row + i][position.col + 1] == 1) {
          return false;
        }
      }
    }

    // Check upper bound
    int shipEnd = position.row + selectedShip.size - 1;

    if (shipEnd < BOARD_SIZE - 1) {
      if (board[shipEnd + 1][position.col] == 1) {
        return false;
      }

      if (position.col > 0) {
        if (board[shipEnd + 1][position.col - 1] == 1) {
          return false;
        }
      }

      if (position.col < BOARD_SIZE - 1) {
        if (board[shipEnd + 1][position.col + 1] == 1) {
          return false;
        }
      }
    }
  } break;
  
  default:
    return false;
  }

  return true;
}
