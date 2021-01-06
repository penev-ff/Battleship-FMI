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

void playTurn(char currentPlayer[], int playerBoard[BOARD_SIZE][BOARD_SIZE],
              int opponentBoard[BOARD_SIZE][BOARD_SIZE]) {
  std::cout << currentPlayer << " this is your board now:" << std::endl;
  printBoard(playerBoard);
  std::cout << "Your opponent board (hid):" << std::endl;
  bool isHid = true;
  printBoard(opponentBoard, isHid);
  //This is for DEBUG - shall remove later.
  std::cout << "Your opponent board (not hid)" << std::endl;
  printBoard(opponentBoard);
  std::cout << "Press ENTER to continue... " << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void game(char player1Name[], int player1Board[BOARD_SIZE][BOARD_SIZE],
          char player2Name[], int player2Board[BOARD_SIZE][BOARD_SIZE]) {

  bool gameOver;

  do {
    playTurn(player1Name, player1Board, player2Board);
    // gameOver = isGameOver(player1Board, player2Board);
  } while (!gameOver);
}

