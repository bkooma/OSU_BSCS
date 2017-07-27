/*************************************************************************************
** Die.hpp is the die class specification file.
** Author:  Byron Kooima
** Date: 2017/07/14
** Description: CS162 Week3 Lab 3
** The Die class represents a normal die. It has a numSides integeger as a protected 
** member. It has a main constructor that accepts an int and sets the numSides to 
** that int value. Die also contains a virtual method called roll_die that returns
** an int that represents a random number based on the sides of the die.
***************************************************************************************/

#ifndef DIE_H
#define DIE_H

#include <cstdlib>

class Die
{

public:

	// Constructor that takes an integer for the number of sides
	Die(int numSides);

	// returns a random value from 1 to the numSides of the die
	virtual int roll_die() const;

	// virtual destructor
	virtual ~Die();

protected:
	// number of sides of the Die
	int numSides;
};

#endif
