/******************************************************************************
** Creature.hpp is the Creature Base class specification file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week6 Project 3
** Description: Header file for the Creature class.
******************************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

// This class is the abstract representation of a tool used in rock paper sisscors.
class Creature {
protected:
	int strength;
	int armor;
	int points;
	std::string name;
	std::string specialAttack;
	int dieNumAttack;
	int dieNumDefense;
	int dieSidesAttack;
	int dieSidesDefense;

public:
	Creature();
//	Creature(int strength);
	virtual int attackRoll() = 0;
	virtual int defenseRoll() = 0;
	virtual int inflict_pain(int attack, int defense);
	virtual void revive() = 0;

	bool is_dead();
	int sum_die(int dieNum, int dieSides);

	std::string get_name();
	int get_strength();
	int get_armor();
	int get_points();
	std::string get_special();

	virtual ~Creature();
};

#endif
