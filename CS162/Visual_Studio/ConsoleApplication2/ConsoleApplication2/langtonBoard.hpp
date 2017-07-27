/*************************************************************************************
** langtonBoard.hpp is the langtonBoard class specification file.
** Author:  Byron Kooima
** Date: 2017/07/06
** Description: CS162 Week2 Project1
***************************************************************************************/

#ifndef LANGTONBOARD_HPP_
#define LANGTONBOARD_HPP_

#include "langtonAnt.hpp"

class Board {
	
private:

	/// The width of the board.
	int WIDTH;

	/// Height of the board.
	int HEIGHT;

	// Initialize the board array
	int **a_board = nullptr;

	/// Is a color 'on'?
	static const int ON = 1;

	/// Is a color 'off'?
	static const int OFF = 0;

	// Initialize the Ant object
	Ant* a_ant = nullptr;

public:
	
	// Default Constructor
	Board();

	// Destructor
	~Board();


	void setAnt(Ant*);
	void flipColor(Ant*);
	int getColorAt(Ant*);

	// Gets the Width of the Board.
	int getWidth();

	// Gets the Height of the Board.
	int getHeight();

	// Sets the Width of the Board.
	void setWidth(int x);

	// Sets the Height of the Board.
	void setHeight(int y);

	// Dynamically creates the Board based on Height/Width values
	void setBoard(int x, int y);

	// Move Ant based on current position and color of cell
	void moveAnt();

	// check whether ant is out of bounds of the array. If so,
	// wrap around (i.e. x > height -> x = 0, etc.)
	void checkBounds();

	// Output the Board with the Ant and colors
	void output();

};

#endif /*LANGTONBOARD_HPP_*/
