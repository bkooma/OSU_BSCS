/*************************************************************************************
** LoadedDie.cpp is the loaded die class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/14
** Description: CS162 Week3 Lab 3
** The LoadedDie class represents a loaded die and inherits from the Die class. It has
** a main constructor that accepts an int and uses the Die constructor to set numSides.
** Die also contains a method called roll_die that returns an int that represents a
** loaded random number based on the sides of the die.
***************************************************************************************/

#include "LoadedDie.hpp"
#include <cstdlib>

// Constructor that takes an integer for the number of sides and initializes Die
LoadedDie::LoadedDie(int numSides) : Die(numSides){
//	this->numSides = numSides;
}

// Returns a loaded value (using the rand function) from 1 to the numSides of the die
int LoadedDie::roll_die() const
{
	// If random number mod is 2 or less 
	if((rand() % 2 + 1) == 1)
	{
		// Run the normal rand function for numSides
		return (rand() % numSides + 1);
	}
	else
	{
		// Else just return the highest value (numSides)
		return numSides;
	}
}


