/******************************************************************************
** BlueMen.hpp is the Blue Men derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The BlueMen class represents a Creature derived class. It inherits the 
** variables from the Creature base class. It also uses the virtual functions 
** from the base class for the attack_roll, defense_roll and recover_strength.
******************************************************************************/


#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

class BlueMen: public Creature {
public:
	// Default constructor for BlueMen.
	BlueMen();

	//Attack roll of the dice for the BlueMen.
	virtual int attack_roll();
	//Defense roll of the dice for the BlueMen.
	virtual int defense_roll(int);
	//Revive the BlueMen after the round is over
	virtual void recover_strength();

	// Destructor
	virtual ~BlueMen();
};

#endif /* SRC_BLUEMEN_HPP_ */
