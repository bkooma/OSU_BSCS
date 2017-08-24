/*************************************************************************************
** Creature.cpp is the Creature base class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Creature class represents a Creature Base Class for the combatGame. This class is
** an abstract class for all of the Creature subclasses.
***************************************************************************************/

#include "Creature.hpp"
#include <ctime>
#include "userMenu.hpp"

/*********************************************************************
** Function: Creature::Creature
** Description: Default constructor for Creature. Sets all protected
**				members to default values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Creature members set to default.
*********************************************************************/
Creature::Creature(int strngth, int arm)
{
	this->strength = strngth;
	this->armor = arm;
	defPoints = 0;
	name = "";
	creatureInfo = "";
	specialAttack = "";
	dieNumAttack = 0;
	dieSidesAttack = 0;
	dieNumDefense = 0;
	dieSidesDefense = 0;
	uBelt = new UtilityBelt();
	// Set seed for random function
	std::srand(static_cast<unsigned int>(time(0)));
}

// Getters
/*********************************************************************
** Function: Creature::get_name()
** Description: Getter for returning the Creature name
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns a string of the Creature name.
*********************************************************************/
std::string Creature::get_name()
{
	return name;
}

/*********************************************************************
** Function: Creature::get_creatureInfo()
** Description: Getter for returning the Creature information
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns a string of the Creature information.
*********************************************************************/
std::string Creature::get_creatureInfo()
{
	return creatureInfo;
}

/*********************************************************************
** Function: Creature::get_strength()
** Description: Getter for returning the Creature strength
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int of the Creature strength.
*********************************************************************/
int Creature::get_strength()
{
	return strength;
}

/*********************************************************************
** Function: Creature::get_armor()
** Description: Getter for returning the Creature armor
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int of the Creature armor.
*********************************************************************/
int Creature::get_armor()
{
	return armor;
}

/*********************************************************************
** Function: Creature::get_points()
** Description: Getter for returning the Creature points
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int of the Creature points.
*********************************************************************/
int Creature::get_defPoints()
{
	return defPoints;
}

/*********************************************************************
** Function: Creature::get_special()
** Description: Getter for returning the Creature's special attack
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns a string of the Creature's special attack.
*********************************************************************/
std::string Creature::get_special()
{
	return specialAttack;
}

/*********************************************************************
** Function: Creature::defense(int)
** Description: Standard function for all creatures to determine the
**				damage inflicted during a round
** Parameters:	attack			The value of the attack die roll
** Pre-Conditions: N/A
** Post-Conditions: Returns an int for the damage inflicted after
**					calculating the offense roll minus the defense 
**					roll and armor. Will return 0 if the damage is
**					less than 0
*********************************************************************/
int Creature::defense()
{
	this->specialAttack = "";
	// Call the die_roll function for defense die
	defPoints = die_roll(this->dieNumDefense, this->dieSidesDefense);
	return defPoints;

}

/*********************************************************************
** Function: Creature::attack()
** Description: Attack roll of the dice for the Creature. Passes the
**				attack die to the die_roll function to get the attack
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Creature::attack()
{
	// Reset the special attack to nothing
	this->specialAttack = "";

	// Call the die_roll function for attack die
	return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

int Creature::pain(int attack, int defense)
{
	// Calculation for subtracting the defending creatures total defense
	// from the attack roll
	int total_pain = attack - (defense + armor);

	if (total_pain > 0)
	{
		// If damage is greater than 0, subtract the damage from the strength
		strength = strength - total_pain;
		return total_pain;
	}
	// If damage is negative, return 0
	return 0;
}

void Creature::add_inventory(std::string iName, std::string uName, int qInput, bool special)
{
	uBelt->addItems(iName, uName, qInput, special);
}

void Creature::remove_inventory()
{
	uBelt->removeItems();
}

void Creature::transfer_qty(std::string iName, Creature* batman)
{
	Item tempItem;
	if (search_items(iName)) {
		tempItem = uBelt->returnItem(iName);
		std::cout << "You received: " << tempItem.get_itemName() << std::endl;
		batman->add_inventory(tempItem.get_itemName(), tempItem.get_itemDesc(), 1, tempItem.get_special());
		uBelt->removeQty(iName);
	}
}

void Creature::get_itemName()
{
	uBelt->printItems();
}

bool Creature::search_items(std::string iName)
{
	return uBelt->searchItems(iName);
}

/*********************************************************************
** Function: Creature::die_roll(int, int)
** Description: Standard function for all creatures to roll the die
**				for either offense or defense 
** Parameters:	dieNum			The number of die for the roll
**				dieSides		The number of sides for the die
** Pre-Conditions: N/A
** Post-Conditions: Returns an int for the offensive or defensive roll
**					of the dice.
*********************************************************************/
int Creature::die_roll(int dieNum, int dieSides)
{
	int dieSum = 0;

	// Step through a loop for the number of dice
	for (int i = 0; i < dieNum; i++)
	{
		// Randomly generate a number based on the dice sides
		// and add it to the sum
		dieSum = dieSum + rand() % dieSides + 1;
	}
	return dieSum;
}

/*********************************************************************
** Function: Creature::defeated()
** Description: Standard function for all creatures to determine if
**				the Creature has been defeated
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns a boolean value based on the strength left
**					for the creature
*********************************************************************/
bool Creature::defeated()
{
	return strength <=0;
}

/*********************************************************************
** Function:		Creature::~Creature()
** Description:		Creature Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Creature::~Creature()
{
	delete uBelt;
}
