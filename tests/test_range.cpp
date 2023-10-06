#include "../src/game/input.h"
#include <cassert>

int main() {
   // Test case 1: valid
   char* argv1[] = {"program", "3", "5"};
   int low = 0, up = 0;
   assert(readbounds(3,argv1,low,up) == true);
   assert(low == 3);
   assert(up == 5);

   return 0;
}