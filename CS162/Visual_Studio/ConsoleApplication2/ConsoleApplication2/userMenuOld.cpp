/*************************************************************************************
** userMenu.cpp is the userMenu class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/06
** Description: CS162 Re-usable user menu
** Currently the menu options are hard coded. Eventually I want to convert this to 
** a vector object to initalize the menu. The SafeInput is used to ensure the user
** only enters integer values within the menu range.
*************************************************************************************/

#include "userMenu.hpp"
#include "inputVerification.cpp"
#include <iostream>


int userMenu::makeSelection()
{
	std::cout << "\nLet's simulate Langton's ant. Please select an option from the following menu: \n\n";
	
	char verString[500] = { 
		"Select a valid input option.\n" 
		"1. Begin/Continue simulation\n" 
		"2. Set table size [Height:Width] (default: [40:80])\n"
		"3. Select the ant's starting position (default: center of board)\n" 
		"4. EXTRA CREDIT: Set a random starting position for the ant\n"
		"5. Select the ant's starting direction (default: North)\n"
		"6. Select the number of moves for the ant (default: 80)\n"
		"7. Re-initialize ant scenario\n"
		"8. Exit\n\n" };

	std::cout << verString;

	SafeInput <int>(choice,
		[=](int Input) -> bool {
		return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input < 9));
	},verString);

	return choice;
}