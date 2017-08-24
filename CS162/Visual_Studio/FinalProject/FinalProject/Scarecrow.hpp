/******************************************************************************
** Scarecrow.hpp is the Scarecrow derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Scarecrow class represents a Creature derived class. It inherits the 
** variables from the Creature base class. It also uses the virtual functions 
** from the base class for the attack, defense and recover_strength. 
** It overrides the defense function to incorporate the addtional special 
** attack ability.
******************************************************************************/

#ifndef SCARECROW_HPP
#define SCARECROW_HPP

#include "Creature.hpp"

class Scarecrow:public Creature {

public:
	//Default constructor for Scarecrow.
	Scarecrow(int,int);

	//Attack roll of the dice for the Scarecrow.
	virtual int attack();
	//Defense roll of the dice for the Scarecrow.
	virtual int pain(int attack, int defense);
	//Revive the Scarecrow after the round is over
	virtual void recover_strength();

	// Destructor
	virtual ~Scarecrow();
};

#endif
