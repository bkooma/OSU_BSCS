#ifndef LANGTON_HPP_
#define LANGTON_HPP_
/**
* Ant class. Only has some basic information like position, and the
* current travelling direction. Only real modifier functions are
* for turning left or right.
*/
class Ant {

/// Direction, NESW.
	enum Direction { DIR_NORTH, DIR_SOUTH, DIR_WEST, DIR_EAST };

private:
	/// The current x position.
	int a_x;

	// The current y position.
	int a_y;

	// The current number of moves.
	int a_z;

public:

	/// The current direction.
	Direction a_direction;

	/**
	* Constructor.
	*/
	Ant();

	/**
	* Destructor.
	*/
	~Ant();

	/**
	* Turns left. Dependend on the current direction, the x or y
	* coordinate of the ant is changed.
	*/
	void turnL();

	/**
	* Turns right. Dependend on the current direction, the x or y
	* coordinate of the ant is changed.
	*/
	void turnR();

	/**
	* Gets the current x position of the ant.
	* @return the x position.
	*/
	int getX();

	/**
	* Gets the current y position of the ant.
	* @return the y position.
	*/
	int getY();

	int getDir();

	/**
	* Gets the current number of moves of the ant.
	*/
	int getMoves();

	/**
	* Sets the x position of the ant.
	* @param x The x position to set.
	*/
	void setX(int x);

	/**
	* Sets the y position of the ant.
	* @param y the y position of the ant to set.
	*/
	void setY(int y);

	void setDir(int d);

	/**
	* Sets the number of moves of the ant.
	*/
	void setMoves(int z);
};

/**
* The 'board' of the ant to move on, with a predetermined size.
* I couldn't figure out how to make this multidimensional array
* dynamic (some people told me to use std::vector on #irc on
* freenode.org, but I found that too much of a hassle just for
* this programming challenge :-)).
*/
class Board {
	
private:

	/// The current height position.
	int h_x;

	// The current width position.
	int w_y;

	Ant* a_ant = nullptr;

public:

	/// The width of the plane.
	int WIDTH;

	/// Height of the plane.
	int HEIGHT;

	int **a_board = nullptr;

	/// Is a space 'on'?
	static const int ON = 1;

	/// Is a space 'off'?
	static const int OFF = 0;

	// Default Constructor
	Board();

	/**
	* Constructor.
	*/
//	Plane(int h, int w);

	/**
	* Destructor.
	*/
	~Board();

	void setAnt(Ant*);
//	void initAnt(Ant*);
	void flipColor(Ant*);
	int getColorAt(Ant*);

	/**
	* Gets the current x position of the ant.
	* @return the x position.
	*/
	int getWidth();

	/**
	* Gets the current y position of the ant.
	* @return the y position.
	*/
	int getHeight();

	/**
	* Sets the x position of the ant.
	* @param x The x position to set.
	*/
	void setWidth(int x);

	/**
	* Sets the y position of the ant.
	* @param y the y position of the ant to set.
	*/
	void setHeight(int y);

	void setBoard(int x, int y);

	void output();
	void checkBounds();
	void moveAnt();

};

#endif /*LANGTON_HPP_*/
