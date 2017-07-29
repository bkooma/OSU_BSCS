/******************************************************************************
** Medusa.hpp is the Medusa derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project 3
** Description: Header file for the Medusa class.
******************************************************************************/


#include "Medusa.hpp"

Medusa::Medusa() {
	armor = 3;
	strength = 8;
	name = "Medusa";
}

int Medusa::attackRoll()
{
	this->dieNumAttack = 2;
	this->dieSidesAttack = 6;
	this->specialAttack = "";

	int sum = sum_die(this->dieNumAttack, this->dieSidesAttack);

	if (sum > 8){
		this->specialAttack = "Glare";
	}
	return sum;
}

int Medusa::defenseRoll()
{
	this->dieNumDefense = 1;
	this->dieSidesDefense = 6;
	this->specialAttack = "";

	return sum_die(this->dieNumDefense, this->dieSidesDefense);
}

void Medusa::revive()
{
	strength = 8;
}

Medusa::~Medusa() {
	// TODO Auto-generated destructor stub
}

