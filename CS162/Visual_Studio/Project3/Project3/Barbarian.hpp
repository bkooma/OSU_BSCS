/******************************************************************************
** Barbarian.hpp is the Barbarian derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project 3
** Description: Header file for the Barbarian class.
******************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian: public Creature {

public:
	Barbarian();

	virtual int attack_roll();
	virtual int defense_roll();
	virtual void recover_strength();

	virtual ~Barbarian();
};

#endif /* SRC_BARBARIAN_H_ */
