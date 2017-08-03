/*************************************************************************************
** Vampire.cpp is the Vampire sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Vampire class represents a Creature derived class. It inherits the variables 
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack_roll, defense_roll and recover_strength. It overrides the 
** inflict_pain function to incorporate the addtional special attack ability.
***************************************************************************************/
#include "Vampire.hpp"

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
int Vampire::defense_roll()
{
	// Reset special attack to nothing
	this->specialAttack = "";
	// Call the die_roll function for defense die
	int dieSum = die_roll(this->dieNumDefense, this->dieSidesDefense);

	// Randomly select a number from 1-100
	int Charm = rand() % 100 + 1;

	// If number is greater than 50
	if (Charm > 50)
	{
		// Vampire uses the Charm defense 
		this->specialAttack = "CHARM";
	}
	return dieSum;
}

/*********************************************************************
** Function: Vampire::inflict_pain(int, int)
** Description: Override the function to determine if the Vampire 
**				uses the Charm defense.
** Parameters:	attack			The value of the attack die roll
**				defense			The value of the defense die roll
** Pre-Conditions: N/A
** Post-Conditions: Returns an int for the damage inflicted
*********************************************************************/
int Vampire::inflict_pain(int attack, int defense)
{
	if (this->specialAttack == "CHARM")
	{
		// No damage is taken
		return 0;
	}
	// Calls the base class function if no Charm was used
	return Creature::inflict_pain(attack, defense);
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
