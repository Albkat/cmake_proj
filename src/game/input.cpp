#include "input.h"
#include "check.h"
#include <iostream>
#include <sstream>

bool readbounds(int argc, char* argv[], int& low, int& up) {
   if (argc == 3) {
      std::cout << "Trying to read CLI args" << std::endl;
      // iterate CLI arguments
      for (int i = 1; i < 3; ++i) {
         std::istringstream iss(argv[i]); // create iss object
         int num;

         // convert CLI arg to integer
         if (iss >> num) {
            if (i == 1) {
               low = num;
            } else {
               up = num;
            }
         } else {
            std::cout << "Argument " << i << " is invalid, please enter integer" << std::endl;
            return false;
         }
      }
   } else {
      readInteger(low, "lower bound: ");
      readInteger(up, "upper bound: ");
   }
   return true;   
}