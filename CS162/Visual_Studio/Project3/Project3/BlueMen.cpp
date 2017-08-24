/*************************************************************************************
** BlueMen.cpp is the BlueMen sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The BlueMen class represents a Creature derived class. It inherits the variables
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack_roll, defense_roll and recover_strength.
***************************************************************************************/

#include "BlueMen.hpp"

/*********************************************************************
** Function: BlueMen::BlueMen()
** Description: Default constructor for BlueMen. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: BlueMen members set to specific values.
*********************************************************************/
BlueMen::BlueMen() {
	armor = 3;
	strength = 12;
	name = "Blue Men";
	dieNumAttack = 2;
	dieSidesAttack = 10;
	dieSidesDefense = 6;
	specialAttack = "";
}

/*********************************************************************
** Function: BlueMen::attack_roll()
** Description: Attack roll of the dice for the BlueMen. Passes the
**				attack die to the die_roll function to get the attack
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int BlueMen::attack_roll(){
	// Call the die_roll function for attack die
	return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

/*********************************************************************
** Function: BlueMen::defense_roll()
** Description: Defense roll of the dice for the BlueMen. Passes the
**				defense die to the die_roll function to get the defense
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int BlueMen::defense_roll(int attack){

	// For every 4 points of damage, BlueMen lose one defense die
	if (this->strength > 8)
		// Start out with 3 dice
		this->dieNumDefense = 3;
	else if (this->strength > 4)
		// Reduced to 2 dice
		this->dieNumDefense = 2;
	else if (this->strength > 0)
		// Only a single die left
		this->dieNumDefense = 1;

	return Creature::defense_roll(attack);
}

/*********************************************************************
** Function: BlueMen::recover_strength()
** Description: Revive the BlueMen after the round is over
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores the BlueMen to full strength
*********************************************************************/
void BlueMen::recover_strength(){
	strength = 12;
}

/*********************************************************************
** Function:		BlueMen::~BlueMen()
** Description:		BlueMen Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
BlueMen::~BlueMen() {}

