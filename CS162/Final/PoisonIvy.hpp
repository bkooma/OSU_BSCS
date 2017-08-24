/******************************************************************************
** PoisonIvy.hpp is the PoisonIvy derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week8 Final Project
** The PoisonIvy class represents a Creature derived class. It inherits the 
** variables from the Creature base class. It also uses the virtual functions 
** from the base class for the attack, defense and recover_strength. 
** PoisonIvy also has the ability to Seduce an opponent and remove all their 
** strength in one hit
******************************************************************************/

#ifndef POISONIVY_HPP
#define POISONIVY_HPP

#include "Creature.hpp"

class PoisonIvy: public Creature {
public:
	//Default constructor for PoisonIvy.
	PoisonIvy(int, int);

	//Offense roll of the dice for Poison Ivy.
	virtual int attack();
	//Defense roll of the dice for Poison Ivy.
	virtual int pain(int attack, int defense);
	//Revive Poison Ivy after the round is over
	virtual void recover_strength();

	// Destructor
	virtual ~PoisonIvy();
};

#endif /* SRC_POISONIVY_HPP_ */
