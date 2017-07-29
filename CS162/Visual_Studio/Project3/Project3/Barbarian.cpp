/*
 * Barbarian.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: bkooima
 */

#include "Barbarian.hpp"

Barbarian::Barbarian() {
	armor = 0;
	strength = 12;
	name = "Barbarian";
}

int Barbarian::attackRoll(){
	this->dieNumAttack = 2;
	this->dieSidesAttack = 6;
	this->specialAttack = "";

	int sum = sum_die(this->dieNumAttack, this->dieSidesAttack);

	return sum;
}

int Barbarian::defenseRoll(){
	this->dieNumDefense = 2;
	this->dieSidesDefense = 6;

	return sum_die (this->dieNumDefense, this->dieSidesDefense);
}

void Barbarian::revive(){
	strength = 12;
}
Barbarian::~Barbarian() {
	// TODO Auto-generated destructor stub
}

