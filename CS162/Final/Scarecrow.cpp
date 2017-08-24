/*************************************************************************************
** Scarecrow.cpp is the Scarecrow sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Scarecrow class represents a Creature derived class. It inherits the variables 
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack, defense and recover_strength. It overrides the 
** defense function to incorporate the additional special attack ability.
***************************************************************************************/
#include "Scarecrow.hpp"
#include <ctime>

/*********************************************************************
** Function: Scarecrow::Scarecrow()
** Description: Default constructor for Scarecrow. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Scarecrow members set to specific values.
*********************************************************************/
Scarecrow::Scarecrow(int strngth, int arm) : Creature(strngth, arm)
{
	name = "Scarecrow";
	creatureInfo = "\nScarecrow is an overly-obsessive and deranged ex-professor of psychology.\n"
		"He uses a variety of drugs to prey on the fears and phobias of others.\n"
		"But you of course are Batman so fear drugs should have no affect on you, right?\n";
	dieNumAttack = 1;
	dieSidesAttack = 12;
	specialAttack = "";
	dieNumDefense = 1;
	dieSidesDefense = 6;
}

/*********************************************************************
** Function: Scarecrow::attack()
** Description: Attack roll of the dice for the Scarecrow. Passes the
**				attack die to the die_roll function to get the attack 
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Scarecrow::attack()
{
	// Reset the special attack to nothing
	this->specialAttack = "";

	// Call the die_roll function for attack die
	return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

/*********************************************************************
** Function: Scarecrow::pain()
** Description: Defense roll of the dice for the Scarecrow. Passes the
**				defense die to the die_roll function to get the 
**				defense value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Scarecrow::pain(int attack, int defense)
{	
	// Reset special attack to nothing
	this->specialAttack = "";

	// Randomly select a number from 1-100
//	int Charm = rand() % 100 + 1;

	// If number is greater than 50
	if ((rand() % 2) > 0)
	{
		// Scarecrow uses the Charm defense 
		this->specialAttack = "FEARGAS";
		return 0;
	}
	return Creature::pain(attack, defense);
}

/*********************************************************************
** Function: Scarecrow::recover_strength()
** Description: Revive the Scarecrow after the round is over
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores the Scarecrow to full strength
*********************************************************************/
void Scarecrow::recover_strength()
{
	strength = 18;
}

/*********************************************************************
** Function:		Scarecrow::~Scarecrow()
** Description:		Scarecrow Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Scarecrow::~Scarecrow(){}
