/*************************************************************************************
** langtonAnt.hpp is the langtonAnt class specification file.
** Author:  Byron Kooima
** Date: 2017/07/06
** Description: CS162 Week2 Project1
***************************************************************************************/

#ifndef LANGTONANT_HPP_
#define LANGTONANT_HPP_

class Ant {

/// Direction
	enum Direction { DIR_NORTH, DIR_SOUTH, DIR_WEST, DIR_EAST };

private:
	/// The current x position.
	int a_x;

	// The current y position.
	int a_y;

	// The current number of moves.
	int a_z;

	/// The current direction.
	Direction a_direction;

public:

	//Constructor
	Ant();

	//Destructor
	~Ant();

	// Gets the current x position of the ant.
	int getX();

	// Gets the current y position of the ant.
	int getY();

	// Gets the current dirction of the ant.
	int getDir();

	// Gets the current number of moves of the ant.
	int getMoves();

	// Sets the x position of the ant.
	void setX(int x);

	// Sets the y position of the ant.
	void setY(int y);

	// Sets the direction of the ant.
	void setDir(int d);

	// Sets the number of moves of the ant.
	void setMoves(int z);

	// Turns left. Dependend on the current direction, the x or y
	// coordinate of the ant is changed.
	void turnL();

	// Turns right. Dependend on the current direction, the x or y
	// coordinate of the ant is changed.
	void turnR();
};

#endif /*LANGTONANT_HPP_*/
