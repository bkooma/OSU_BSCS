/*************************************************************************************
** Vampire.cpp is the Vampire sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Vampire class represents a Creature derived class. It inherits the variables 
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack_roll, defense_roll and recover_strength. It overrides the 
** defense_roll function to incorporate the addtional special attack ability.
***************************************************************************************/
#include "Vampire.hpp"
#include <ctime>

/*********************************************************************
** Function: Vampire::Vampire()
** Description: Default constructor for Vampire. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Vampire members set to specific values.
*********************************************************************/
Vampire::Vampire()
{
	name = "Vampire";
	armor = 1;
	strength = 18;
	dieNumAttack = 1;
	dieSidesAttack = 12;
	specialAttack = "";
	dieNumDefense = 1;
	dieSidesDefense = 6;
}

/*********************************************************************
** Function: Vampire::attack_roll()
** Description: Attack roll of the dice for the Vampire. Passes the
**				attack die to the die_roll function to get the attack 
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Vampire::attack_roll()
{
	// Reset the special attack to nothing
	this->specialAttack = "";

	// Call the die_roll function for attack die
	return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

/*********************************************************************
** Function: Vampire::defense_roll()
** Description: Defense roll of the dice for the Vampire. Passes the
**				defense die to the die_roll function to get the 
**				defense value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Vampire::defense_roll(int attack)
{	
	// Reset special attack to nothing
	this->specialAttack = "";

	// Randomly select a number from 1-100
//	int Charm = rand() % 100 + 1;

	// If number is greater than 50
	if ((rand() % 2) > 0)
	{
		// Vampire uses the Charm defense 
		this->specialAttack = "CHARM";
		return 0;
	}
	return Creature::defense_roll(attack);
}

/*********************************************************************
** Function: Vampire::recover_strength()
** Description: Revive the Vampire after the round is over
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores the Vampire to full strength
*********************************************************************/
void Vampire::recover_strength()
{
	strength = 18;
}

/*********************************************************************
** Function:		Vampire::~Vampire()
** Description:		Vampire Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Vampire::~Vampire(){}
