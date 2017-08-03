/***************************************************************************************
** Program name: Rock, Paper, Scissors Game
** Authors:  Byron Kooima, Alexander Jennison, Polly Sobeck, 
**           Dai Duong Nguyen, Zachary Bellone
** Date: 2017/07/30
** Description: CS162 Week5 Group10
** This program simulates a game of Rock, Paper, Scissors. It takes a user's choice of 
** Tool and matches it up against a randomly chosen Computer Tool. By default, the 
** normal rules of Rock, Paper, Scissors apply. However, the user can also choose to 
** input their own strength for each Tool, which allows certain tools to be more 
** powerful than others. The program outputs the round winner and the current score 
** (human wins, computer wins, ties) after each round. The user can choose to play 
** another round or to exit the program.
***************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm>
#include "inputVerification.cpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"
#include "RPSGame.hpp"


int main () {
	// Main variables
	std::string strengthSet;
	std::string toolType;
	// Set strengths for tools to default
	int rockStrength = 1;
	int paperStrength = 1;
	int scissorStrength = 1;
 	std::string varString;


	// Set seed for random function
    std::srand(static_cast<unsigned int>(time(0)));

	// Create a new RPSGame object
	RPSGame* game = new RPSGame();

	// Prompt the user to select option for changing strength of tool
	std::cout << "Welcome to the challenging game of Rock, Paper, Scissors\n";
	std::cout << "Would you like to set the strength for your specific Tool? (y-yes, n-no)\n";

	// Input verification for selected strength (y/n)
	varString = "Please enter Y/N\n";
	SafeInput <std::string>(strengthSet,
		[=](std::string Input) -> bool {
		std::transform(Input.begin(), Input.end(),
			Input.begin(), ::toupper);
		return (Input.compare("Y") == 0 || Input.compare("N") == 0);
	}, varString);

	// If user wants to change strength of the tools, prompt for each Tool
	if (strengthSet == "y" || strengthSet == "Y") {
		// Set the error message
		varString = "Please enter an integer value (>0).\n";
		// Prompt for the Rock strength
		std::cout << "What level of strength should the Rock tool have?  ";

		// Input verification for an int
		SafeInput <int>(rockStrength,
			[=](int Input) -> bool {
			return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
		}, varString);

		// Prompt for the Paper strength
		std::cout << "What level of strength should the Paper tool have?  ";
		// Input verification for an int
		SafeInput <int>(paperStrength,
			[=](int Input) -> bool {
			return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
		}, varString);

		// Prompt for the Scissors strength
		std::cout << "What level of strength should the Scissors tool have?  ";
		// Input verification for an int
		SafeInput <int>(scissorStrength,
			[=](int Input) -> bool {
			return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
		}, varString);
	}

	// Do loop for tool selection and continuing the rounds of RPS play
	do {
		// Prompt the user for their selected Tool
		std::cout << "Please select your tool type ('p'-Paper, 'r'-Rock, 's'-Scissors, 'e'-Exit)\n";
		varString = "Please enter a valid option ('p'-Paper, 'r'-Rock, 's'-Scissors, 'e'-Exit)\n";
		// Input verification to ensure the user enters r/p/s
		SafeInput <std::string>(toolType,
			[=](std::string Input) -> bool {
			std::transform(Input.begin(), Input.end(),
				Input.begin(), ::toupper);
			return (Input.compare("P") == 0 || Input.compare("R") == 0 || Input.compare("S") == 0 || Input.compare("E") == 0);
			}, varString);

		// User does not select e/E for exiting the program
		if (toolType != "e" && toolType != "E") {
			// Set the players tool from their selection and pass in the strengths of the tools
			game->setPlayerTool(toolType, rockStrength, paperStrength, scissorStrength);
			// Set the computer's tool from a random int (1-3) and pass in the strengths of the tools
			game->setComputerTool(rockStrength, paperStrength, scissorStrength);

			// Call the game play function
			game->play();

			// Call the print score function
			game->print();
		}
	} while (toolType != "e" && toolType != "E");

	// Delete the allocated memory
    delete game;

	return 0;
}
