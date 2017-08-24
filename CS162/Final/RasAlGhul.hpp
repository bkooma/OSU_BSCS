/******************************************************************************
** RasAlGhul.hpp is the Ra's Al Ghul derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The RasAlGhul class represents a Creature derived class. It inherits the 
** variables from the Creature base class. It also uses the virtual functions 
** from the base class for the attack, defense and recover_strength. 
** It overrides the defense function to incorporate the addtional special 
** attack ability.
******************************************************************************/


#ifndef RASALGHUL_HPP
#define RASALGHUL_HPP

#include "Creature.hpp"

class RasAlGhul: public Creature {
public:
	//Default constructor for RasAlGhul.
	RasAlGhul(int, int);

	virtual int pain(int attack, int defense);
	//Revive Harry Potter to initial strength after the round is over
	virtual void recover_strength();

	// Destructor
	virtual ~RasAlGhul();
private:
	// Variable to keep track of RasAlGhul's lives
	int ghulLives;
};

#endif /* SRC_RasAlGhul_HPP_ */
