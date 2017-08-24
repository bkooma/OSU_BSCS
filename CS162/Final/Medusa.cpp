/*************************************************************************************
** Medusa.cpp is the Medusa sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Medusa class represents a Creature derived class. It inherits the variables
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack_roll, defense_roll and recover_strength. Medusa also has the ability
** to Glare an opponent and remove all their strength in one hit
***************************************************************************************/

#include "Medusa.hpp"

/*********************************************************************
** Function: Medusa::Medusa()
** Description: Default constructor for Medusa. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Medusa members set to specific values.
*********************************************************************/
Medusa::Medusa() {
	armor = 3;
	strength = 8;
	name = "Medusa";
	dieNumAttack = 2;
	dieNumDefense = 1;
	dieSidesAttack = dieSidesDefense = 6;
}

/*********************************************************************
** Function: Medusa::attack_roll()
** Description: Attack roll of the dice for Medusa. Passes the
**				attack die to the die_roll function to get the attack
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Medusa::attack_roll()
{
	// Reset the special attack to nothing
	this->specialAttack = "";

	// Call the die_roll function for attack die
	int dieSum = die_roll(this->dieNumAttack, this->dieSidesAttack);

	// If Medusa's attack is 12, she uses Glare
	if (dieSum == 12){
		this->specialAttack = "GLARE";
	}
	return dieSum;
}

/*********************************************************************
** Function: Medusa::defense_roll()
** Description: Defense roll of the dice for the Medusa. Passes
**				the defense die to the die_roll function to get the
**				defense value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Medusa::defense_roll(int attack)
{
	// Reset the special attack
	this->specialAttack = "";
	// Calls the base class function to determine damage
	return Creature::defense_roll(attack);
}

/*********************************************************************
** Function: Medusa::recover_strength()
** Description: Revive Medusa after the round is over
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores the Medusa to full strength
*********************************************************************/
void Medusa::recover_strength()
{
	strength = 8;
}

/*********************************************************************
** Function:		Medusa::~Medusa()
** Description:		Medusa Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Medusa::~Medusa() {}

