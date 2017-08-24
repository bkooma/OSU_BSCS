/******************************************************************************
** Space.hpp is the Space Base class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Space class represents a Space Base Class for the batmanGame. This class
** is abstract with some pure virtual functions
******************************************************************************/

#include "Space.hpp"

/*********************************************************************
** Function: Space::Space(string, Creature, Creature)
** Description: Default constructor for Space. Sets all protected
**				members to default values.
** Parameters:	name		Name of the Space
**				batman		The Batman Creature
**				vil			The Villain Creature
** Pre-Conditions: N/A
** Post-Conditions: Space set to default
*********************************************************************/
Space::Space(std::string name, Creature* batman, Creature * vil)
{
	// Initialize the directional pointers
	this->up = NULL;
	this->right = NULL;
	this->down = NULL;
	this->left = NULL;
	// Set variables for use in the Class
	this->spaceName = name;
	this->Villain = vil;
	this->IamBat = batman;
}

/*********************************************************************
** Function: Space::displayVillainInfo()
** Description: Print function for returning the Villain information
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints the Villain name and info 
*********************************************************************/
void Space::displayVillainInfo()
{
	std::cout << "\n" << this->Villain->get_name() << ":";
	std::cout << this->Villain->get_creatureInfo() << std::endl;
}

/*********************************************************************
** Function:		Space::~Space()
** Description:		Space Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Space::~Space()
{

}

/*********************************************************************
** Function: Space::setAdjSpace(Space, char)
** Description: Default function for assigning the adjacent rooms to 
**				a passed in Space.
** Parameters:	room		Space that is adjacent to calling Space
**				roomDir		The Space location in relation to the
**							calling Space
** Pre-Conditions: N/A
** Post-Conditions: Adjacent Space pointer is assigned
*********************************************************************/
void Space::setAdjSpace(Space * room, char roomDir)
{
	if (roomDir == 'U')
		this->up = room;
	else if (roomDir == 'R')
		this->right = room;
	else if (roomDir == 'D')
		this->down = room;
	else if (roomDir == 'L')
		this->left = room;
}

/*********************************************************************
** Function: Space::moveSpace(char)
** Description: Default function for moving from current Space to 
**				adjacent Space.
** Parameters:	menuOpt		Direction to move to
** Pre-Conditions: N/A
** Post-Conditions: Returns the Space Batman has moved to
*********************************************************************/
Space * Space::moveSpace(char menuOpt)
{
	// Reset some Game Boolean values
	this->gasApplied = false;
	this->stunApplied = false;

	if (menuOpt == 'U')
		return up;
	else if (menuOpt == 'R')
		return right;
	else if (menuOpt == 'D')
		return down;
	else if (menuOpt == 'L')
		return left;
	else
		return NULL;
}

/*********************************************************************
** Function: Space::pause()
** Description: Default function for waiting on user to push Enter
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: The screen is paused until user pushes Enter
*********************************************************************/
void Space::pause()
{
	std::string tmpString;
	std::cout << "Press Enter to Continue" << std::endl;
	std::getline(std::cin, tmpString);
	std::cin.clear();
	std::cin.ignore();
	// This option does not work well in VS, but seems to work on Flip. Command window dependent
	std::cout << "\033[2J\033[1;1H";
}

/*********************************************************************
** Function: printRound(Creature*, Creature*)
** Description: Base level function to encompass all of the printed
**				text and round status
** Parameters:	O1		Player 1 selected Creature
**				O2		Player 2 selected Creature
** Pre-Conditions: N/A
** Post-Conditions: The match plays out between two creatures with
**					the output of each match displayed to the prompt
*********************************************************************/

void Space::printRound(Creature * O1, Creature * O2)
{
	std::string p1Round;
	std::string p2Round;
	int round = 1;
	bool pStart = false;

	// Set up the string with the name of the Creature and its starting strength
	p1Round = O1->get_name() + " (STR: " + std::to_string(O1->get_strength()) + ")";
	p2Round = O2->get_name() + " (STR: " + std::to_string(O2->get_strength()) + ")";

	// Batman gets to start
	std::cout << "Batman Will Start the Combat Game\n";
	std::cout << std::string(95, '-') << std::endl;

	// Set the format of the output
	std::cout << std::left << std::setw(10) << "Roll #";
	std::cout << std::setw(5) << "O1: " << std::setw(28) << p1Round;
	std::cout << std::setw(8) << "|  O2: " << std::setw(25) << p2Round;
	std::cout << std::setw(10) << "Damage" << std::setw(10) << "Strength" << std::endl;

	// Play the match for the two Creatures
	playRound(O1, O2, round, pStart);

	// Print out the final strengths of the two Creatures
	std::cout << std::string(95, '-') << std::endl;
	std::cout << std::setw(10) << "" << std::setw(20) << "O1 Final Strength Pts: " << std::setw(10) << O1->get_strength();
	std::cout << std::setw(20) << "|  O2 Final Strength Pts: " << std::setw(10) << O2->get_strength() << std::endl << std::endl;

	// Print out who wins the match
	std::cout << std::string(95, '=') << std::endl;
	if (O1->defeated()) {
		std::cout << O2->get_name() << " is the winner!\n\n";
	}
	else if (O2->defeated()) {
		std::cout << O1->get_name() << " is the winner!\n\n";
	}
}

/*********************************************************************
** Function: playRound(Creature*, Creature*, int, bool)
** Description: Plays a single match between two creatures and prints
**				the result of each round
** Parameters:	pOffense		Current Creature attacking
**				pDefense		Current Creature defending
**				round			Pass in initialized round for
**								recursive loop
**				pStart			bool to determine which player
**								was selected to start the game
** Pre-Conditions: N/A
** Post-Conditions: The match plays out between two creatures with
**					the output of each round displayed to the prompt
*********************************************************************/

void Space::playRound(Creature * pOffense, Creature * pDefense, int round, bool pStart)
{
	std::string p1Round;
	std::string p2Round;
	std::string pOff;
	std::string pDef;

	// Recursive function to continue attacks until one of the Creatures is defeated
	while (!pOffense->defeated() && !pDefense->defeated()) {
		int damage = 0;
		int defenseRoll;
		// Roll die for the attack
		int offenseRoll = pOffense->attack();

		// Check if Poison Ivy used SEDUCE in the attack
		if (pOffense->get_special() == "SEDUCE") {
			// Set Poison Ivy's attack strength at a reasonably high value
			offenseRoll = 75;
			//			defenseRoll = pDefense->defense(offenseRoll);
		}
		// Check if Scarecrow uses Fear Gas on Batman
		else if (pOffense->get_special() == "FEAR GAS") {
			// Set Scarecrows's attack strength at a reasonably high value
			offenseRoll = 150;
		}
		// Determine if Batman uses his Smoke attack
		else if (pOffense->get_special() == "SMOKE") {
			// Set Batman's attack strength at a reasonably high value
			offenseRoll = 50;
		}
		
		// Determine if Batman uses his Finishing Blow
		else if (pOffense->get_special() == "FINISHING BLOW") {
			// Set Batman's attack strength at a reasonably high value
			offenseRoll = 100;
		}
		
		// Check to see if Batman has stunned the Villain
		if (this->stunApplied && pDefense->get_name() != "Batman") {
			// Roll die for the defense
			defenseRoll = pDefense->defense()/2;
		}
		else
		{
			// Roll die for the defense
			defenseRoll = pDefense->defense();
		}
		
		// Calculate the total pain caused
		damage = pDefense->pain(offenseRoll, defenseRoll);

		// Set player strings based on who was randomly selected to start
		if (!pStart) {
			pOff = "O1: ";
			pDef = "O2: ";
		}
		else {
			pOff = "O2: ";
			pDef = "O1: ";
		}

		// For every odd round, set up the output statements
		if (round % 2 == 1) {
			p1Round = "Attack:  ";
			// Determine if any offensive specials were used and output to screen
			if (pOffense->get_special() != "") {
				p1Round = p1Round + "(" + pOffense->get_special() + ")";
			}
			// If no specials were used, print the strength of the offense roll
			else {
				p1Round = p1Round + std::to_string(offenseRoll);
			}

			p2Round = "|  Defense: ";
			// Determine if any defensive specials were used and output to screen
			if (pDefense->get_special() != "") {
				p2Round = p2Round + "(" + pDefense->get_special() + ")";
			}
			// If no specials were used, print the strength of the defensive roll + armor
			else {
				p2Round = p2Round + std::to_string(pDefense->get_defPoints()) + " + armor: " + std::to_string(pDefense->get_armor());
			}

			// Format the output for each round
			std::cout << std::setw(10) << round << std::setw(33) << p1Round << std::setw(33) << p2Round;
			std::cout << std::setw(5) << pDef + "-" << std::setw(5) << damage;
			std::cout << std::setw(5) << pDef << std::setw(5) << pDefense->get_strength() << std::endl;
		}

		// For every odd round, set up the output statements
		if (round % 2 == 0) {
			p1Round = "Defense:  ";
			// Determine if any defensive specials were used and output to screen
			if (pDefense->get_special() != "") {
				p1Round = p1Round + "(" + pDefense->get_special() + ")";
			}
			// If no specials were used, print the strength of the defensive roll + armor
			else {
				p1Round = p1Round + std::to_string(pDefense->get_defPoints()) + " + armor: " + std::to_string(pDefense->get_armor());
			}
			// Determine if any offensive specials were used and output to screen
			p2Round = "|  Attack: ";
			if (pOffense->get_special() != "") {
				p2Round = p2Round + "(" + pOffense->get_special() + ")";
			}
			// If no specials were used, print the strength of the offense roll
			else {
				p2Round = p2Round + std::to_string(offenseRoll);
			}

			// Format the output for each round
			std::cout << std::setw(10) << round << std::setw(33) << p1Round << std::setw(33) << p2Round;
			std::cout << std::setw(5) << pDef + "-" << std::setw(5) << damage;
			std::cout << std::setw(5) << pDef << std::setw(5) << pDefense->get_strength() << std::endl << std::endl;
		}
		// Increment the round counter
		round++;
		// Determine if the opponent is defeated
		if (!pDefense->defeated()) {
			// If not defeated set boolean to opposite player (p1 true or false)
			pStart = !pStart;
			// Recursive function call to pass the opposite players to the function
			playRound(pDefense, pOffense, round, pStart);
		}
	}
}