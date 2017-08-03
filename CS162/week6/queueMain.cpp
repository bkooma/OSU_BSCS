/*************************************************************************************
** Program name: queueMain.cpp is the Queue main function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Lab6
** The queueMain program populates a default Queue object and calls the Queue menu to
** prompt the user for actions to perform on the Queue.
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Queue.hpp"
#include "userMenu.hpp"
#include "inputVerification.cpp"

int main()
{
	int val;
	int returnVal;
	std::string varString;

	// Create the Queue object
	Queue QL;

	// Create the menu object
	userMenu menu;
	int menuChoice = 0;

	// Populate the userMenu class vector with some options
	menu.add_choice("Enter a value to be added to the queue");
	menu.add_choice("Display first node (front) value");
	menu.add_choice("Remove first node (front) value");
	menu.add_choice("Display the queue contents");
	menu.add_choice("Exit");

	// Make sure the choice is valid
	menuChoice = menu.makeChoice();

	while (menuChoice != 5)
	{
		if (menuChoice == 1){
			varString = "Please enter an int to add to Queue.\n";
			std::cout << varString;
			// Input validation function to make sure the quantity variable entered by user is valid
			SafeInput <int>(val,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n'));
			}, varString);

			// Place the value at the end of the Queue
			QL.addBack(val);
		}
		else if (menuChoice == 2){
			// Check if Queue is empty before getting first node value
			if (QL.isEmpty()) {
				std::cout << "The Queue is empty. No first node value exists\n" << std::endl;
			}
			// If Queue is not empty, return the first node (front) value
			else {
				returnVal = QL.getFront();
				std::cout << "The first node (front) value is: " << returnVal << std::endl;
			}
		}
		// Remove the first node in the Queue
		else if (menuChoice == 3){
			// Call the removeFront function
			QL.removeFront();
		}
		// Display the values in the Queue
		else if (menuChoice == 4){
			QL.displayQueue();
		}
		menuChoice = menu.makeChoice();
	}
	return 0;
}


