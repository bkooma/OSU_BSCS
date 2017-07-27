/*************************************************************************************
** Recursion.cpp is the Recursion class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/30
** Description: CS162 Week5 Lab 5
** The Recursion class represents a Grocery List Item. 
***************************************************************************************/

#include <iostream>
#include <string>
#include "Recursion.hpp"
#include "userMenu.hpp"
#include "inputVerification.cpp"

void reverse(std::string s)
{
	if (s.length() >> 1) {
		reverse(s.substr(1));
	}
	
	std::cout << s.substr(0, 1);
}

int arraySum(int arr[], int elements)
{
	if (elements == 1) {
		return arr[0];
	}
	else {
		return arr[elements - 1] + arraySum(arr, elements - 1);
	}
}

int triangleSum(int rowNum)
{
	if (rowNum == 1) {
		return 1;
	}
	else {
		return (rowNum + triangleSum(rowNum - 1));
	}
}

void recursionMenu()
{
	int menuOpt = -1;
	std::string iString = "";
	std::string rString = "";

	userMenu mainMenu;
	mainMenu.add_choice("Use Recursion to Reverse a String.");
	mainMenu.add_choice("Use Recursion to Calculate the Sum of an Array.");
	mainMenu.add_choice("Use Recursion to Calculate the Triangular Number for N.");
	mainMenu.add_choice("Exit the Recursion Program.");

	// make a valid selection from the menu
	menuOpt = mainMenu.makeChoice();

	while (menuOpt != 4) {

		if (menuOpt == 1) {
			std::cout << "Please enter a string you would like to reverse:\n";
			std::cin.ignore();
			std::getline(std::cin, iString);
			std::cout << "\nThe string: \n" << iString << "\n\nin reverse is: \n";
			reverse(iString);
			std::cout << "\n";
		}

		if (menuOpt == 2) {
			int* recArr;
			int sizeArray = 0;
			int arrValue = 0;

			std::cout << "Enter the size of the array you would like to sum (<=100).\n";
			char varString[100] = { "Please enter an integer for the size.\n" };
			SafeInput <int>(sizeArray,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
			}, varString);

			// Size the array for the User input
			recArr = new int[sizeArray];

			for (int i = 0; i < sizeArray; i++) {
				std::cout << "Please enter value for the Arr[" << i << "] element.\n";
				char varString2[100] = { "Please enter an integer for the array value.\n" };
				SafeInput <int>(arrValue,
					[=](int Input) -> bool {
					return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n'));
				}, varString2);

				recArr[i] = arrValue;
			}
			
			std::cout << "The sum of your array is: " << arraySum(recArr, sizeArray) << std::endl;
			delete[] recArr;
		}

		if (menuOpt == 3) {
			int triSize = 0;

			std::cout << "Please enter an integer for the Triangular Number function.\n";
			char varString[100] = { "Please enter an integer.\n" };
			SafeInput <int>(triSize,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
			}, varString);

			std::cout << "The sum of all the rows in a " << triSize << " sized triangle is: " << triangleSum(triSize);
		}
			
		menuOpt = mainMenu.makeChoice();
	}
}

int main() {
	recursionMenu();

	return 0;
}
