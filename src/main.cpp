// entry point for number guessing game
#include <iostream> // analogue to <stdio.h> in C
#include "game/game.h" // custom header file

int main() {

   int low,up; // specify the range

   // user interaction
   std :: cout << "Welcome to the game!" << std::endl;
   std :: cout << "Please enter limits (e.g. from 1 to 49)" << std::endl;
   std :: cin >> low >> up;

   // create a game instance
   GuessingGame game(low,up);

   return 0;
}