/*************************************************************************************
** Program name: combatGame.cpp is the Fantasy Combat Game implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Main program allows the user to select a menu option to pit two Creatures against
** eachother in a combat simulator. The user can select any two Creatures for the a 
** single match. There is also an option to run the Test Harness where every combination
** of Creature matches is tested.
***************************************************************************************/
#include "userMenu.hpp"

#include "Creature.hpp"
#include "Batman.hpp"
#include "Riddler.hpp"
#include "PoisonIvy.hpp"
#include "Scarecrow.hpp"
#include "LeagueOfShadows.hpp"
#include "RasAlGhul.hpp"

#include "Space.hpp"
#include "BatCave.hpp"
#include "IvyLair.hpp"
#include "Warehouse.hpp"
#include "ArkhamAsylum.hpp"
#include "WayneManner.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>

void playGame();
void resetDisplay(Creature* batman, int moves);

int main()
{
	// Seed the random number generator
	std::srand(static_cast<unsigned int>(time(0)));

	std::string image = "";
	std::string fileName = "intro_Batman.txt";

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

	std::cout << "BAM, POW, CRACK!\n";
	std::cout << "Batman wakes up from a crazy dream where he was the star of a 60's sitcom. For some reason he had\n";
	std::cout << "a mask with painted on eyebrows and cloth ears. And Holy Annoying Sidekick, Batman would never be\n";
	std::cout << "seen with that Robin character.\n ";
	std::cout << "Batman looks down at the bat counsel in his bat cave and sees the bat alarm. Selina Kyle has been\n";
	std::cout << "taken by Ra's Al Ghul."
	std::cout << "\nYou start your adventure in the Batcave. Alfred has poured you a nice cup of bat coffee\n\n";
	playGame();

	return 0;
}

void playGame() {
	char menuOpt;
//	int batCaveChoice = 0;
//	int mainMenu = 0;
	int batMoves = 100;
	bool defeated = false;
	Space* currentSpace = NULL;
	Space* batCave = NULL;
	Space* wayneManner = NULL;
	Space* arkhamAsylum = NULL;
	Space* ivyLair = NULL;
	Space* warehouse = NULL;
	Space* wayneEnterprise = NULL;

	Creature* poisonIvy = new PoisonIvy(75,15);
	Creature* batman = new Batman(100,20);
	Creature* league = new LeagueOfShadows(100,10);
	Creature* alGhul = new RasAlGhul(100, 20);
	Creature* riddler = new Riddler(100, 20);
	Creature* scarecrow = new Scarecrow(100, 20);

	batCave = new BatCave("BATCAVE", batman, batman);
	ivyLair = new IvyLair("IVY LAIR", batman, poisonIvy);
	warehouse = new Warehouse("WAREHOUSE", batman, riddler);
	arkhamAsylum = new ArkhamAsylum("ARKHAM ASYLUM", batman, scarecrow);
	wayneManner = new WayneManner("WAYNE MANNER", batman, league);
	wayneEnterprise = new Warehouse("WAYNE INC", batman, alGhul);

	riddler->add_inventory("Inoculation", "Immunizes against all types of plant type manipulations",1,true);
	riddler->add_inventory("Antidote", "In the off chance you are sprayed with a fearful toxin", 1, false);
	poisonIvy->add_inventory("ReGen Potion", "A mix of plant goodness to regain strength", 3, false);
	poisonIvy->add_inventory("Plant toxin", "An odorless toxin used to reduce opponent's strength", 1, true);
	scarecrow->add_inventory("Fear Gas", "A potent toxin capable of instilling fear in the strongest of foes", 1, true);
	scarecrow->add_inventory("Batarang", "Send it out and it comes back. Can retrieve items from small spaces.", 1, true);
	league->add_inventory("Lazarus Pit Water", "Used to resurrect those who are mostly dead", 1, false);
	league->add_inventory("Map to Ghul", "Specific location of Ra's Al Ghul", 1, true);

	// REMOVE when Riddler implemented
//	batman->add_inventory("Antidote", "In the off chance you are sprayed with a toxin", 1, true);

	batCave->setAdjSpace(ivyLair, 'D');
	batCave->setAdjSpace(warehouse, 'L');
	batCave->setAdjSpace(arkhamAsylum, 'R');
	batCave->setAdjSpace(wayneManner, 'U');

	ivyLair->setAdjSpace(batCave, 'U');
	warehouse->setAdjSpace(batCave, 'R');
	arkhamAsylum->setAdjSpace(batCave, 'L');
	wayneManner->setAdjSpace(batCave, 'D');
	wayneManner->setAdjSpace(wayneEnterprise, 'U');
	wayneEnterprise->setAdjSpace(wayneManner, 'D');

	currentSpace = batCave;

	do
	{
		currentSpace->displaySpaceInfo();
		resetDisplay(batman,batMoves);
		menuOpt = currentSpace->spaceMenu();

		if (menuOpt == 'U') {
			if (currentSpace->getSpaceName() == "WAYNE MANNER" && !batman->search_items("Map to Ghul")) {
				std::cout << "\nWithout the map to Ra's Al Ghul's location, there is no point in heading to Wayne Enterprises.\n";
				batCave->pause();
			}
			else {
				currentSpace = currentSpace->moveSpace('U');
				batMoves--;
			}
		}
		else if (menuOpt == 'R') {
			currentSpace = currentSpace->moveSpace('R');
			batMoves--;
		}
		else if (menuOpt == 'D') {
			currentSpace = currentSpace->moveSpace('D');
			batMoves--;
		}
		else if (menuOpt == 'L') {
			currentSpace = currentSpace->moveSpace('L');
			batMoves--;
		}
		else if (menuOpt == 'K' || menuOpt == 'G' || menuOpt == 'T' || menuOpt == 'S' || menuOpt == 'F')
			batMoves--;
		else if (menuOpt == 'A') {
			std::cout << "\nAdding Grapple Gun to the Utility Belt\n";
			batman->add_inventory("Grapple Gun", "For hard to reach places. Can also be used to suspend things.", 1, true);
		}
		else if (menuOpt == 'I'){
			batman->remove_inventory();
			batCave->pause();
		}

		if (batman->defeated()) {
			defeated = batman->defeated();
			std::cout << "Batman cannot be defeated but somehow his life has expired\n";
		}
		
	} while (menuOpt != 'Q' && !defeated);

	batCave->pause();

	delete poisonIvy;
	delete batman;
	delete league;
	delete alGhul;
	delete riddler;
	delete scarecrow;

	delete batCave;
	delete wayneManner;
	delete arkhamAsylum;
	delete ivyLair;
	delete warehouse;
	delete wayneEnterprise;

	return;
}

void resetDisplay(Creature* batman, int moves)
{
	// Clear the console on Linux
	std::cout << "\033[2J\033[1;1H";

	// Display Health and Inventory
	std::cout << "Strength: " << batman->get_strength() << std::endl;
	std::cout << "Moves Left: " << moves << std::endl;
	std::cout << "Belt Items: ";
	batman->get_itemName();
	std::cout << "\n";
}


/*********************************************************************
** Function: playRound(Creature*, Creature*, int, bool)
** Description: Plays a single match between two creatures and prints
**				the result of each round
** Parameters:	pOffense		Current Creature attacking
				pDefense		Current Creature defending
				round			Pass in initialized round for 
								recursive loop
				pStart			bool to determine which random player
								was selected to start the game
** Pre-Conditions: N/A
** Post-Conditions: The match plays out between two creatures with
**					the output of each round displayed to the prompt
*********************************************************************/
/*
void playRound(Creature * pOffense, Creature * pDefense, int round, bool pStart)
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

		// Check if Medusa used GLARE in the attack
		if (pOffense->get_special() == "GLARE") {
			// Set Medusa's attack strength equal to the remaining strength of defender plus total defense
			offenseRoll = 100;
//			defenseRoll = pDefense->defense(offenseRoll);
		}

		// Roll die for the defense
		defenseRoll = pDefense->defense(offenseRoll);

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
			std::cout << std::setw(5) << pDef + "-" << std::setw(5) << defenseRoll;
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
			std::cout << std::setw(5) << pDef + "-" << std::setw(5) << defenseRoll;
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
*/

/*********************************************************************
** Function: printRound(Creature*, Creature*)
** Description: Base level function to encompass all of the printed
**				text and round status
** Parameters:	O1		Player 1 selected Creature
				O2		Player 2 selected Creature
** Pre-Conditions: N/A
** Post-Conditions: The match plays out between two creatures with
**					the output of each match displayed to the prompt
*********************************************************************/
/*
void printRound(Creature * O1, Creature * O2)
{
	std::string p1Round;
	std::string p2Round;
//	int O1Wins = 0;
//	int O2Wins = 0;
	int round = 1;
	bool pStart;

	// See which player gets to start.
	pStart = (rand() % 2);

	// Set up the string with the name of the Creature and its starting strength
	p1Round = O1->get_name() + " (STR: " + std::to_string(O1->get_strength()) + ")";
	p2Round = O2->get_name() + " (STR: " + std::to_string(O2->get_strength()) + ")";

	// If player 1 gets to start
	if (!pStart) {
		std::cout << "Player 1 (O1) Will Start the Combat Game\n";
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
	}
	// If player 2 gets to start
	else if (pStart) {
		std::cout << "Player 2 (O2) Will Start the Combat Game\n";
		std::cout << std::string(95, '-') << std::endl;

		// Set the format of the output
		std::cout << std::left << std::setw(10) << "Roll #";
		std::cout << std::setw(5) << "O2: " << std::setw(28) << p2Round;
		std::cout << std::setw(8) << "|  O1: " << std::setw(25) << p1Round;
		std::cout << std::setw(10) << "Damage" << std::setw(10) << "Strength" << std::endl;

		// Play the match for the two Creatures
		playRound(O2, O1, round, pStart);

		// Print out the final strengths of the two Creatures
		std::cout << std::string(95, '-') << std::endl;
		std::cout << std::setw(10) << "" << std::setw(20) << "O2 Final Strength Pts: " << std::setw(10) << O2->get_strength();
		std::cout << std::setw(20) << "|  O1 Final Strength Pts: " << std::setw(10) << O1->get_strength() << std::endl << std::endl;
	}

	// Print out who wins the match
	std::cout << std::string(95, '=') << std::endl;
	if (O1->defeated()) {
		std::cout << "Player2's " << O2->get_name() << " is the winner!\n\n";
	}
	else if (O2->defeated()) {
		std::cout << "Player1's " << O1->get_name() << " is the winner!\n\n";
	}
}
*/
