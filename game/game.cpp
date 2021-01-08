#include "./game.h"
#include "../board/board.h"
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

void greatAndBuild(char playerName[], int board[BOARD_SIZE][BOARD_SIZE]) {
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

  greatAndBuild(player1Name, player1Board);

  system("cls");
  std::cout << "Please enter player 2 nickname: ";
  std::cin.getline(player2Name, NAME_MAX_SIZE);

  if (player2Name[0] == '\0') {
    setDefaultPlayerName(player2Name, 2);
  }

  greatAndBuild(player2Name, player2Board);

  game(player1Name, player1Board, player2Name, player2Board);
}

void showAttackMessage(int msgCode) {
  switch (msgCode) {
  case 1:
    std::cout << "You missed. Better luck next time!\n";
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

void attack(char currentPlayer[], int opponentBoard[BOARD_SIZE][BOARD_SIZE]) {
  system("cls");
  std::cout << currentPlayer << " it's your turn to attack.\n";
  std::cout << "Your opponent board (hid):" << std::endl;
  const bool isHid = true;
  printBoard(opponentBoard, isHid);
  std::cout << "Q - if you want to return:\n";
  std::cout << "Enter coordinates you want to attack:\n";
  char letterCoordinateChar, digitCoordinateChar;
  do {
    std::cout << "Capital letter: ";
    std::cin >> letterCoordinateChar;
    std::cin.sync();

    if (letterCoordinateChar == 'Q') {
      return;
    }

    if (letterCoordinateChar < 'A' || letterCoordinateChar > 'J') {
      std::cout
          << "Invalid input! Please enter a valid capital letter [A, J]: ";
    }

  } while (letterCoordinateChar < 'A' || letterCoordinateChar > 'J');

  do {
    std::cout << "Digit: ";
    std::cin >> digitCoordinateChar;
    std::cin.sync();

    if (digitCoordinateChar < '0' || digitCoordinateChar > '9') {
      std::cout << "Invalid input! Please enter a valid digit [0, 9]: ";
    }

  } while (digitCoordinateChar < '0' || digitCoordinateChar > '9');

  int attackRow = digitCoordinateChar - '0';
  int attackCol = letterCoordinateChar - 'A';

  if (opponentBoard[attackRow][attackCol] == 0) {
    system("cls");
    opponentBoard[attackRow][attackCol] = -1;
    std::cout << "Your opponent board (hid):" << std::endl;
    printBoard(opponentBoard, isHid);
    showAttackMessage(1);
    return;
  }
}

void playTurn(char currentPlayer[], int playerBoard[BOARD_SIZE][BOARD_SIZE],
              int opponentBoard[BOARD_SIZE][BOARD_SIZE]) {
  system("cls");
  char option;
  do {
    std::cout << currentPlayer << " it's your turn to attack.\n";
    std::cout << "Your opponent board (hid):" << std::endl;
    bool isHid = true;
    printBoard(opponentBoard, isHid);
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
    attack(currentPlayer, opponentBoard);
    break;
  }
}

void game(char player1Name[], int player1Board[BOARD_SIZE][BOARD_SIZE],
          char player2Name[], int player2Board[BOARD_SIZE][BOARD_SIZE]) {

  bool gameOver;

  do {
    playTurn(player1Name, player1Board, player2Board);
    playTurn(player2Name, player2Board, player1Board);
    // gameOver = isGameOver(player1Board, player2Board);
  } while (!gameOver);
}