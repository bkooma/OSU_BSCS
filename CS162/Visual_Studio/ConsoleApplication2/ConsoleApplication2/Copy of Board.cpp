/*************************************************************************************
** Board.cpp is the Board class function implementation file. 
** Author:  Byron Kooima
** Date: 2017/03/08
** Description: CS161 Week9 Assignment 9 Project
** The Board class represents a tic-tac-toe board. It has a 3x3 array as a data member,
** which stores the locations of the players' moves. It has a default constructor that 
** initializes the 3x3 array to empty (using '.' char). Board also contains a method 
** called makeMove that accepts as parameters the x and y coordinates of the move along
**  with which player's turn it is. The method determines if the position is already 
** occupied and either records the move and returns true or returns false. There is also
** a method called gameState that returns one of the enum values based on the board 
** status. There is also a method called print, which just prints out the current board.
***************************************************************************************/

#include <iostream>
#include <string>
#include "Board.hpp"


// Default Board constructor
Board::Board() {
	//Loop through rows
	for (int i = 0; i < 3; i++) {

		//Loop through columns
		for (int j = 0; j < 3; j++) {
			boardCharArr[i][j] = '.';
		}
	}
}

// Board makeMove
bool Board::makeMove(int row, int col, char currentPlayer)
{
	if ((row >= 0) && (row < 3)) {
		if ((col >= 0) && (col < 3)) {
			// Check to see if that array element is already taken
			if (boardCharArr[row][col] == '.') {
				// If it is not, set the array element to the current player
				boardCharArr[row][col] = currentPlayer;
				return true;
			}
		}
	}
	return false;
}

// Board print
void Board::print()
{
	// Print some empty lines
	std::cout << std::endl << std::endl;
	// Print the header of the board
	std::cout << "   0  1  2  " << std::endl;
	// Output the char contained in each cell of the array
	for (int i = 0; i < 3; i++) {
		std::cout << i << "  ";
		for (int j = 0; j < 3; j++) {
			std::cout << boardCharArr[i][j] << "  ";
		}
		// Add a couple more empty lines
		std::cout << std::endl << std::endl << std::endl;
	}
}

// Game state
gameStatus Board::gameState()
{
	gameStatus gameEnumState;
	char winner = 0;

	// Default game status to DRAW
	gameEnumState = DRAW;

	// Check if board is full
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (boardCharArr[i][j] == '.') {
				// If '.' exists in array, set to game status to UNFINISHED
				gameEnumState = UNFINISHED;
			}
		}
	}

	// Check if their is a row or column with any winners
	for (int i = 0; i < 3; i++) {
		// Check to see if any column has a winner
		if ((boardCharArr[0][i] != '.') && (boardCharArr[0][i] == boardCharArr[1][i]) && (boardCharArr[1][i] == boardCharArr[2][i])) {
			// winner is set to the char of the winning player
			winner = boardCharArr[0][i];
		}
		// Check to see if any row has a winner
		else if ((boardCharArr[i][0] != '.') && (boardCharArr[i][0] == boardCharArr[i][1]) && (boardCharArr[i][1] == boardCharArr[i][2])) {
			// winner is set to the char of the winning player
			winner = boardCharArr[i][0];
		}
	}
	
	// Check if there is a diagonal with a winner
	if ((boardCharArr[0][0] != '.') && (boardCharArr[0][0] == boardCharArr[1][1]) && (boardCharArr[1][1] == boardCharArr[2][2])) {
		// winner is set to the char of the winning player
		winner = boardCharArr[0][0];
	}
	else if ((boardCharArr[0][2] != '.') && (boardCharArr[0][2] == boardCharArr[1][1]) && (boardCharArr[1][1] == boardCharArr[2][0])) {
		// winner is set to the char of the winning player
		winner = boardCharArr[0][2];
	}

	// If x is the winner, set game status to X_WON
	if (winner == 'x') {
		gameEnumState = X_WON;
	}
	// If o is the winner, set game status to O_WON
	else if (winner == 'o') {
		gameEnumState = O_WON;
	}

	// Return the board status
	return gameEnumState;
}

// Board destructor
Board::~Board()
{}
