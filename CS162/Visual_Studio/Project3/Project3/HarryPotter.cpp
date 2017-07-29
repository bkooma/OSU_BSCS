/*
 * HarryPotter.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: bkooima
 */

#include "HarryPotter.hpp"

HarryPotter::HarryPotter() {
	armor = 0;
	strength = 10;
	harryLives = 1;
	name = "Harry Potter";
}

int HarryPotter::attackRoll()
{
	this->dieNumAttack = 2;
	this->dieSidesAttack = 6;
	this->specialAttack = "";

	int sum = sum_die(this->dieNumAttack, this->dieSidesAttack);

	return sum;
}

int HarryPotter::defenseRoll()
{
	this->dieNumDefense = 2;
	this->dieSidesDefense = 6;

	return sum_die(this->dieNumDefense, this->dieSidesDefense);
}

int HarryPotter::inflict_pain(int attack, int defense)
{
	int damage;
	damage = Creature::inflict_pain(attack,defense);


	if (this->harryLives > 0 && this->is_dead()){
		strength = 20;
		this->specialAttack = "Hogwarts";
		this->harryLives--;
	}

	return damage;
}

void HarryPotter::revive()
{
	strength = 10;
	this->harryLives = 1;
}

HarryPotter::~HarryPotter() {
	// TODO Auto-generated destructor stub
}

