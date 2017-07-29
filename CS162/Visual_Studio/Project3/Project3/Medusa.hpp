/*
 * Medusa.hpp
 *
 *  Created on: Jul 27, 2017
 *      Author: bkooima
 */

#ifndef SRC_MEDUSA_HPP_
#define SRC_MEDUSA_HPP_

#include "Creature.hpp"

class Medusa: public Creature {
public:
	Medusa();

	virtual int attackRoll();
	virtual int defenseRoll();
	virtual void revive();

	virtual ~Medusa();
};

#endif /* SRC_MEDUSA_HPP_ */
