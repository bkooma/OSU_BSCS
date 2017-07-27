/*************************************************************************************
** TicTacToe.cpp is the TicTacToe class function implementation file.
** Author:  Byron Kooima
** Date: 2017/03/08
** Description: CS161 Week9 Assignment 9 Project
** The TicTacToe class has two fields - a Board object and current player character. It
** has a constructor that takes a char parameter that determines whether 'x' or 'o' 
** should have the first move. It has a method called play that starts a game. The play
** method keeps looping until someone has won or it's a draw and then declares outcome.
***************************************************************************************/

#include "TicTacToe.hpp"
#include <iostream>
#include <cstring>
#include <string>

// default constructor
TicTacToe::TicTacToe()
{}

// Set who has the first move
TicTacToe::TicTacToe(char p)
{
	while ((p != 'x') && (p != 'o'))
	{
		std::cout << "That is not a valid starting player. Please enter 'x' or 'o' " << std::endl;
		std::cin >> p;
	}
	playerTurn = p;
}

// TicTacToe play
void TicTacToe::play()
{
	int row, col;
	// Initialize the board
	board1;
	// Print the empty board
	board1.print();

	// While loop to play the game until there is a winner or a draw
	while (board1.gameState() == UNFINISHED) {
		std::cout << "Player " << playerTurn << ": please enter your move." << std::endl;
		// Accept coordinates for move from command line
		std::cin >> row >> col;

		// Check if the square is already taken
		if (!board1.makeMove(row, col, playerTurn)) {
			std::cout << "That square is already taken" << std::endl;
		}
		// Switch player to 'o'
		else if(playerTurn == 'x') {
			playerTurn = 'o';
		}
		// Switch player to 'x'
		else {
			playerTurn = 'x';
		}
		// Print the current board
		board1.print();
	}

	// Check if 'x' has won
	if (board1.gameState() == X_WON) {
		std::cout << std:: endl << "Player x is the winner!" << std:: endl << std::endl;
	}
	// Check if 'o' has won
	else if (board1.gameState() == O_WON) {
		std::cout << std::endl << "Player o is the winner!" << std::endl << std::endl;
	}
	// Check if the board is filled and there is no winner
	else if (board1.gameState() == DRAW) {
		std::cout << std::endl << "The game ended in a draw." << std::endl << std::endl;
	}
}


// TicTacToe destructor
TicTacToe::~TicTacToe()
{}

int main()
{
	char player;
	std::cout << "Shall we play a game? Who will go first (Enter x or o)" << std::endl;
	std::cin >> player;

	// Initialize game to TicTacToe class
	TicTacToe* game = new TicTacToe(player);
	// Play the game
	game->play();

	// Free up heap memory
	delete game;
	game = NULL;

	return 0;
}