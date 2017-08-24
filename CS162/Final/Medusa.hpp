/******************************************************************************
** Medusa.hpp is the Medusa derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Medusa class represents a Creature derived class. It inherits the 
** variables from the Creature base class. It also uses the virtual functions 
** from the base class for the attack_roll, defense_roll and recover_strength. 
** Medusa also has the ability to Glare an opponent and remove all their 
** strength in one hit
******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

class Medusa: public Creature {
public:
	//Default constructor for Medusa.
	Medusa();

	//Attack roll of the dice for Medusa. 
	virtual int attack_roll();
	//Defense roll of the dice for Medusa.
	virtual int defense_roll(int);
	//Revive Medusa after the round is over
	virtual void recover_strength();

	// Destructor
	virtual ~Medusa();
};

#endif /* SRC_MEDUSA_HPP_ */
