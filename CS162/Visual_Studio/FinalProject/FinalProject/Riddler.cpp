/*************************************************************************************
** Riddler.cpp is the Riddler sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Riddler class represents a Creature derived class. It inherits the variables 
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack, defense and recover_strength.
***************************************************************************************/
#include "Riddler.hpp"
#include <ctime>

/*********************************************************************
** Function: Riddler::Riddler()
** Description: Default constructor for Riddler. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Riddler members set to specific values.
*********************************************************************/
Riddler::Riddler(int strngth, int arm) : Creature(strngth,arm)
{
	name = "Riddler";
	creatureInfo = "\nA criminal mastermind, the Riddler delights in incorporating riddles\n"
		"and puzzles into his plots, leaving clues for Batman to solve.\n"
		"Cleaning the streets of Gotham will require more than an empty Utility Belt\n";
	dieNumAttack = 4;
	dieSidesAttack = 7;
	specialAttack = "";
	dieNumDefense = 1;
	dieSidesDefense = 6;
}

/*********************************************************************
** Function: Riddler::attack()
** Description: Attack roll of the dice for the Riddler. Passes the
**				attack die to the die_roll function to get the attack 
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Riddler::attack()
{
	// Reset the special attack to nothing
	this->specialAttack = "";

	// Call the die_roll function for attack die
	return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

/*********************************************************************
** Function: Riddler::pain(int, int)
** Description: Defense roll of the dice for the Riddler. Passes the
**				defense die to the die_roll function to get the 
**				defense value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Riddler::pain(int attack, int defense)
{	
	// Reset special attack to nothing
	this->specialAttack = "";

	// If random number is 2 (1/3 chance)
	if ((rand() % 3) > 1)
	{
		// Riddler uses the Charm defense 
		this->specialAttack = "CHARM";
		return 0;
	}
	return Creature::pain(attack, defense);
}

/*********************************************************************
** Function: Riddler::recover_strength()
** Description: Revive the Riddler after the round is over
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores the Riddler to full strength
*********************************************************************/
void Riddler::recover_strength()
{
	strength = 75;
}

/*********************************************************************
** Function:		Riddler::~Riddler()
** Description:		Riddler Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Riddler::~Riddler(){}
