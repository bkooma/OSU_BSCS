/*************************************************************************************
** LoadedDie.hpp is the loaded die class specification file.
** Author:  Byron Kooima
** Date: 2017/07/14
** Description: CS162 Week3 Lab 3
** The LoadedDie class represents a loaded die and inherits from the Die class. It has 
** a main constructor that accepts an int and uses the Die constructor to set numSides.
** Die also contains a method called roll_die that returns an int that represents a 
** loaded random number based on the sides of the die.
***************************************************************************************/

#ifndef LOADEDDIE_H
#define LOADEDDIE_H

#include <cstdlib>
#include "Die.hpp"

class LoadedDie : public Die
{

public:
	LoadedDie(int numSides);

	// returns a value between 1 and the number of sides
	int roll_die() const;
	
};

#endif // !LOADEDDIE_HPP
