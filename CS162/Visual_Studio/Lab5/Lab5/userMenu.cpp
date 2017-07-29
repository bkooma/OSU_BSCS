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

/*********************************************************************
** Function:		userMenu::add_choice()
** Description:		Populates the menu vector with menu options
** Parameters:		std::string option			Passed string for menu
** Pre-Conditions:	N/A
** Post-Conditions: Menu vector is populated with the string
*********************************************************************/
void userMenu::add_choice(std::string option) {
	// Increase the vector with the new menu option
	choice.push_back(option);
}

/*********************************************************************
** Function:		userMenu::printMenu()
** Description:		Prints the Menu options within the menu vector
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: The menu is displayed to the command line
*********************************************************************/
void userMenu::printMenu() {
	// Step through the vector and print the menu options
	for (size_t i = 0; i < choice.size(); ++i)
		std::cout << " " << i + 1 << ".  " << choice[i] << "\n";
}

/*********************************************************************
** Function:		userMenu::makeChoice()
** Description:		Using the inputVerification, the user enters the
** 					menu option selection and that value is returned.
** Parameters:
** Pre-Conditions:	N/A
** Post-Conditions: Returns an int of the valid selected menu option.
*********************************************************************/
int userMenu::makeChoice() {
	std::cout << "\nPlease select an option from the following menu: \n";
	printMenu();

	int choiceSize = choice.size() + 1;

	// Error message for the inputVerification class
	std::string varString = "Select a valid input option.\n";
	// Input verification provided by the user
	SafeInput <int>(selectedChoice,
		[=](int Input) -> bool {
		return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input < choiceSize));
	}, varString);
	// Returns the valid menu choice selected by the user
	return selectedChoice;
}
