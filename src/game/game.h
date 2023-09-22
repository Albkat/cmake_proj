// header guard
#ifndef GAME_H
#define GAME_H

// enumeration used to represent the possible outcomes of the game 
enum class Res {
   Correct,
   TooLow,
   TooHigh
};

class GuessingGame{
public:
   GuessingGame(int low,int high);
   Res makeGuess(int guess);

private:
   int lowerL;
   int upperL;
   int secretN;
};
#endif