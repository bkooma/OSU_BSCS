/*************************************************************************************
** Program name: main_Die.cpp is the Game class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/14
** Description: CS162 Week3 Lab 3
** The Main program allows the user to select the menu option to run the War game using
** two dice. The other menu options allow the user to modify various aspects of
** the scenario (Number of sides for player1/2 die, Loaded die for player1/2, and Number
** of rounds to play in the game).
** The play option executes the game using the provided (or default) parameters.
***************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.hpp"
#include "userMenu.hpp"
#include "inputVerification.cpp"

int main()
{
	// Initialize the variables
	int menuOpt;
	int dieLoaded = -1;
	int p1NumSides = 6;
	int p2NumSides = 6;
	int numRounds = 3;
	
	// Seed the random generator
	std::srand(static_cast<unsigned int>(time(0)));
	
	std::cout << "Let's play a friendly (and fair) game of Dice\n";

	// Populate the userMenu class vector with some options 
	userMenu mainMenu;
	mainMenu.add_choice("Enter Number of Sides for Player 1 Die (default: 6)");
	mainMenu.add_choice("Enter Number of Sides for Player 2 Die (default: 6)");
	mainMenu.add_choice("Load Player 1 or Player 2 Die");
	mainMenu.add_choice("Enter Number of Rounds to Play (default: 3)");
	mainMenu.add_choice("Let's Play!");
	mainMenu.add_choice("Exit");

	// Make sure the choice is valid
	menuOpt = mainMenu.makeChoice();

	// Populate a sub userMenu class vector with some additional options
	userMenu menu;
	//	menu.add_choice("Select a valid input option.\n");
	menu.add_choice("No loaded die this game?");
	menu.add_choice("Player 1 Die Loaded?");
	menu.add_choice("Player 2 Die Loaded?");
	menu.add_choice("Both Player 1 & 2 Die Loaded?");

	// Run through the menu options selected
	while (menuOpt != 6) {
		// If entering the number of sides for player 1 die
		if (menuOpt == 1) {
			char verString[100] = { "\nEnter number of sides for Player 1 die (Between 1 and 20).\n" };
			std::cout << verString;

			// Input validation function to make sure the p1NumSides variable entered by user is valid
			SafeInput <int>(p1NumSides,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input <= 20));
			}, verString);
		}

		// If entering the number of sides for player 2 die
		else if (menuOpt == 2) {
			char verString[100] = { "\nEnter number of sides for Player 2 die (Between 1 and 20).\n" };
			std::cout << verString;

			// Input validation function to make sure the p2NumSides variable entered by user is valid
			SafeInput <int>(p2NumSides,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input <= 20));
			}, verString);
		}

		// If selecting to load any players' die
		else if (menuOpt == 3) {
			dieLoaded = menu.makeChoice();
		}

		// If entering the number of rounds to be played
		else if (menuOpt == 4) {
			// Error message for the inputVerification class
			char verString[100] = { "\nEnter a number between 1 and 10000. \n" };
			std::cout << verString;

			// Input validation function to make sure the numRounds variable entered by user is valid
			SafeInput <int>(numRounds,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input <= 10000));
			}, verString);
		}

		// Play the game
		else if (menuOpt ==5) {
			// Call the Game constructor with the numRounds
			Game diceGame(numRounds);

			// Play the game passing in the number of sides for each die and whether any of them are loaded
			diceGame.play_game(p1NumSides, p2NumSides, dieLoaded);
		}
		
		// Re-populate menu selection options
		menuOpt = mainMenu.makeChoice();
	}
	return 0;
}