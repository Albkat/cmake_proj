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
   GuessingGame(int low,int high); // a constructor
   Res makeGuess(int guess); // function that returns enumeration
   int getSeed(); //to get secret number

private:
   int lowerL;
   int upperL;
   int secretN;
};
#endif