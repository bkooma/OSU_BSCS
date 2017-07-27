/*************************************************************************************
** langtonBoard.cpp is the Board class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/06
** Description: CS162 Week2 Project1
** The Board class assigns an Ant class and performs the following options:
** flipColor: of the Ant
** getColorAt: Gets the value on on the board where the Ant is currently positioned
** get/set the Board Height/Width
** setBoard: Dynamically allocates array for the board
** moveAnt: Move ant to next position on board based on ant's direction
** checkBounds: Moves ant to opposite side of the board when it reaches the boundary
** output: Prints the current board layout 
**
** Citation: Sections of this code were referenced from
** https://ubuntuforums.org/showthread.php?t=812784&page=2
***************************************************************************************/

#include "langtonBoard.hpp"

#include <iostream>
#include <stdlib.h>

using namespace std;

// Default Constructor
Board::Board() {
	setHeight(40);
	setWidth(80);
	//Creates matrix based on user input
	a_board = new int *[getHeight()];			//Matrix rows
	for (int mRow = 0; mRow < getHeight(); mRow++)
	{
		a_board[mRow] = new int[getWidth()];			//Matrix columns
	}

	// initialize a Board array with all zeroes. 
	for (int i = 0; i < getHeight(); i++) {
		for (int j = 0; j < getWidth(); j++) {
			a_board[i][j] = 0;
		}
	}
}

// Destructor
Board::~Board() {
	//Frees dynamically allocated memory
	for (int mRow = 0; mRow < getHeight(); mRow++)
	{
		delete[] a_board[mRow];
	}
	delete[] a_board;
	a_board = 0;
}

// Sets the Ant class object
void Board::setAnt(Ant* ant) {
	a_ant = ant;
}

// Flips the color (" " or "#") for the Ant's position
void Board::flipColor(Ant* ant) {

	int color = a_board[ant->getY()][ant->getX()];

	if (color == Board::OFF) {
		a_board[ant->getY()][ant->getX()] = Board::ON;
	}
	else {
		a_board[ant->getY()][ant->getX()] = Board::OFF;
	}
}

// Returns the Ant's position on the board
int Board::getColorAt(Ant* ant) {
	return a_board[ant->getY()][ant->getX()];
}

// Sets the Height of the board.
void Board::setHeight(int x) {
	HEIGHT = x;
}

// Sets the Width of the Board.
void Board::setWidth(int y) {
	WIDTH = y;
}

// Gets the Height of the Board.
int Board::getHeight() {
	return HEIGHT;
}

// Gets the Width of the Board.
int Board::getWidth() {
	return WIDTH;
}

// Dynamically creates the Board based on Height/Width values
void Board::setBoard(int h, int w) {
	//Frees dynamically allocated memory
	for (int mRow = 0; mRow < getHeight(); mRow++)
	{
		delete[] a_board[mRow];
	}
	delete[] a_board;
	a_board = 0;

	//Creates matrix based on user input
	a_board = new int *[h];			//Matrix rows
	for (int mRow = 0; mRow < h; mRow++)
	{
		a_board[mRow] = new int[w];			//Matrix columns
	}

	// initialize a Board array with all zeroes. 
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			a_board[i][j] = 0;
		}
	}
	return;
}

// Move Ant based on current position and color of cell
void Board::moveAnt() {
	flipColor(a_ant); // flip a color where the current ant is.

	if (getColorAt(a_ant) == Board::OFF) {
		// if the color is off, turn left.
		a_ant->turnL();
	}
	else if (getColorAt(a_ant) == Board::ON) {
		// and if on, turn right.
		a_ant->turnR();
	}

	// check whether ant is out of bounds of the array. If so,
	// wrap around (i.e. x > height -> x = 0, etc.)
	checkBounds();
}

void Board::checkBounds() {
	// wrap around the Plane:
	if (a_ant->getX() < 0) {
		a_ant->setX(Board::getWidth() - 1);
	}

	if (a_ant->getY() < 0) {
		a_ant->setY(Board::getHeight() - 1);
	}

	if (a_ant->getX() > Board::getWidth() - 1) {
		a_ant->setX(0);
	}

	if (a_ant->getY() > Board::getHeight() - 1) {
		a_ant->setY(0);
	}
}

// Output the Board with ant's position and colors
void Board::output() {
	//	system("CLS");
	for (int i = 0; i < Board::getHeight(); i++) {
		for (int j = 0; j < Board::getWidth(); j++) {
			if (i == a_ant->getY() && j == a_ant->getX()) {
				cout << "@"; // Output the ant position on the board
			}
			else if (Board::a_board[i][j] == Board::OFF) {
				cout << " "; // for OFF colors, print a blank
			}
			else if (Board::a_board[i][j] == Board::ON) {
				cout << "#"; // for ON colors, print a pound
			}
		}
		cout << '\n';
	}
}