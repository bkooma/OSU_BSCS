#ifndef LANGTON_HPP_
#define LANGTON_HPP_
/**
* Ant class. Only has some basic information like position, and the
* current travelling direction. Only real modifier functions are
* for turning left or right.
*/
class Ant {
public:

	/// Direction, NESW.
	enum Direction {
		DIR_NORTH, DIR_SOUTH, DIR_WEST, DIR_EAST
	};

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
	void turnLeft();

	/**
	* Turns right. Dependend on the current direction, the x or y
	* coordinate of the ant is changed.
	*/
	void turnRight();

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

private:
	/// The current direction.
	Direction m_direction;

	/// The current x position.
	int m_x;

	// The current y position.
	int m_y;
};

/**
* The 'board' of the ant to move on, with a predetermined size.
* I couldn't figure out how to make this multidimensional array
* dynamic (some people told me to use std::vector on #irc on
* freenode.org, but I found that too much of a hassle just for
* this programming challenge :-)).
*/
class Plane {
public:

	/// The width of the plane.
	static const int WIDTH = 30;

	/// Height of the plane.
	static const int HEIGHT = 18;

	/// Is a space 'on'?
	static const int ON = 1;

	/// Is a space 'off'?
	static const int OFF = 0;

	/**
	* Constructor.
	*/
	Plane();

	/**
	* Destructor.
	*/
	~Plane();

	/// Meh, can't be arsed to comment this further.

	void setAnt(Ant*);
	void flipColor(Ant*);
	int getColorAt(Ant*);
	int getWidth();
	int getHeight();
	void output();
	void checkWrap();
	void moveAnt();

private:
	int m_plane[HEIGHT][WIDTH];

	Ant* m_ant;
};

#endif /*LANGTON_HPP_*/
