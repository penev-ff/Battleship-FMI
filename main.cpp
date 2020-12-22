#include <iostream>

void gameMainMenu();
void printMainMenu();


int main() {

  gameMainMenu();

  return 0;
}

void printMainMenu(){
  std::cout << std::endl;
  std::cout << "---- Battleship Game ----\n"
               "-       Main Menu       -\n" 
               "- 1.New Game            -\n" 
               "- 2.Board Builder       -\n" 
               "- 3.Exit                -\n" 
               "-------------------------\n" 
               << std::endl;
}

void selectOption(){
  std::cout << "Please select an option: ";
  bool isOptionValid = false;
  char input;
  do {
    std::cin >> input;
    std::cin.sync();
    switch (input)
    {
    case '1':
      /* TODO NEW GAME */
      break;    
    case '2':
      /* TODO Board Builder */
      break;
    case '3':
      /* TODO EXIT */
      break;
    
    default:
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