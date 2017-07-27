/*************************************************************************************
** Board.hpp is the Board class specification file.
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

#ifndef BOARD_HPP
#define BOARD_HPP
#include <string>
#include <stdio.h>

// Definition of enum game states
enum gameStatus {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
private:
	// 3x3 Array member
	char boardCharArr[3][3];
	// 
	char currentPlayer;
	gameStatus gameEnumState;

public:
	// default constructor
	Board();

	// Metod for makeMove
	bool makeMove(int row, int col, char player);

	// Method for returning game status
	gameStatus gameState();

	// Method for printing the board
	void print();

	//destructor
	~Board();
};

#endif // !BOARD_HPP

