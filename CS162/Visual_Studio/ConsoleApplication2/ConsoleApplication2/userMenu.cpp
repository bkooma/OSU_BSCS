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

void userMenu::add_choice(std::string option) {
	choice.push_back(option);
}

void userMenu::printMenu() {
	for (size_t i = 0; i < choice.size(); ++i)
		std::cout << " " << i + 1 << ".  " << choice[i] << "\n";
}

int userMenu::makeChoice() {
	std::cout << "\nPlease select an option from the following menu: \n";
	printMenu();

	int choiceSize = choice.size() + 1;

	// Error message for the inputVerification class
	char verString[100] = { "Select a valid input option.\n" };

	SafeInput <int>(selectedChoice,
		[=](int Input) -> bool {
		return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input < choiceSize));
	}, verString);

	return selectedChoice;
}