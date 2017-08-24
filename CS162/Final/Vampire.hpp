/******************************************************************************
** Vampire.hpp is the Vampire derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Vampire class represents a Creature derived class. It inherits the 
** variables from the Creature base class. It also uses the virtual functions 
** from the base class for the attack_roll, defense_roll and recover_strength. 
** It overrides the defense_roll function to incorporate the addtional special 
** attack ability.
******************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

class Vampire:public Creature {

public:
	//Default constructor for Vampire.
	Vampire();

	//Attack roll of the dice for the Vampire.
	virtual int attack_roll();
	//Defense roll of the dice for the Vampire.
	virtual int defense_roll(int);
	//Revive the Vampire after the round is over
	virtual void recover_strength();

	// Destructor
	virtual ~Vampire();
};

#endif
