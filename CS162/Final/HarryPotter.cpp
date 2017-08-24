/*************************************************************************************
** HarryPotter.cpp is the HarryPotter sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The HarryPotter class represents a Creature derived class. It inherits the variables
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack_roll, defense_roll and recover_strength. It overrides the 
** defense_roll function to incorporate the addtional special attack ability.
***************************************************************************************/

#include "HarryPotter.hpp"

/*********************************************************************
** Function: HarryPotter::HarryPotter()
** Description: Default constructor for HarryPotter. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: HarryPotter members set to specific values.
*********************************************************************/
HarryPotter::HarryPotter() {
	armor = 0;
	strength = 10;
	harryLives = 1;
	name = "Harry Potter";
	dieNumAttack = dieNumDefense = 2;
	dieSidesAttack = dieSidesDefense = 6;
	specialAttack = "";
}

/*********************************************************************
** Function: HarryPotter::attack_roll()
** Description: Attack roll of the dice for HarryPotter. Passes the
**				attack die to the die_roll function to get the attack
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int HarryPotter::attack_roll()
{
	// Reset the special attack to nothing
	this->specialAttack = "";

	// Call the die_roll function for attack die
	return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

/*********************************************************************
** Function: HarryPotter::defense_roll()
** Description: Defense roll of the dice for the HarryPotter. Passes 
**				the defense die to the die_roll function to get the
**				defense value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int HarryPotter::defense_roll(int attack)
{
	// Calls the base class function to determine damage
	int damage = Creature::defense_roll(attack);

	// If HarryPotter is killed and still has another life
	if (this->harryLives > 0 && this->defeated()) {
		// Restore his strength to 20
		strength = 20;
		// set the special attack
		this->specialAttack = "HOGWARTS";
		// Remove a life from Harry Potter
		this->harryLives--;
	}
	return damage;
}

/*********************************************************************
** Function: HarryPotter::recover_strength()
** Description: Revive Harry Potter to initial strength after the 
**				round is over
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores HarryPotter to full strength
*********************************************************************/
void HarryPotter::recover_strength()
{
	strength = 10;
	// Reset Harry's lives
	this->harryLives = 1;
}

HarryPotter::~HarryPotter() {
	// TODO Auto-generated destructor stub
}

