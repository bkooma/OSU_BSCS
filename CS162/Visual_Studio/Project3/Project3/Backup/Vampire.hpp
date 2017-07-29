/******************************************************************************
** Vampire.hpp is the Vampire derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project 3
** Description: Header file for the Vampire class.
******************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

class Vampire:public Creature {

public:
	Vampire();

	virtual int attack();
	virtual int defense();
	virtual void revive();
};

#endif