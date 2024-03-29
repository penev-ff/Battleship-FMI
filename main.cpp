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
* main
*
*/


#include <iostream>
#include "./board/board.h"
#include "./board/boardBuilder.h"
#include "./game/game.h"

void gameMainMenu();
void printMainMenu();

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
  bool isOptionValid;
  char input;
  do {
    std::cin >> input;
    std::cin.sync();

    switch (input) {
    case '1':
      system("cls");
      newGame();
      isOptionValid = true;
      break;
    case '2':
      system("cls");
      int tempBoard[BOARD_SIZE][BOARD_SIZE];
      boardBuilderMenu(tempBoard);
      isOptionValid = true;
      break;
    case '3':
      system("cls");
      return;

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
  system("cls");
  printMainMenu();
  selectOption();
}