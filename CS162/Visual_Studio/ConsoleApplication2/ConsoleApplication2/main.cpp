/***************************************************************************************
** Program name: main.cpp is the langton(Ant/Board) class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/07
** Description: CS162 Week1 Project1
** The Main program allows the user to select the menu option to run the Langton Ant
** simulation. The other menu options allow the user to modify various aspects of 
** the scenario (board size, initial ant location, starting direction, # of moves). 
** The initialization option returns the Ant/Board to its initial state (default values).
*****************************************************************************************/

#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "userMenu.hpp"
#include "langtonBoard.hpp"
#include "inputVerification.cpp"

int main() {

	int menuOpt;
	int numMoves;
	int cntMoves;
	srand(time(NULL));

	Ant* ant = new Ant();
	Board* board = new Board();

	userMenu menu;
//	menu.add_choice("Select a valid input option.\n");
	menu.add_choice("Begin / Continue simulation");
	menu.add_choice("Set table size [Height:Width] (default: [40:80])");
	menu.add_choice("Select the ant's starting position (default: center of board)");
	menu.add_choice("EXTRA CREDIT: Set a random starting position for the ant");
	menu.add_choice("Select the ant's starting direction (default: North)");
	menu.add_choice("Select the number of moves for the ant (default: 80)");
	menu.add_choice("Re-initialize ant scenario");
	menu.add_choice("Exit\n");

	menuOpt = menu.makeChoice();

	while (menuOpt != 8) {
		// Begin Lanton Ant simulation	
		if (menuOpt == 1) {

			cntMoves = 0;

			// Initialize the ant object
			board->setAnt(ant);

			// Get the current number of moves to execute (default: 80)
			numMoves = ant->getMoves();

			// Execute the Langton Ant's moves 
			while (cntMoves<numMoves) {
				// Outputs the current board status/layout
				board->output();
				// Move ant to next position
				board->moveAnt();
				std::cout << std::endl;
				// Sleep option to leave the board on the screen for 250 milliseconds
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
				cntMoves++;
				std::cout << "Current ant move is: " << cntMoves << "\n\n";
			}
			
		}

		// User selected board height/width
		else if (menuOpt == 2) {
			int b_Height;
			int b_Width;

			std::cout << "Please enter the height (less than 80) for the Langton Ant board. \n";

			// Error message for the inputVerification class
			char verString[100] = { "\nBoard size must be less than 80. \n" };

			// inputVerification for the user board height input (must be less than predefined value)
			SafeInput <int>(b_Height,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input <= 80));
			}, verString);

			std::cout << "Please enter the width (less than 80) for the Langton Ant board. \n";

			// inputVerification for the user board height input (must be less than predefined value)
			SafeInput <int>(b_Width,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input <= 80));
			}, verString);

			// Initialize a new board array using updated Heigh/Width values
			board->setBoard(b_Height, b_Width);

			// Set the board height based on valid user input
			board->setHeight(b_Height);
			// Recenter the ant's height position based on new board height
			ant->setY(board->getHeight() / 2);

			// Set the board width based on valid user input
			board->setWidth(b_Width);
			// Recenter the ant's width position based on new board width
			ant->setX(board->getWidth() / 2);

		}

		// User selected ant starting height/width position
		else if (menuOpt == 3) {
			int aHeight;
			int aWidth;
			int curHeight;
			int curWidth;

			// Get current board height 
			curHeight = board->getHeight();

			std::cout << "Please enter the height for the ant's starting position. \n";
			std::cout << "Must be less than board height of: " << curHeight << "\n";

			// Error message for the inputVerification class
			char verStringH[100] = { "\nAnt height must be less than board height. \n" };

			// inputVerification for the user ant height input (must be less than board height)
			SafeInput <int>(aHeight,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input <= curHeight));
			}, verStringH);

			// Set ant height based on valid user input
			ant->setY(aHeight - 1);

			// Get current board width
			curWidth = board->getWidth();

			std::cout << "Please enter the width for the ant's starting position. \n";
			std::cout << "Must be less than board width of: " << curWidth << "\n";

			// Error message for the inputVerification class
			char verStringW[100] = { "\nAnt width must be less than board width. \n" };

			// inputVerification for the user ant width input (must be less than board width)
			SafeInput <int>(aWidth,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input <= curWidth));
			}, verStringW);

			// Set ant width based on valid user input
			ant->setX(aWidth - 1);
		}

		// EXTRA CREDIT: Pick a random starting position for the ant
		else if (menuOpt == 4) {
			// Set the ant's width position between 0 and current board's width
			ant->setX(rand() % board->getWidth() + 1);

			// Set the ant's height position between 0 and current board's height
			ant->setY(rand() % board->getHeight() + 1);

			std::cout << "The random position is: [" << ant->getX() << "," << ant->getY() << "]";
		}

		// User selected ant starting direction
		else if (menuOpt == 5) {
			int antDir;
			std::cout << "Please enter the ant's starting direction \n0 for North\n1 for South\n2 for West\n3 for East\n";

			// Error message for the inputVerification class
			char verString[100] = { "\n0 for North\n1 for South\n2 for West\n3 for East\n" };

			// inputVerification for the user ant direction input (must be less than 3)
			SafeInput <int>(antDir,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input >= 0 && Input <= 3));
			}, verString);

			// Set the ant's starting direction
			ant->setDir(antDir);
//			std::cout << "Current ant direction is: " << antDir;
		}

		// User selected number of moves the ant should make
		else if (menuOpt == 6) {
			int b_Moves;

			std::cout << "Please enter the ant's number of moves (less than 1000). \n";

			// Error message for the inputVerification class
			char verString[100] = { "\nNumber of moves must be less than 1000. \n" };

			// inputVerification for the user ant moves input (must be less than 1000)
			SafeInput <int>(b_Moves,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input <= 1000));
			}, verString);

			// Set number of moves the ant will make
			ant->setMoves(b_Moves);
		}

		// Re-initialize the ant/board to default values
		else if (menuOpt == 7) {
			//Delete current ant object
			delete ant;
			ant = nullptr;

			// Delete current board object
			delete board;
			board = nullptr;

			// Setup a new ant object
			ant = new Ant();
			// Setup a new board object
			board = new Board();
		}

		// Re-populate menu selection options
		menuOpt = menu.makeChoice();
	} 

	// Delete ant/board objects
	delete ant;
	delete board;
	return 0;
}