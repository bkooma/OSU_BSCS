#include "Vampire.hpp"

Vampire::Vampire()
{
	armor = 1;
	strength = 18;
	name = "Vampire";
}

int Vampire::attack()
{
	this->dieNumAttack = 2;
	this->dieSidesAttack = 6;
	this->specialAttack = "";

	int sum = sum_die(this->dieNumAttack, this->dieSidesAttack);

	return sum;
}

int Vampire::defense()
{
	this->dieNumDefense = 2;
	this->dieSidesDefense = 6;
	this->specialAttack = "";

	int Charm = rand() % 100 + 1;
	
	if (Charm > 50)
	{
		this->specialAttack = "Charm";
		return 100;
	}
	else
		return sum_die(this->dieNumDefense, this->dieSidesDefense);
}

void Vampire::revive()
{
	strength = 18;
}
