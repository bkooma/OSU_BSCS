/*************************************************************************************
** Batman.cpp is the Batman derived class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Batman class represents a Creature derived class. It inherits the variables
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack, defense and recover_strength.
***************************************************************************************/

#include "Batman.hpp"

/*********************************************************************
** Function: Batman::Batman()
** Description: Default constructor for Batman. Sets all protected
**				members to specific values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Batman members set to specific values.
*********************************************************************/
Batman::Batman(int strngth, int arm) : Creature(strngth,arm) {
	name = "Batman";
	creatureInfo = "\nI AM BATMAN! A dark and brooding soul. Your loss of your parents\n"
		"has scarred you. You have taken to a Dark Night's purpose and\n"
		"attempt to clean Gotham's streets of the type of scum that killed\n"
		"your family.\n"
		"Cleaning the streets of Gotham will require more than an empty Utility Belt\n";
	dieNumAttack = 4;
	dieSidesAttack = 10;
	dieNumDefense = 2;
	dieSidesDefense = 6;
	specialAttack = "";
}

/*********************************************************************
** Function: Batman::attack()
** Description: Attack roll of the dice for Batman. Passes the
**				attack die to the die_roll function to get the attack
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Batman::attack()
{
	// Reset the special attack to nothing
	this->specialAttack = "";

	// Call the die_roll function for attack die
	int dieSum = die_roll(this->dieNumAttack, this->dieSidesAttack);

	// If Batman's attack is > 29, he uses SMOKE
	if (dieSum > 29 && dieSum <= 35 && this->search_items("Grapple Gun")) {
		this->specialAttack = "SMOKE";
	}
	// Else if Batman's attack is > 35, he uses FINISHING BLOW
	else if (dieSum > 35 && this->search_items("Plant toxin"))
		this->specialAttack = "FINISHING BLOW";
	return dieSum;
}

/*********************************************************************
** Function: Batman::defense()
** Description: Defense roll of the dice for the Batman. Passes the
**				defense die to the die_roll function to get the defense
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Batman::defense(){

	this->specialAttack = "";
	// Call the die_roll function for defense die
	defPoints = die_roll(this->dieNumDefense, this->dieSidesDefense);
	return defPoints;
}

/*********************************************************************
** Function: Batman::pain(int, int)
** Description: Defense roll of the dice for the Pain. Passes
**				the defense die to the die_roll function to get the
**				defense value.
** Parameters:	attack		Attack roll
**				defense		Defense roll
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int Batman::pain(int attack, int defense)
{
	this->specialAttack = "";
	// Checks to see if Batman has Antidote and not Inoculation and if Scarecrow is attacking
	if (this->search_items("Antidote") && !this->search_items("Inoculation") && attack == 150) {
		// Batman is Immune from the Fear Gas
		this->specialAttack = "Immune";
		return 0;
	}
	// Checks to see if Batman has Inoculation and not Antidote and if Ivy is attacking
	else if (this->search_items("Inoculation") && !this->search_items("Antidote") && attack == 75) {
		// Batman is Immune from the SEDUCE
		this->specialAttack = "Immune";
		return 0;
	}
	// Checks to see if Batman has both Inoculation and Antidote
	else if (this->search_items("Inoculation") && this->search_items("Antidote") && attack >=75) {
		this->specialAttack = "Immune";
		return 0;
	}
	// Calls the base class function to determine damage
	int damage = Creature::pain(attack, defense);

	// If Batman has the Lazarus Water, he regains his life
	if (this->defeated() && this->search_items("Lazarus Pit Water")) {
		this->strength = 100;
		this->specialAttack = "LAZARUS";
		uBelt->removeQty("Lazarus Pit Water");
	}
	return damage;
}

/*********************************************************************
** Function: Batman::recover_strength()
** Description: Batman can use a ReGen potion to recover strength
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Restores 25 strength to Batman
*********************************************************************/
void Batman::recover_strength(){
	// If Batman chooses to use a ReGen potion to refill his strength
	uBelt->removeQty("ReGen Potion");
	if (strength < 75) {
		strength += 25;
	}
	else
		strength = 100;
}

/*********************************************************************
** Function: Batman::endScreen(bool)
** Description: Prints the final screen after Batman's fight with Ra's
** Parameters:	batDead		Is Batman dead
** Pre-Conditions: N/A
** Post-Conditions: Prints the appropriate screen based on win vs loss.
*********************************************************************/
void Batman::endScreen(bool batDead)
{
	std::string image = "";
	std::string endBanner = "";
	std::string fileName;

	// If Batman is dead, print the loser screen
	if (batDead) {
		fileName = "lose_Batman.txt";
		endBanner = "\nYou were unable to save Catwo... er I mean Selina in time.\n"
			"So much for the BatCat relationship. Guess you better go track down Vicki Vale.\n";
	}
	// Else he has Won!
	else {
		fileName = "won_Batman.txt";
		endBanner = "\nCatwoma... er I mean Selina Kyle is saved just in time.\n\n"
			"Batman was able to defeat Ra's Al Ghul and the League of Shadows on the way.\n\n"
			"Selina is greatful for the help but tells you she could have saved herself.\n"
			"She leans in and asks if you can meet up in a dark alley sometime. It's a date!\n\n"
			"Better go ask that Bruce Wayne guy if he can loan you some cash.\n\n";
	}

	// Print the ASCII txt file
	std::ifstream inFile;
	inFile.open(fileName.c_str());

	if (inFile)
	{
		while (inFile)
		{
			std::string tmpLine;
			std::getline(inFile, tmpLine);
			tmpLine += "\n";
			image += tmpLine;
		}
		std::cout << image << std::endl;
		inFile.close();
	}
	else
		std::cout << "Error opening image file\n" << std::endl;

	std::cout << endBanner;
}

/*********************************************************************
** Function:		Batman::~Batman()
** Description:		Batman Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Batman::~Batman() {}

