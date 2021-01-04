#include <iostream>
#include "../board/board.h"
#include "../board/boardBuilder.h"
#include "./game.h"

void setDefaultPlayerName (char player1Name[], int id){
    const unsigned defaultNameSize = 8;
    const char defaultName[defaultNameSize] = "Player ";
    
    for (size_t i = 0; i < defaultNameSize; i++)
    {
      player1Name[i] = defaultName[i];
    }
    
    player1Name[defaultNameSize - 1] = '0' + id;
    player1Name[defaultNameSize] = '\0';
}

void newGame() {
  const unsigned NAME_MAX_SIZE = 51;
  char player1Name[NAME_MAX_SIZE] = "";
  char player2Name[NAME_MAX_SIZE] = "";
  int player1Board[BOARD_SIZE][BOARD_SIZE];
  int player2Board[BOARD_SIZE][BOARD_SIZE];

  std::cout << "Please enter player 1 nickname: ";
  
  std::cin.getline(player1Name, NAME_MAX_SIZE);

  if (player1Name[0] == '\0')
  {
    setDefaultPlayerName(player1Name, 1);
  }
  
  greatAndBuild(player1Name, player1Board);

  std::cout << "Please enter player 2 nickname: ";
  std::cin.getline(player2Name, NAME_MAX_SIZE);

  if (player2Name[0] == '\0')
  {
    setDefaultPlayerName(player2Name, 2);
  }

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