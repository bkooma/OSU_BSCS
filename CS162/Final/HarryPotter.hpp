/******************************************************************************
** HarryPotter.hpp is the Harry Potter derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The HarryPotter class represents a Creature derived class. It inherits the 
** variables from the Creature base class. It also uses the virtual functions 
** from the base class for the attack_roll, defense_roll and recover_strength. 
** It overrides the defense_roll function to incorporate the addtional special 
** attack ability.
******************************************************************************/


#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

class HarryPotter: public Creature {
public:
	//Default constructor for HarryPotter.
	HarryPotter();

	//Attack roll of the dice for HarryPotter.
	virtual int attack_roll();
	//Defense roll of the dice for the HarryPotter.
	virtual int defense_roll(int);
	//Revive Harry Potter to initial strength after the round is over
	virtual void recover_strength();

	// Destructor
	virtual ~HarryPotter();
private:
	// Variable to keep track of HarryPotter's lives
	int harryLives;
};

#endif /* SRC_HARRYPOTTER_HPP_ */
