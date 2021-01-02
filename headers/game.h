#pragma once
#include "board.h"
#include "boardBuilder.h"

void newGame();
void greatAndBuild(const char playerName[], int board[BOARD_SIZE][BOARD_SIZE]);
void game(const char player1Name[], int player1Board[BOARD_SIZE][BOARD_SIZE],
          const char player2Name[], int player2Board[BOARD_SIZE][BOARD_SIZE]);

void newGame() {
  const unsigned NAME_MAX_SIZE = 51;
  char player1Name[NAME_MAX_SIZE] = "";
  char player2Name[NAME_MAX_SIZE] = "";
  int player1Board[BOARD_SIZE][BOARD_SIZE];
  int player2Board[BOARD_SIZE][BOARD_SIZE];

  std::cout << "Please enter player 1 nickname: ";
  std::cin.getline(player1Name, NAME_MAX_SIZE);

  greatAndBuild(player1Name, player1Board);

  std::cout << "Please enter player 2 nickname: ";
  std::cin.getline(player2Name, NAME_MAX_SIZE);

  greatAndBuild(player2Name, player2Board);

  game(player1Name, player1Board, player2Name, player2Board);
}

void greatAndBuild(const char playerName[], int board[BOARD_SIZE][BOARD_SIZE]) {
  system("cls");
  std::cout << "Hello, " << playerName << std::endl;
  std::cout << "It's your turn to build a board.\n";
  boardBuilderMenu(board);
}

void game(const char player1Name[],
          int player1Board[BOARD_SIZE][BOARD_SIZE],
          const char player2Name[],
          int player2Board[BOARD_SIZE][BOARD_SIZE]) {}