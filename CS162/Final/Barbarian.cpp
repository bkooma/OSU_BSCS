/*************************************************************************************
** Barbarian.cpp is the Barbarian sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Barbarian class represents a Creature derived class. It inherits the variables
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack_roll and recover_strength. 
***************************************************************************************/

#include "Barbarian.hpp"

/*********************************************************************
** Function: Barbarian::Barbarian()
** Description: Default constructor for Barbarian. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Barbarian members set to specific values.
*********************************************************************/
Barbarian::Barbarian() {
	armor = 0;
	strength = 12;
	name = "Barbarian";
	dieNumAttack = 2;
	dieSidesAttack = 6;
	dieNumDefense = 2;
	dieSidesDefense = 6;
	this->specialAttack = "";
}

/*********************************************************************
** Function: Barbarian::attack_roll()
** Description: Attack roll of the dice for the Barbarian. Passes the
**				attack die to the die_roll function to get the attack
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Barbarian::attack_roll(){
	// Call the die_roll function for attack die
	return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

/*********************************************************************
** Function: Barbarian::recover_strength()
** Description: Revive the Barbarian after the round is over
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores the Barbarian to full strength
*********************************************************************/
void Barbarian::recover_strength(){
	strength = 12;
}

/*********************************************************************
** Function:		Barbarian::~Barbarian()
** Description:		Barbarian Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Barbarian::~Barbarian() {}

