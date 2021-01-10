/**
*  
* Solution to course project # 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 62535
* @compiler GCC
*
* Game mechanics
*
*/

#include "./game.h"
#include "../board/boardBuilder.h"
#include <iostream>
#include <limits>

void setDefaultPlayerName(char player1Name[], int id) {
  const unsigned defaultNameSize = 8;
  const char defaultName[defaultNameSize] = "Player ";

  for (size_t i = 0; i < defaultNameSize; i++) {
    player1Name[i] = defaultName[i];
  }

  player1Name[defaultNameSize - 1] = '0' + id;
  player1Name[defaultNameSize] = '\0';
}

void greetAndBuild(char playerName[], int board[BOARD_SIZE][BOARD_SIZE]) {
  system("cls");
  std::cout << "Hello, " << playerName << std::endl;
  std::cout << "It's your turn to build a board.\n";
  boardBuilderMenu(board);
}

void newGame() {
  const unsigned NAME_MAX_SIZE = 51;
  char player1Name[NAME_MAX_SIZE] = "";
  char player2Name[NAME_MAX_SIZE] = "";
  int player1Board[BOARD_SIZE][BOARD_SIZE];
  int player2Board[BOARD_SIZE][BOARD_SIZE];

  std::cout << "Please enter player 1 nickname: ";

  std::cin.getline(player1Name, NAME_MAX_SIZE);

  if (player1Name[0] == '\0') {
    setDefaultPlayerName(player1Name, 1);
  }

  greetAndBuild(player1Name, player1Board);

  system("cls");
  std::cout << "Please enter player 2 nickname: ";
  std::cin.getline(player2Name, NAME_MAX_SIZE);

  if (player2Name[0] == '\0') {
    setDefaultPlayerName(player2Name, 2);
  }

  greetAndBuild(player2Name, player2Board);

  game(player1Name, player1Board, player2Name, player2Board);
}

bool isGameOver(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (unsigned row = 0; row < BOARD_SIZE; row++) {
    for (unsigned col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == 1) {
        return false;
      }
    }
  }
  return true;
}

bool isShipSank(int opponentBoard[BOARD_SIZE][BOARD_SIZE], int attackRow,
                int attackCol) {
  for (int checkColR = attackCol + 1; checkColR <= 9; checkColR++) {
    int toCheck = opponentBoard[attackRow][checkColR];
    if (toCheck == 0 || toCheck == -1) {
      break;
    }
    if (toCheck == 1) {
      return false;
    }
  }

  for (int checkColL = attackCol - 1; checkColL >= 0; checkColL--) {
    int toCheck = opponentBoard[attackRow][checkColL];
    if (toCheck == 0 || toCheck == -1) {
      break;
    }

    if (toCheck == 1) {
      return false;
    }
  }

  for (int checkRowU = attackRow - 1; checkRowU >= 0; checkRowU--) {
    int toCheck = opponentBoard[checkRowU][attackCol];
    if (toCheck == 0 || toCheck == -1) {
      break;
    }

    if (toCheck == 1) {
      return false;
    }
  }

  for (int checkRowD = attackRow + 1; checkRowD <= 9; checkRowD++) {
    int toCheck = opponentBoard[checkRowD][attackCol];
    if (toCheck == 0 || toCheck == -1) {
      break;
    }

    if (toCheck == 1) {
      return false;
    }
  }

  return true;
}

void showAttackMessage(int msgCode) {
  switch (msgCode) {
  case 1:
    std::cout << "You missed. Better luck next time!\n";
    break;
  case 2:
    std::cout << "You hit your opponent!\n";
    break;
  case 3:
    std::cout << "You sank a ship!\n";
    break;

  default:
    break;
  }

  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMyBoard(char currentPlayer[],
                 int playerBoard[BOARD_SIZE][BOARD_SIZE]) {
  system("cls");
  std::cout << currentPlayer << " this is your board now:" << std::endl;
  printBoard(playerBoard);
  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printBoardToAttack(char currentPlayer[],
                        int opponentBoard[BOARD_SIZE][BOARD_SIZE]) {
  system("cls");
  std::cout << currentPlayer << " it's your turn to attack.\n";
  std::cout << "Your opponent board (hid):" << std::endl;
  bool isHid = true;
  printBoard(opponentBoard, isHid);
}

bool attack(char currentPlayer[], int opponentBoard[BOARD_SIZE][BOARD_SIZE]) {

  bool hit = false;
  int lastHitRow, lastHitCol;
  do {
    printBoardToAttack(currentPlayer, opponentBoard);
    char opt = '2';
    if (hit) {
      std::cout << "Last time you hit your opponent on "
                << (char)('A' + lastHitCol) << lastHitRow << "\n";
      std::cout << "1. Attack based on last hit\n"
                   "2. Attack with new coordinates set\n";
      do {
        std::cin >> opt;
        std::cin.sync();
      } while (opt < '1' || opt > '2');
    }

    int attackRow, attackCol;

    if (hit && opt == '1') {
      bool isValid = false;
      do {
        bool isDirectionValid = false;
        char direction;
        do {
          std::cout << "Last hit coordinate: " << (char)('A' + lastHitCol)
                    << lastHitRow << std::endl;
          std::cout << "Enter direction L/R/U/D: ";
          std::cin >> direction;
          std::cin.sync();
          isDirectionValid = direction != 'L' || direction != 'R' ||
                             direction != 'U' || direction != 'D';
        } while (!isDirectionValid);

        switch (direction) {
        case 'L':
          attackRow = lastHitRow;
          if (lastHitCol - 1 >= 0) {
            attackCol = lastHitCol - 1;
            isValid = true;
          }
          break;
        case 'R':
          attackRow = lastHitRow;

          if (lastHitCol + 1 <= 9) {
            attackCol = lastHitCol + 1;
            isValid = true;
          }
          break;
        case 'U':
          attackCol = lastHitCol;
          if (lastHitRow - 1 >= 0) {
            attackRow = lastHitRow - 1;
            isValid = true;
          }
          break;
        case 'D':
          attackCol = lastHitCol;
          if (lastHitRow + 1 <= 9) {
            attackRow = lastHitRow + 1;
            isValid = true;
          }
          break;
        }

      } while (!isValid);

    } else {

      std::cout << "Enter coordinates you want to attack:\n";
      char letterCoordinateChar, digitCoordinateChar;
      std::cout << "Capital letter: ";
      do {
        std::cin >> letterCoordinateChar;
        std::cin.sync();

        if (letterCoordinateChar < 'A' || letterCoordinateChar > 'J') {
          std::cout
              << "Invalid input! Please enter a valid capital letter [A, J]: ";
        }

      } while (letterCoordinateChar < 'A' || letterCoordinateChar > 'J');

      std::cout << "Digit: ";
      do {
        std::cin >> digitCoordinateChar;
        std::cin.sync();

        if (digitCoordinateChar < '0' || digitCoordinateChar > '9') {
          std::cout << "Invalid input! Please enter a valid digit [0, 9]: ";
        }

      } while (digitCoordinateChar < '0' || digitCoordinateChar > '9');

      attackRow = digitCoordinateChar - '0';
      attackCol = letterCoordinateChar - 'A';
    }

    int coordinateData = opponentBoard[attackRow][attackCol];

    if (coordinateData == 0) {
      system("cls");
      opponentBoard[attackRow][attackCol] = -1;
      std::cout << "Your opponent board (hid):" << std::endl;
      printBoard(opponentBoard, true);
      showAttackMessage(1);
      return true;
    }

    if (coordinateData == 1) {
      system("cls");
      opponentBoard[attackRow][attackCol] = 2;
      std::cout << "Your opponent board (hid):" << std::endl;
      printBoard(opponentBoard, true);
      bool shipSank = isShipSank(opponentBoard, attackRow, attackCol);
      if (shipSank) {
        showAttackMessage(3);
        return false;
      } else {
        showAttackMessage(2);
      }

      lastHitRow = attackRow;
      lastHitCol = attackCol;
      hit = true;
    }

    if (coordinateData == 2 || coordinateData == -1) {
      return false;
    }

  } while (hit);
  return true;
}

void playTurn(char currentPlayer[], int playerBoard[BOARD_SIZE][BOARD_SIZE],
              int opponentBoard[BOARD_SIZE][BOARD_SIZE]) {

  bool finishedTurn = false;

  do {
    char option;
    do {
      printBoardToAttack(currentPlayer, opponentBoard);
      std::cout << "Select an option:\n"
                   "1. Show your board\n"
                   "2. Attack opponent\n";

      std::cin >> option;
      std::cin.sync();
    } while (option < '1' || option > '2');

    switch (option) {
    case '1':
      showMyBoard(currentPlayer, playerBoard);
      break;
    case '2':
      finishedTurn = attack(currentPlayer, opponentBoard);
      break;
    }

    if (isGameOver(opponentBoard)) {
      return;
    }

  } while (!finishedTurn);
}

void gameOverMessage(char winner[]) {
  system("cls");
  std::cout << "Game over! " << winner
            << " sank all the ships and won the game.\n";
}

void game(char player1Name[], int player1Board[BOARD_SIZE][BOARD_SIZE],
          char player2Name[], int player2Board[BOARD_SIZE][BOARD_SIZE]) {

  bool gameOver = false;

  do {
    playTurn(player1Name, player1Board, player2Board);
    if (isGameOver(player2Board)) {
      gameOver = true;
      gameOverMessage(player1Name);
      break;
    }
    playTurn(player2Name, player2Board, player1Board);
    if (isGameOver(player1Board)) {
      gameOver = true;
      gameOverMessage(player2Name);
    }
  } while (!gameOver);

  std::cout << "Press ENTER to exit... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}