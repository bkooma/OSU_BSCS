/*************************************************************************************
** Die.cpp is the die class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/14
** Description: CS162 Week3 Lab 3
** The Die class represents a normal die. It has a numSides integeger as a protected
** member. It has a main constructor that accepts an int and sets the numSides to
** that int value. Die also contains a virtual method called roll_die that returns
** an int that represents a random number based on the sides of the die.
***************************************************************************************/

#include "Die.hpp"
#include <cstdlib>
#include <iostream>

// Constructor that takes an integer for the number of sides
Die::Die(int numSides) {
	{
		this->numSides = numSides;
	}
}

// returns a value (using the rand function) from 1 to the numSides of the die
int Die::roll_die() const {
	{
		return (rand() % numSides + 1);
	}
}

// Destructor
Die::~Die() {

}