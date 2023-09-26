// entry point for number guessing game
#include <iostream> // analogue to <stdio.h> in C
#include "game/game.h" // custom header file

int main() {

   int low, up; // specify the range
   int buff;

   // user interaction
   std :: cout << "Welcome to the game!" << std::endl;
   std :: cout << "Please enter limits (e.g. from 1 to 49)" << std::endl;
   std :: cin >> low >> up;

   // small check if numbers are in the right order
   if (low > up) {
      buff = low;
      low = up;
      up = buff;
   } else if (low == up) {
      std::cout << "The same number entered twice! Abort ..." <<std::endl;
      return 1;
   }

   std::cout << "Let's start!" << std::endl;
   std::cout << "I am thinking of a number b/n " << low << " and " << up << std::endl;

   // create a game instance
   GuessingGame game(low,up);


   return 0;
}