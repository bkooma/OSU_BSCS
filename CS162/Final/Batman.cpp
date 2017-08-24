/*************************************************************************************
** Batman.cpp is the Batman sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Batman class represents a Creature derived class. It inherits the variables
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack, defense and recover_strength.
***************************************************************************************/

#include "Batman.hpp"

/*********************************************************************
** Function: Batman::Batman()
** Description: Default constructor for Batman. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Batman members set to specific values.
*********************************************************************/
Batman::Batman(int strngth, int arm) : Creature(strngth,arm) {
	name = "Batman";
	creatureInfo = "\nI AM BATMAN! A dark and brooding soul. Your loss of your parents\n"
		"has scarred you. You have taken to a Dark Night's purpose and\n"
		"attempt to clean Gotham's streets of the type of scum that killed\n"
		"your family.\n"
		"Cleaning the streets of Gotham will require more than an empty Utility Belt\n";
	dieNumAttack = 4;
	dieSidesAttack = 10;
	dieSidesDefense = 6;
	specialAttack = "";
}

/*********************************************************************
** Function: Batman::defense()
** Description: Defense roll of the dice for the Batman. Passes the
**				defense die to the die_roll function to get the defense
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Batman::defense(){

	this->specialAttack = "";
	// Call the die_roll function for defense die
	defPoints = die_roll(this->dieNumDefense, this->dieSidesDefense);
	return defPoints;
}

/*********************************************************************
** Function: Batman::pain()
** Description: Defense roll of the dice for the Pain. Passes
**				the defense die to the die_roll function to get the
**				defense value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Batman::pain(int attack, int defense)
{
	this->specialAttack = "";
	if (this->search_items("Inoculation") && attack > 100) {
		this->specialAttack = "Immune";
		return 0;
	}
	// Calls the base class function to determine damage
	return Creature::pain(attack, defense);
}

/*********************************************************************
** Function: Batman::recover_strength()
** Description: Revive the Batman after the round is over
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores the Batman to full strength
*********************************************************************/
void Batman::recover_strength(){
	uBelt->removeQty("ReGen Potion");
	if (strength < 75) {
		strength += 25;
	}
	else
		strength = 100;
}

/*********************************************************************
** Function:		Batman::~Batman()
** Description:		Batman Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Batman::~Batman() {}

