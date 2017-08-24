/******************************************************************************
** Batman.hpp is the Blue Men derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Batman class represents a Creature derived class. It inherits the 
** variables from the Creature base class. It also uses the virtual functions 
** from the base class for the attack, defense and recover_strength.
******************************************************************************/

#ifndef BATMAN_HPP
#define BATMAN_HPP

#include "Creature.hpp"
#include <fstream>
#include <vector>

class Batman: public Creature {
public:
	// Default constructor for Batman.
	Batman(int, int);

	//Offense roll of the dice for Batman.
	virtual int attack();

	//Defense roll of the dice for the Batman.
	int defense();
	
	// Inflict pain on Batman
	int pain(int attack, int defense);

	//Revive the Batman after the round is over
	virtual void recover_strength();

	// Prints the end credit screen
	void endScreen(bool);

	// Destructor
	virtual ~Batman();

};

#endif /* SRC_BLUEMEN_HPP_ */
