/******************************************************************************
** Barbarian.hpp is the Barbarian derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Barbarian class represents a Creature derived class. It inherits the 
** variables from the Creature base class. It also uses the virtual functions 
** from the base class for the attack_roll, defense_roll and recover_strength.
******************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian: public Creature {

public:
	// Default constructor for Barbarian.
	Barbarian();

	//Attack roll of the dice for the Barbarian.
	virtual int attack_roll();
	//Revive the Barbarian after the round is over
	virtual void recover_strength();

	// Destructor
	virtual ~Barbarian();
};

#endif /* SRC_BARBARIAN_H_ */
