#include "Creature.hpp"
#include <cstdlib>
#include <ctime>

Creature::Creature()
{
	strength = 0;
	armor = 0;
	points = 0;
	name = "";
	specialAttack = "";
	dieNumAttack = 0;
	dieSidesAttack = 0;

	// Set seed for random function
	std::srand(static_cast<unsigned int>(time(0)));
}

int Creature::take_damage(int attack, int defense)
{
	attack -= armor;
	int damage = attack - defense;

	if (damage > 0)
	{
		strength -= damage;
		return damage;
	}
	return 0;
}

bool Creature::is_dead()
{
	return strength <=0;
}

int Creature::sum_die(int dieNum, int dieSides)
{
	int sum(0);
	for (int i = 0; i < dieNum; i++)
	{
		sum += rand() % dieSides + 1;
	}
	return sum;
}

std::string Creature::get_name()
{
	return name;
}

int Creature::get_strength()
{
	return strength;
}

int Creature::get_armor()
{
	return armor;
}

int Creature::get_points()
{
	return points;
}

std::string Creature::get_special()
{
	return specialAttack;
}
