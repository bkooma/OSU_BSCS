/*************************************************************************************
** Recursion.cpp is the Recursion class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/30
** Description: CS162 Week5 Lab 5
** The Recursion class represents a program with three examples of Recursion functions.
** The program prompts the user for the three recursion choices and an exit option.
***************************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include "Recursion.hpp"
#include "userMenu.hpp"
#include "inputVerification.cpp"

/*********************************************************************
** Function: Recursion::Recursion
** Description: Default constructor for Recursion. 
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Not really necessary for this program but created
**					for possible reuse.
*********************************************************************/
Recursion::Recursion() {
}

/*********************************************************************
** Function:		Recursion::reverse()
** Description:		Use recursion to reverses the characters of a user 
**					provided string	and outputs to the command prompt.
** Parameters:		s		User provided string
** Pre-Conditions:	N/A
** Post-Conditions: Prints the reversed string to the command prompt
*********************************************************************/
void Recursion::reverse(std::string s)
{
	if (s.length() >> 1) {
		reverse(s.substr(1));
	}
	
	std::cout << s.substr(0, 1);
}

/*********************************************************************
** Function:		Recursion::arraySum()
** Description:		Use recursion to sum up the value of all the
**					elements in a provided array.
** Parameters:		arr[]		Array of values
**					element		Number of elements of the array
** Pre-Conditions:	N/A
** Post-Conditions: Sums up the elements of the array and returns
**					the sum to the calling command.
*********************************************************************/
int Recursion::arraySum(int arr[], int elements)
{
	if (elements == 1) {
		return arr[0];
	}
	else {
		return arr[elements - 1] + arraySum(arr, elements - 1);
	}
}

/*********************************************************************
** Function:		Recursion::triangleSum()
** Description:		Use recursion to calculate the triangular sum of
**					a user provided size N.
** Parameters:		rowNum		Number of rows in the triangle
** Pre-Conditions:	N/A
** Post-Conditions: Sums up the rows of the number of triangle 
**					elements and returns sum to calling command.
*********************************************************************/
int Recursion::triangleSum(int rowNum)
{
	if (rowNum == 1) {
		return 1;
	}
	else {
		return (rowNum + triangleSum(rowNum - 1));
	}
}

/*********************************************************************
** Function:		Recursion::recursionMenu()
** Description:		Provides a menu function for the three recursive
**					functions and an exit option.
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Accepts valid input from the user and then runs
**					the specified recursive function.
*********************************************************************/
void Recursion::recursionMenu()
{
	int menuOpt = -1;
	std::string iString = "";
	std::string rString = "";
	std::string varString;

	// Create a menu object
	userMenu mainMenu;
	// Add choices to the recursion menu
	mainMenu.add_choice("Use Recursion to Reverse a String.");
	mainMenu.add_choice("Use Recursion to Calculate the Sum of an Array.");
	mainMenu.add_choice("Use Recursion to Calculate the Triangular Number for N.");
	mainMenu.add_choice("Exit the Recursion Program.");

	// make a valid selection from the menu
	menuOpt = mainMenu.makeChoice();

	// While user does not select Exit
	while (menuOpt != 4) {

		// Call the reverse string function
		if (menuOpt == 1) {
			varString = "Please enter a string you would like to reverse:\n";
			std::cout << varString;
			std::cin.ignore();

			SafeInput <std::string>(iString,
				[=](std::string Input) -> bool {
				std::transform(Input.begin(), Input.end(),
					Input.begin(), ::toupper);
				return (Input.compare("") != 0);
			}, varString);

			// Print the current string and call the recursive string function
			std::cout << "\nThe string: \n" << iString << "\n\nin reverse is: \n";
			reverse(iString);
			std::cout << "\n\n";
		}

		// Call the Array Sum recursive function
		if (menuOpt == 2) {
			int* recArr;
			int sizeArray = 0;
			int arrValue = 0;

			// Prompt the user for a valid integer size for the array
			std::cout << "Enter the size of the array you would like to sum (<=100).\n";
			varString = "Please enter an integer for the size.\n";
			SafeInput <int>(sizeArray,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
			}, varString);

			// Size the array for the User input
			recArr = new int[sizeArray];

			// Step through the array and populate with user provided values
			for (int i = 0; i < sizeArray; i++) {
				// Prompt user for a valid integer
				std::cout << "Please enter value for the Arr[" << i << "] element.\n";
				varString = "Please enter an integer for the array value.\n";
				SafeInput <int>(arrValue,
					[=](int Input) -> bool {
					return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n'));
				}, varString);

				// Populate the array with the user provided int
				recArr[i] = arrValue;
			}
			
			// Sum up the array values using the recursive array sum function
			std::cout << "The sum of your array is: " << arraySum(recArr, sizeArray) << std::endl << std::endl;
			// Free up the memory
			delete[] recArr;
		}

		// Call the Triangular Number recursive function
		if (menuOpt == 3) {
			int triSize = 0;

			// Prompt the user for a valid integer for the triangular size
			std::cout << "Please enter an integer for the Triangular Number function.\n";
			varString = "Please enter an integer.\n";
			SafeInput <int>(triSize,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
			}, varString);

			// Sum up all the values of a triangle of size N using the recursive Triangular function
			std::cout << "The sum of all the rows in a " << triSize << " sized triangle is: " << triangleSum(triSize) << std::endl << std::endl;
		}
		
		// Repost the menu options
		menuOpt = mainMenu.makeChoice();
	}
}

/*********************************************************************
** Function: Recursion::~Recursion
** Description: Destructor for Recursion.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Not really necessary for this program but created
**					for possible reuse.
*********************************************************************/
Recursion::~Recursion() {
}


int main() {
	// Create a recursion object
	Recursion *recursion = new Recursion;
	// Call the menu option
	recursion->recursionMenu();

	// Free up the memory
	delete recursion;
	return 0;
}
