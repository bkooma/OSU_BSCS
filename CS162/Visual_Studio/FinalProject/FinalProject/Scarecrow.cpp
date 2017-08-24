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
** Function: Scarecrow::Scarecrow(int, int)
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
	dieNumAttack = 4;
	dieSidesAttack = 9;
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
	int dieSum = die_roll(this->dieNumAttack, this->dieSidesAttack);

	// If Scarecrow's attack is 12, he uses Fear Gas
	if (dieSum > 27) {
		this->specialAttack = "FEAR GAS";
	}
	return dieSum;
}

/*********************************************************************
** Function: Scarecrow::pain(int, int)
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
	// Calls the base class function to determine damage
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
	strength = 65;
}

/*********************************************************************
** Function:		Scarecrow::~Scarecrow()
** Description:		Scarecrow Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Scarecrow::~Scarecrow(){}
