#include <iostream>
#include "headers/board.h"
#include "headers/boardBuilder.h"

void gameMainMenu();
void printMainMenu();

void newGame(){
  const unsigned BOARD_SIZE = 10;
  const unsigned NAME_MAX_SIZE = 51;

  char player1Name[NAME_MAX_SIZE] = "";
  char player2Name[NAME_MAX_SIZE] = "";

  std::cout << "Please enter player 1 nickname: ";
  std::cin.getline(player1Name, NAME_MAX_SIZE);
  std::cout << "Please enter player 2 nickname: ";
  std::cin.getline(player2Name, NAME_MAX_SIZE);

  int player1Board[BOARD_SIZE][BOARD_SIZE];
  int player2Board[BOARD_SIZE][BOARD_SIZE];

  system("cls");
  std::cout << "Hello, " << player1Name << std::endl;
  std::cout << "It's your turn to build a board.\n";
  boardBuilderMenu(player1Board);
}

int main() {

  gameMainMenu();

  return 0;
}

void printMainMenu() {
  std::cout << std::endl;
  std::cout << "---- Battleship Game ----\n"
               "-       Main Menu       -\n"
               "- 1.New Game            -\n"
               "- 2.Board Builder       -\n"
               "- 3.Exit                -\n"
               "-------------------------\n"
            << std::endl;
}

void selectOption() {
  std::cout << "Please select an option: ";
  bool isOptionValid = false;
  char input;
  do {
    std::cin >> input;
    std::cin.sync();
    switch (input) {
    case '1':
      /* TODO NEW GAME */
      system("cls");
      newGame();
      isOptionValid = true;
      break;
    case '2':
      /* TODO Board Builder */
      system("cls");
      int tempBoard[BOARD_SIZE][BOARD_SIZE];
      boardBuilderMenu(tempBoard);
      isOptionValid = true;
      break;
    case '3':
      system("cls");
      return;
      break;

    default:
      system("cls");
      printMainMenu();
      isOptionValid = false;
      std::cout << "Your option is invalid! \n"
                   "Please enter a valid option [1-3]:"
                << std::endl;
      break;
    }
  } while (!isOptionValid);
}

void gameMainMenu() {
  printMainMenu();
  selectOption();
}