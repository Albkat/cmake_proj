#include "check.h"
#include <limits>

bool readInteger(int& number, const std::string& text){
   while (true) {
      std::cout << text;
      if (std::cin >> number) {
         return 0;
      } else {
         // handle invalid
         std::cout << "Invalid input. Please enter an integer." << std::endl;

         // clear the error state 
         std::cin.clear();

         //disacrd any remaining buffer
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
   }
   return 0;
}