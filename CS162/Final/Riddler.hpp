/******************************************************************************
** Riddler.hpp is the Riddler derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Riddler class represents a Creature derived class. It inherits the 
** variables from the Creature base class. It also uses the virtual functions 
** from the base class for the attack, defense and recover_strength. 
******************************************************************************/

#ifndef RIDDLER_HPP
#define RIDDLER_HPP

#include "Creature.hpp"

class Riddler:public Creature {

public:
	//Default constructor for Riddler.
	Riddler(int strngth, int arm);

	//Attack roll of the dice for the Riddler.
	virtual int attack();
	//Defense roll of the dice for the Riddler.
	virtual int pain(int attack, int defense);
	//Revive the Riddler after the round is over
	virtual void recover_strength();

	// Destructor
	virtual ~Riddler();
};

#endif
