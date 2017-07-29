/******************************************************************************
** BlueMen.hpp is the Blue Men derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project 3
** Description: Header file for the Blue Men class.
******************************************************************************/


#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

class BlueMen: public Creature {
public:
	BlueMen();

	virtual int attackRoll();
	virtual int defenseRoll();
	virtual void revive();

	virtual ~BlueMen();
};

#endif /* SRC_BLUEMEN_HPP_ */
