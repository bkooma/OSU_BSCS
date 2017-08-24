/*************************************************************************************
** RasAlGhul.cpp is the RasAlGhul sub-class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The RasAlGhul class represents a Creature derived class. It inherits the variables
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack, defense and recover_strength. It overrides the 
** defense function to incorporate the additional special attack ability.
***************************************************************************************/

#include "RasAlGhul.hpp"

/*********************************************************************
** Function: RasAlGhul::RasAlGhul(int, int)
** Description: Default constructor for RasAlGhul. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: RasAlGhul members set to specific values.
*********************************************************************/
RasAlGhul::RasAlGhul(int strngth, int arm) : Creature(strngth, arm){
	ghulLives = 1;
	name = "Ra's Al Ghul";
	creatureInfo = "\nHis name is Arabic for Head of the Demon. He has dedicated his life\n"
		"to keeping order and justice in a world which he views as decadent and corrupt.\n"
		"Hint: If you have made it this far, you should have the items needed to prevail.\n";
	dieNumAttack = 5;
	dieNumDefense = 1;
	dieSidesAttack = dieSidesDefense = 9;
	specialAttack = "";
}

/*********************************************************************
** Function: RasAlGhul::pain(int, int)
** Description: Defense roll of the dice for the RasAlGhul. Passes
**				the defense die to the die_roll function to get the
**				defense value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int RasAlGhul::pain(int attack, int defense)
{
	// Calls the base class function to determine damage
	int damage = Creature::pain(attack, defense);

	// If RasAlGhul is killed and still has another life
	if (this->ghulLives > 0 && this->defeated()) {
		// Restore his strength to 30
		strength = 30;
		// set the special attack
		this->specialAttack = "LAZARUS";
		// Remove a life from RasAlGhul
		this->ghulLives--;
	}
	return damage;
}

/*********************************************************************
** Function: RasAlGhul::recover_strength()
** Description: Revive Ra's Al Ghul one time with Lazarus Water
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores RasAlGhul to full strength
*********************************************************************/
void RasAlGhul::recover_strength()
{
	strength = 10;
	// Reset Ra's lives
	this->ghulLives = 1;
}

RasAlGhul::~RasAlGhul() {
	// TODO Auto-generated destructor stub
}

