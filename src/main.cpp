// entry point for number guessing game
#include <iostream>     // analogue to <stdio.h> in C
#include "game.h"  // custom header file
#include "check.h" // custom header file
#include "input.h" // header for inputreader
#include <ctime>

int main(int argc, char* argv[]) {

   int low, up; // specify the range
   int buff;

   time_t now = time(nullptr); // current date and time in seconds
   char* dati = ctime(&now); // convert to string form


   // user interaction
   std :: cout << "Welcome to the game!" << std::endl;
   std :: cout << "The current time: "<< dati;
   std :: cout << "program called: " << argv[0] << std::endl;
   if (readbounds(argc,argv,low,up)) {

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
   } else {
      return 1;
   }

   // create a game instance
   GuessingGame game(low,up);

   int guess, attempt = 0;
   while(true){

      readInteger(guess, "Enter your guess: ");

      attempt++;

      Res result = game.makeGuess(guess);

      if (result == Res::Correct) {
         std::cout << "Congratulations! You got it!" << std::endl;
         break;
      } else if (result == Res::TooLow) {
         std::cout << "Your guess is too low" << std::endl;
      } else {
         std::cout << "Your guess is too high" << std::endl;
      }
   }
   return 0;
}