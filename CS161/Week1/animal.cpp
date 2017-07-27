/****************************************************************
** Author:  Byron Kooima
** Date: 2017/01/07
** Description: CS161 Week1 Assignment
****************************************************************/

#include <iostream>
#include <string>

// a simple example program to return input string
int main()
{
   // set variables
   std::string faveAnimal;
   // prompt user for input
   std::cout << "Please enter your favorite animal." << std::endl;
   std::cin >> faveAnimal;
   // output string with user input
   std::cout << "Your favorite animal is the " << faveAnimal;
   std::cout << "." << std::endl;

   return 0;
}
