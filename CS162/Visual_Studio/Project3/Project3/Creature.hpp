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
	int defPoints;
	std::string name;
	std::string specialAttack;
	int dieNumAttack;
	int dieNumDefense;
	int dieSidesAttack;
	int dieSidesDefense;

public:
	//Default constructor for Creature.
	Creature();
	// Pure abstract functions 
	// Determin the attack damage 
	virtual int attack_roll() = 0;
	// Restore the creature to full strength
	virtual void recover_strength() = 0;

	// Getters
	std::string get_name();
	int get_strength();
	int get_armor();
	int get_defPoints();
	std::string get_special();

	// Standard function for all creatures to determine the	damage inflicted during a round
	virtual int defense_roll(int);
	// Standard function for all creatures to roll the die for either offense or defense
	int die_roll(int dieNum, int dieSides);
	// Standard function for all creatures to determine if the Creature has been defeated
	bool defeated();
	
	// Destructor
	virtual ~Creature();
};

#endif
