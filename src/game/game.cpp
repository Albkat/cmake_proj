// directives
#include "game.h"
#include <ctime>
#include <cstdlib>


// constructor definition
GuessingGame::GuessingGame(int low, int high) {
   lowerL = low;
   upperL = high;
   srand(time(nullptr)); // seed the number generator using current time 
   secretN = rand() % (high - low + 1) + low;
}

Res GuessingGame::makeGuess(int guess) {
   if (guess == secretN) {
      return Res::Correct;
   } else if (guess < secretN) {
      return Res::TooLow;
   } else {
      return Res::TooHigh;
   }
}

int GuessingGame::getSeed() {
   return secretN;
}