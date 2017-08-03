/******************************************************************************
** HarryPotter.hpp is the Harry Potter derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project 3
** Description: Header file for the HarryPotter class.
******************************************************************************/


#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

class HarryPotter: public Creature {
public:
	HarryPotter();

	virtual int attack_roll();
	virtual int defense_roll();
	virtual void recover_strength();
	virtual int inflict_pain(int attack, int defense);

	virtual ~HarryPotter();
private:
	int harryLives;
};

#endif /* SRC_HARRYPOTTER_HPP_ */
