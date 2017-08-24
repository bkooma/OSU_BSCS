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
#include "UtilityBelt.hpp"
#include "inputVerification.cpp"


class Creature {
protected:
	int strength;
	int armor;
	int defPoints;
	std::string name;
	std::string creatureInfo;
	std::string specialAttack;
	int dieNumAttack;
	int dieNumDefense;
	int dieSidesAttack;
	int dieSidesDefense;
	UtilityBelt* uBelt;

public:
	//Default constructor for Creature.
	Creature(int, int);
	// Pure abstract functions 
	// Restore the creature to full strength
	virtual void recover_strength() = 0;

	// Getters
	std::string get_name();
	std::string get_creatureInfo();
	int get_strength();
	int get_armor();
	int get_defPoints();
	std::string get_special();

	// Standard function for all creatures to determine the	damage inflicted during a round
	virtual int defense();

	// Determine the attack damage
	virtual int attack();

	virtual int pain(int attack, int defense);

	virtual void add_inventory(std::string, std::string, int, bool);

	virtual void remove_inventory();

	void transfer_qty(std::string, Creature*);

	void get_itemName();

	bool search_items(std::string iName);
	// Standard function for all creatures to roll the die for either offense or defense
	int die_roll(int dieNum, int dieSides);
	// Standard function for all creatures to determine if the Creature has been defeated
	bool defeated();
	
	// Destructor
	virtual ~Creature();
};

#endif
