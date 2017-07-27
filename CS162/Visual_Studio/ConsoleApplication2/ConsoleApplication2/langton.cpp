#include "langton.hpp"

#include <iostream>
#include <stdlib.h>

using namespace std;

Ant::Ant() {

	a_direction = static_cast<Direction>(0);
	setMoves(80);
	setX(40);
	setY(20);
}

Ant::~Ant() {
}

int Ant::getX() {
	return a_x;
}

int Ant::getY() {
	return a_y;
}

int Ant::getMoves() {
	return a_z;
}

int Ant::getDir() {
	return a_direction;
}

void Ant::setX(int x) {
	a_x = x-1;
}

void Ant::setY(int y) {
	a_y = y-1;
}

void Ant::setMoves(int z) {
	a_z = z;
}

void Ant::setDir(int d) {
	a_direction = static_cast<Direction>(d);
}

void Ant::turnR() {
	// turn 90 degress right, which is dependent on the current direction.
	switch (a_direction) {
	case DIR_NORTH: a_direction = DIR_EAST; a_x += 1; break; // move right in array
	case DIR_EAST: a_direction = DIR_SOUTH; a_y += 1; break; // move down in array
	case DIR_SOUTH: a_direction = DIR_WEST; a_x -= 1; break; // move left in array
	case DIR_WEST: a_direction = DIR_NORTH; a_y -= 1; break; // move up in array.
	default: a_direction = DIR_NORTH; break; // should not happen.
	}
}

void Ant::turnL() {
	// turn 90 degress left, which is dependent on the current direction.
	switch (a_direction) {
	case DIR_NORTH:	a_direction = DIR_WEST;	a_x -= 1; break; // move right in array
	case DIR_WEST: a_direction = DIR_SOUTH; a_y += 1; break; // move down in array
	case DIR_SOUTH: a_direction = DIR_EAST; a_x += 1; break; // move left in array
	case DIR_EAST: a_direction = DIR_NORTH; a_y -= 1; break; // move up in array.
	default: a_direction = DIR_NORTH; break;
	}
}

//-----------------------------------------------------------------------------

Board::Board() {
	setHeight(40);
	setWidth(80);
}

Board::~Board() {}

void Board::setAnt(Ant* ant) {
	a_ant = ant;
}

void Board::flipColor(Ant* ant) {

	int color = a_board[ant->getY()][ant->getX()];

	if (color == Board::OFF) {
		a_board[ant->getY()][ant->getX()] = Board::ON;
	}
	else {
		a_board[ant->getY()][ant->getX()] = Board::OFF;
	}
}

int Board::getColorAt(Ant* ant) {
//	std::cout << "The value on the plane: " << ant->getY()+1 << "  " << ant->getX()+1;
	// simply gets the value on the plane where the ant is residing.
	return a_board[ant->getY()][ant->getX()];
}

void Board::setHeight(int x) {
	HEIGHT = x;
}

void Board::setWidth(int y) {
	WIDTH = y;
}

void Board::setBoard(int h, int w) {
	//Creates matrix based on user input
	a_board = new int *[h];			//Matrix rows
	for (int mRow = 0; mRow < h; mRow++)
	{
		a_board[mRow] = new int[w];			//Matrix columns
	}

	// initialize an array with all zeroes. 
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			a_board[i][j] = 0;
		}
	}
	return;
}

int Board::getHeight() {
	return HEIGHT;
}

int Board::getWidth() {
	return WIDTH;
}

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

void Board::output() {
//	system("CLS");
	for (int i = 0; i < Board::getHeight(); i++) {
		for (int j = 0; j < Board::getWidth(); j++) {
			if (i == a_ant->getY() && j == a_ant->getX()) {
				cout << "@"; // Output the ant position on the board
			}
			else if (Board::a_board[i][j] == Board::OFF) {
				cout << "."; // for OFF colors, print a blank
			}
			else if (Board::a_board[i][j] == Board::ON) {
				cout << "#"; // for ON colors, print a pound
			}
		}
		cout << '\n';
	}
}