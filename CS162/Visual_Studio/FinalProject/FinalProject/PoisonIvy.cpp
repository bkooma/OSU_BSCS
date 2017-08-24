/*************************************************************************************
** PoisonIvy.cpp is the PoisonIvy sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The PoisonIvy class represents a Creature derived class. It inherits the variables
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack, defense and recover_strength. PoisonIvy also has the 
** ability to Seduce an opponent and remove all their strength in one hit
***************************************************************************************/

#include "PoisonIvy.hpp"

/*********************************************************************
** Function: PoisonIvy::PoisonIvy()
** Description: Default constructor for PoisonIvy. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: PoisonIvy members set to specific values.
*********************************************************************/
PoisonIvy::PoisonIvy(int strngth, int arm) : Creature(strngth, arm) {
	name = "Poison Ivy";
	creatureInfo = "\nA devilishly beautiful woman who has developed plant - like superpowers.\n"
		"She produces pheromones that make people susceptible to mind control around her,\n"
		"especially men. But you of course are Batman so she should have no affect on you, right?\n";
	dieNumAttack = 4;
	dieNumDefense = 1;
	dieSidesAttack = 9;
	dieSidesDefense = 6;
}

/*********************************************************************
** Function: PoisonIvy::attack()
** Description: Attack roll of the dice for PoisonIvy. Passes the
**				attack die to the die_roll function to get the attack
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int PoisonIvy::attack()
{
	// Reset the special attack to nothing
	this->specialAttack = "";

	// Call the die_roll function for attack die
	int dieSum = die_roll(this->dieNumAttack, this->dieSidesAttack);

	// If Poison Ivy's attack is > 25, she uses Seduce
	if (dieSum > 25){
		this->specialAttack = "SEDUCE";
	}
	return dieSum;
}

/*********************************************************************
** Function: PoisonIvy::pain(int, int)
** Description: Defense roll of the dice for the PoisonIvy. Passes
**				the defense die to the die_roll function to get the
**				defense value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int PoisonIvy::pain(int attack, int defense)
{
	// Reset the special attack
	this->specialAttack = "";
	// Calls the base class function to determine damage
	return Creature::pain(attack,defense);
}

/*********************************************************************
** Function: PoisonIvy::recover_strength()
** Description: Revive PoisonIvy after the round is over
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores the PoisonIvy to full strength
*********************************************************************/
void PoisonIvy::recover_strength()
{
	strength = 8;
}

/*********************************************************************
** Function:		PoisonIvy::~PoisonIvy()
** Description:		PoisonIvy Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
PoisonIvy::~PoisonIvy() {}

