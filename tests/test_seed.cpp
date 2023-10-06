#include "../src/game/game.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <thread>

int main() {

   const int numGames = 3; // number of games
   std::vector<int> seeds;
   int seedChange = 1;

   for (int i = 0; i < numGames; ++i) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      GuessingGame game(1, 100);

      int seed = game.getSeed();
      seeds.push_back(seed);

      if (i > 0 && seed != seeds[i-1]) {
         seedChange = 0;
         break;
      }
   }

   if (seedChange == 1) {
      return 1;
   }

   return 0;
}
