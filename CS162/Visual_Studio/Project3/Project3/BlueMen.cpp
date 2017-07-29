/*
 * BlueMen.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: bkooima
 */

#include "BlueMen.hpp"

BlueMen::BlueMen() {
	armor = 3;
	strength = 12;
	name = "Blue Men";
}

int BlueMen::attackRoll(){
	this->dieNumAttack = 2;
	this->dieSidesAttack = 10;
	this->specialAttack = "";

	int sum = sum_die(this->dieNumAttack, this->dieSidesAttack);

	return sum;
}

int BlueMen::defenseRoll(){
	if (this->strength > 8)
		this->dieNumDefense = 3;
	else if (this->strength > 4)
		this->dieNumDefense = 2;
	else if (this->strength > 0)
		this->dieNumDefense = 1;

	this->dieSidesDefense = 6;

	return sum_die(this->dieNumDefense, this->dieSidesDefense);
}

void BlueMen::revive(){
	strength = 12;
}

BlueMen::~BlueMen() {
	// TODO Auto-generated destructor stub
}

