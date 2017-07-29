#include "Vampire.hpp"

Vampire::Vampire()
{
	armor = 1;
	strength = 18;
	name = "Vampire";
}

int Vampire::attackRoll()
{
	this->dieNumAttack = 2;
	this->dieSidesAttack = 6;
	this->specialAttack = "";

	int sum = sum_die(this->dieNumAttack, this->dieSidesAttack);

	return sum;
}

int Vampire::defenseRoll()
{
	this->dieNumDefense = 1;
	this->dieSidesDefense = 12;

	return sum_die(this->dieNumDefense, this->dieSidesDefense);
}

int Vampire::inflict_pain(int attack, int defense)
{
	this->specialAttack = "";

	int Charm = rand() % 100 + 1;
	
	if (Charm > 50)
	{
		this->specialAttack = "Charm";
		return 0;
	}

	return Creature::inflict_pain(attack, defense);
}

void Vampire::revive()
{
	strength = 18;
}

Vampire::~Vampire(){

}
