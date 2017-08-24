#include "LeagueOfShadows.hpp"

/*********************************************************************
** Function: Batman::Batman()
** Description: Default constructor for Batman. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Batman members set to specific values.
*********************************************************************/
LeagueOfShadows::LeagueOfShadows(int strngth, int arm) : Creature(strngth, arm) {
	name = "League of Shadows";
	creatureInfo = "\nA force that works in the Shadows to rid the world of injustice and \n"
		"corruption. Batman trained with the League of Shadows and made him the fighting \n"
		"force he is today.\n"
		"If Batman doesn't intimidate them, maybe something else will instill fear.\n";
	dieNumAttack = 4;
	dieSidesAttack = 8;
	dieSidesDefense = 6;
	specialAttack = "";
}

/*********************************************************************
** Function: LeagueOfShadows::defense(int)
** Description: Override function for all creatures to determine the
**				damage inflicted during a round
** Parameters:	attack			The value of the attack die roll
** Pre-Conditions: N/A
** Post-Conditions: Returns an int for the damage inflicted after.
**					Will return 0 if the damage is less than 0
*********************************************************************/
int LeagueOfShadows::defense()
{
	this->specialAttack = "";
	// For every 4 points of damage, the League loses one defense die
	if (this->strength > 75)
		// Start out with 3 dice
		this->dieNumDefense = 4;
	else if (this->strength > 50)
		// Reduced to 2 dice
		this->dieNumDefense = 3;
	else if (this->strength > 25)
		// Only a single die left
		this->dieNumDefense = 2;
	// Call the die_roll function for defense die
	defPoints = die_roll(this->dieNumDefense, this->dieSidesDefense);
	return defPoints;

}

/*********************************************************************
** Function: LeagueOfShadows::pain()
** Description: Defense roll of the dice for the LeagueOfShadows. 
**				Passes the defense die to the die_roll function to get
**				the defense value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int LeagueOfShadows::pain(int attack, int defense)
{
	return Creature::pain(attack,defense);
}

/*********************************************************************
** Function: Batman::recover_strength()
** Description: Revive the Batman after the round is over
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores the Batman to full strength
*********************************************************************/
void LeagueOfShadows::recover_strength() {
	strength = 12;
}

/*********************************************************************
** Function:		Batman::~Batman()
** Description:		Batman Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
LeagueOfShadows::~LeagueOfShadows()
{
}
