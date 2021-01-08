#pragma once
#include "../board/board.h"

void setDefaultPlayerName(char player1Name[], int id);
void greatAndBuild(char playerName[], int board[BOARD_SIZE][BOARD_SIZE]);
void newGame();
void game(char player1Name[], int player1Board[BOARD_SIZE][BOARD_SIZE],
          char player2Name[], int player2Board[BOARD_SIZE][BOARD_SIZE]);
void printBoardToAttack(char currentPlayer[], int opponentBoard[BOARD_SIZE][BOARD_SIZE]);
bool attack(char currentPlayer[], int opponentBoard[BOARD_SIZE][BOARD_SIZE]);
void showMyBoard(char name[], int playerBoard[BOARD_SIZE][BOARD_SIZE]);
void playTurn(char playerName[], int playerBoard[BOARD_SIZE][BOARD_SIZE],
              int opponentBoard[BOARD_SIZE][BOARD_SIZE]);

          