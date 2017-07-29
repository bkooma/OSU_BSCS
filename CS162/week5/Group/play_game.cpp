/***************************************************************************************
** Program name: play_game.cpp is the Rock, Paper, Scissors Game implementation file.
** Author:  Byron Kooima
** Date: 2017/07/30
** Description: CS162 Week5 Group10
** The Main program 
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
	std::string strengthSet;
	std::string toolType;
	int rockStrength = 1;
	int paperStrength = 1;
	int scissorStrength = 1;
 	std::string varString;


	// Set seed for random function
    std::srand(static_cast<unsigned int>(time(0)));

	RPSGame* game = new RPSGame();

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

	if (strengthSet == "y" || strengthSet == "Y") {
		varString = "Please enter an integer value (>0).\n";
		std::cout << "What level of strength should the Rock tool have?  ";

		SafeInput <int>(rockStrength,
			[=](int Input) -> bool {
			return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
		}, varString);

		std::cout << "What level of strength should the Paper tool have?  ";
		SafeInput <int>(paperStrength,
			[=](int Input) -> bool {
			return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
		}, varString);

		std::cout << "What level of strength should the Scissors tool have?  ";
		SafeInput <int>(scissorStrength,
			[=](int Input) -> bool {
			return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
		}, varString);
	}



	do {

		std::cout << "Please select your tool type ('p'-Paper, 'r'-Rock, 's'-Scissors, 'e'-Exit)\n";
		varString = "Please enter a valid option ('p'-Paper, 'r'-Rock, 's'-Scissors, 'e'-Exit)\n";

		SafeInput <std::string>(toolType,
			[=](std::string Input) -> bool {
			std::transform(Input.begin(), Input.end(),
				Input.begin(), ::toupper);
			return (Input.compare("P") == 0 || Input.compare("R") == 0 || Input.compare("S") == 0 || Input.compare("E") == 0);
			}, varString);

		if (toolType != "e" && toolType != "E") {
			game->setPlayerTool(toolType, rockStrength, paperStrength, scissorStrength);
			game->setComputerTool(rockStrength, paperStrength, scissorStrength);

			game->play();

			game->printScore();
		}
	} while (toolType != "e" && toolType != "E");

    delete game;

	return 0;
}
