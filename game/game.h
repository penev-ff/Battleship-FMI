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
* Header with functions definitions for game.cpp
*
*/

#pragma once
#include "../board/board.h"

void setDefaultPlayerName(char player1Name[], int id);
void greetAndBuild(char playerName[], int board[BOARD_SIZE][BOARD_SIZE]);
void newGame();
bool isGameOver(int board[BOARD_SIZE][BOARD_SIZE]);
bool isShipSank(int opponentBoard[BOARD_SIZE][BOARD_SIZE], int attackRow,
                int attackCol);
void gameOverMessage(char winner[]);
void game(char player1Name[], int player1Board[BOARD_SIZE][BOARD_SIZE],
          char player2Name[], int player2Board[BOARD_SIZE][BOARD_SIZE]);
void printBoardToAttack(char currentPlayer[],
                        int opponentBoard[BOARD_SIZE][BOARD_SIZE]);
bool attack(char currentPlayer[], int opponentBoard[BOARD_SIZE][BOARD_SIZE]);
void showMyBoard(char name[], int playerBoard[BOARD_SIZE][BOARD_SIZE]);
void playTurn(char playerName[], int playerBoard[BOARD_SIZE][BOARD_SIZE],
              int opponentBoard[BOARD_SIZE][BOARD_SIZE]);
