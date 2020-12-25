#include <iostream>
const unsigned MAX_ROWS = 10;
const unsigned MAX_COLS = 10;

void gameMainMenu();
void printMainMenu();
void printRowSeparator(char separateSymbol);
void printBoard(int boardEngine[MAX_ROWS][MAX_COLS]);

int main() {

  gameMainMenu();

  return 0;
}

void printRowSeparator(char separateSymbol) {
  for (int i = 0; i < 45; ++i) {
    std::cout << separateSymbol;
  }
  std::cout << std::endl;
}

void printBoard() {
  // Printing the initial row with letters (A-J)
  printRowSeparator('-');
  // Empty edge (calibration)
  std::cout << "|   |";
  for (int i = 0; i < 10; ++i) {
    std::cout << " " << (char)('A' + i) << " |";
  }
  std::cout << std::endl;
  printRowSeparator('-');

  // Printing each row (first column is always a board index digit (0-9))
  for (int row = 0; row < MAX_ROWS; ++row) {
    std::cout << "|";
    for (int col = 0; col < MAX_COLS + 1; ++col) {
      if (col == 0) {
        std::cout << " " << row << " |";
      } else {
        std::cout << " " << '~' << " |";
      }
    }
    std::cout << std::endl;
    printRowSeparator('-');
  }
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
      break;
    case '2':
      /* TODO Board Builder */
      system("cls");
      printBoard();
      break;
    case '3':
      return;
      break;

    default:
      system("cls");
      printMainMenu();
      isOptionValid = false;
      std::cout << "Your option is invalid! \n"
                   "Please enter an option [1-3]:"
                << std::endl;
      break;
    }
  } while (!isOptionValid);
}

void gameMainMenu() {
  printMainMenu();
  selectOption();
}