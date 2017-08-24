/*************************************************************************************
** Program name: batmanGame.cpp is the Main implementation file for the Batman program.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Main program allows the user to select a menu option to move through Spaces in
** a Batman type theme. Each of the Spaces are linked to other Spaces. Each Space also
** has a Creature assigned. Those Creatures are then assigned a Utility Belt which
** is a List which in turn has Items.
** Code for pausing and screen clearing options were referenced from Christopher 
** Merrill's final project posted to the Assignment announcement in Canvas:
** https://oregonstate.instructure.com/courses/1638952/assignments/7025561
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
#include "WayneEnterprise.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

// Function definitions
// Main Game component of the program. Used to interact with the other Classes
void playGame();
// Reset the Display so that the screen is refreshed with the current room and game specifics
void resetDisplay(Space* curSpace, Creature* batman, Creature* rasAlGhul, int moves);

int main()
{
	// Seed the random number generator
	std::srand(static_cast<unsigned int>(time(0)));

	// Make sure the screen is resized to capture all the ASCII goodness
	std::cout << "Please make sure to use Full Screen to enjoy all the ASCII goodness.\n\n";

	// Pause for user to hit Enter
	std::string tmpString;
	std::cout << "Press Enter to Continue" << std::endl;
	std::getline(std::cin, tmpString);
	std::cin.clear();
	std::cin.ignore();
	// This option does not work well in VS, but seems to work on Flip. Command window dependent
	std::cout << "\033[2J\033[1;1H";

	// Display the ASCII art for the Batman Intro
	std::string image = "";
	std::string fileName = "intro_Batman.txt";

	std::ifstream inFile;
	inFile.open(fileName.c_str());

	// Open the ASCII txt file and read in the lines
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

	// Opening monolog about the wonderful adventure about to take place
	std::cout << "BAM, POW, CRACK!\n";
	std::cout << "Batman wakes up from a crazy dream where he was the star of a 60's sitcom. For some reason he had\n";
	std::cout << "a mask with painted on eyebrows and cloth ears. And Holy Annoying Sidekick, Batman would never be\n";
	std::cout << "seen with that Robin character.\n\n";
	std::cout << "You start your adventure in the Batcave. Alfred has poured you a nice cup of bat coffee\n";
	std::cout << "Batman looks down at the bat console in his bat cave and sees the bat alarm. Selina Kyle has been\n";
	std::cout << "taken by Ra's Al Ghul and the League of Shadows. You must fight your way through some of the most\n";
	std::cout << "fearsome villains in Gotham.\n\n";


	// Another pause to allow the user to read the intro
	std::cout << "Press Enter to Continue" << std::endl;
	std::getline(std::cin, tmpString);
	std::cin.clear();
	std::cout << "\033[2J\033[1;1H";

	// Call the main Game function where all the goodness happens
	playGame();

	return 0;
}


/*********************************************************************
** Function: playGame()
** Description: Standard game function to assign all the objects and
**				walk the user through the different areas
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Through a series of logic choices, the player is 
**					either successful in defeating all the Creatures
**					or loses the game
*********************************************************************/
void playGame() {
	char menuOpt;
//	int batCaveChoice = 0;
//	int mainMenu = 0;
	int batMoves = 35;
	bool defeated = false;
	bool winning = false;

	// Initialize the Creature Objects
	Creature* poisonIvy = new PoisonIvy(75,15);
	Creature* batman = new Batman(100,15);
	Creature* league = new LeagueOfShadows(100,10);
	Creature* alGhul = new RasAlGhul(150, 17);
	Creature* riddler = new Riddler(75, 10);
	Creature* scarecrow = new Scarecrow(65, 12);

	// Initialize the Space Objects
	Space* currentSpace = NULL;
	Space* batCave = new BatCave("BATCAVE", batman, batman);
	Space* ivyLair = new IvyLair("IVY LAIR", batman, poisonIvy);
	Space* warehouse = new Warehouse("WAREHOUSE", batman, riddler);
	Space* arkhamAsylum = new ArkhamAsylum("ARKHAM ASYLUM", batman, scarecrow);
	Space* wayneManner = new WayneManner("WAYNE MANNER", batman, league);
	Space* wayneEnterprise = new WayneEnterprise("WAYNE INC", batman, alGhul);

	// Load the Utility Belts of all the Creatures
	riddler->add_inventory("Inoculation", "Immunizes against all types of plant type manipulations",1,false);
	riddler->add_inventory("Antidote", "In the off chance you are sprayed with a fearful toxin", 1, false);
	poisonIvy->add_inventory("ReGen Potion", "A mix of plant goodness to regain strength", 3, false);
	poisonIvy->add_inventory("Plant toxin", "An odorless toxin used to reduce opponent's strength", 1, true);
	scarecrow->add_inventory("Fear Gas", "A potent toxin capable of instilling fear in the strongest of foes", 1, true);
	scarecrow->add_inventory("Batarang", "Send it out and it comes back. Can retrieve items from small spaces.", 1, true);
	league->add_inventory("Lazarus Pit Water", "Used to resurrect those who are mostly dead", 1, false);
	league->add_inventory("Map to Ghul", "Specific location of Ra's Al Ghul", 1, true);
//	alGhul->add_inventory("Well of Sins", "All consuming evil",1, true);
//	alGhul->add_inventory("Katana","Ra's preferred weapon of choice",1,true);
//	alGhul->add_inventory("Smoke pellets", "Helps avoid opponents blows through diversion", 3, true);

	// Linking the adjacent rooms to the Batcave
	batCave->setAdjSpace(ivyLair, 'D');
	batCave->setAdjSpace(warehouse, 'L');
	batCave->setAdjSpace(arkhamAsylum, 'R');
	batCave->setAdjSpace(wayneManner, 'U');

	// Assigning all of the other connecting rooms and map flow
	ivyLair->setAdjSpace(batCave, 'U');
	warehouse->setAdjSpace(batCave, 'R');
	arkhamAsylum->setAdjSpace(batCave, 'L');
	wayneManner->setAdjSpace(batCave, 'D');
	wayneManner->setAdjSpace(wayneEnterprise, 'U');
	wayneEnterprise->setAdjSpace(wayneManner, 'D');

	// Initialize a modifiable Space variable
	currentSpace = batCave;

	do
	{
		// Reset to display to only show the new Space info
		resetDisplay(currentSpace, batman, alGhul, batMoves);
		currentSpace->displaySpaceInfo();
		// Display Space specific menu
		menuOpt = currentSpace->spaceMenu();

		// Start checking the returned values from the Space menu options
		// If user selected to go up
		if (menuOpt == 'U') {
			// Make sure the user can't go up to Wayne Enterprises until they have aquired the Map 
			if (currentSpace->getSpaceName() == "WAYNE MANNER" && !batman->search_items("Map to Ghul")) {
				std::cout << "\nWithout the map to Ra's Al Ghul's location, there is no point in heading to Wayne Enterprises.\n";
				batCave->pause();
			}
			// Friendly reminder that it might be good to increase Batman's health before fighting the League or Ra's
			else if (batman->get_strength() < 40) {
				std::cout << "\nThe battle ahead could be strenuous. Consider applying ReGen potion before taking on anymore villains.\n";
				currentSpace = currentSpace->moveSpace('U');
				batCave->pause();
				batMoves--;
			}
			// Move Up
			else {
				currentSpace = currentSpace->moveSpace('U');
				batMoves--;
			}
		}
		// Move Right
		else if (menuOpt == 'R') {
			currentSpace = currentSpace->moveSpace('R');
			batMoves--;
		}
		// Move Down
		else if (menuOpt == 'D') {
			currentSpace = currentSpace->moveSpace('D');
			batMoves--;
		}
		// Move Left
		else if (menuOpt == 'L') {
			currentSpace = currentSpace->moveSpace('L');
			batMoves--;
		}
		// Some options that don't have any specific logic but need to reduce Batman's remaining steps
		else if (menuOpt == 'K' || menuOpt == 'G' || menuOpt == 'T' || menuOpt == 'S' || menuOpt == 'F')
			batMoves--;
		// If user selects to Aquire the Grappling Gun
		else if (menuOpt == 'A') {
			// Determine if Batman's Utility Belt already has the tool
			if (batman->search_items("Grapple Gun")) {
				std::cout << "\nYou already have a Grapple Gun. You don't want to carry around two of these things.\n";
				batCave->pause();
			}
			else {
				std::cout << "\nAdding Grapple Gun to the Utility Belt\n";
				batman->add_inventory("Grapple Gun", "For hard to reach places. Can also be used to suspend things.", 1, false);
				batCave->pause();
			}
		}
		// Remove objects from the Utility Belt (in case it is too full)
		else if (menuOpt == 'I'){
			batman->remove_inventory();
			batCave->pause();
		}
		// When Batman wins the day
		else if (menuOpt == 'W') {
			std::cout << "\nYou have bested Ra's Al Ghul completed your mission!\n";
			winning = true;
			batCave->pause();
		}
		// Show that Batman's health has been depleted
		if (batman->defeated()) {
			resetDisplay(currentSpace, batman, alGhul, batMoves);
			std::cout << "\nBatman cannot be defeated but somehow his life has expired\n";
			defeated = true;
			batCave->pause();
		}
		// Warn the player that Batman's moves are getting low
		if (batMoves == 15) {
			resetDisplay(currentSpace, batman, alGhul, batMoves);
			std::cout << "You only have 15 moves left. Better get to Selina before Ra's takes her for good.\n";
			batCave->pause();
		}
		// When the number of moves runs out
		else if (batMoves <= 0) {
			resetDisplay(currentSpace, batman, alGhul, batMoves);
			defeated = true;
			std::cout << "You took to long looking around Gotham. Ra's Al Ghul has left the city and Salina is likely lost forever.\n";
			batCave->pause();
		}
		
	} while (menuOpt != 'Q' && !defeated && !winning);

	// Show the winning screen
	if (defeated || !winning)
		static_cast<Batman*>(batman)->endScreen(true);
	// Or show losing screen
	else
		static_cast<Batman*>(batman)->endScreen(false);

	// Pause for Enter
	batCave->pause();

	// Remove all the dynamic memory objects
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

/*********************************************************************
** Function: resetDisplay(Space, Creature, Creature, int)
** Description: Standard function for all Spaces to reset the display
**
** Parameters:		curSpace	The current Space Batman is in
**					batman		Monitor Batman's stats
**					rasAlGhul	Keep track of Ra's vitals
**					moves		Keep track of how many moves Batman 
**								has left
** Pre-Conditions: N/A
** Post-Conditions: Screen is reset and the game stats are displayed
**					along with the ASCII image of the room
*********************************************************************/
void resetDisplay(Space* curSpace, Creature* batman, Creature* rasAlGhul, int moves)
{
	// Clear the console on Linux
	std::cout << "\033[2J\033[1;1H";

	// Display Health and Inventory
	std::cout << "Batman's Strength: " << batman->get_strength() << std::endl;
	std::cout << "Ra's Al Ghul's Strength: " << rasAlGhul->get_strength() << std::endl;
	std::cout << "Moves Left: " << moves << std::endl;
	std::cout << "Belt Items: ";
	batman->get_itemName();
	std::cout << "\n";

	// Display current Space's ASCII artwork
	curSpace->displaySpaceMap();
}
