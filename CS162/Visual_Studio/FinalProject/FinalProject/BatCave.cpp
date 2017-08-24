/*************************************************************************************
** BatCave.cpp is the Batcave derived class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Batcave class represents a Space derived class. It is the main corridor for all
** Space objects in the Batman Game. It inherits the variables from the Space base
** class. It also uses the virtual functions from the base class for the
** displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
***************************************************************************************/

#include "BatCave.hpp"

/*********************************************************************
** Function: BatCave::spaceMenu()
** Description: Abstract function from base class to implement the menu
** 				options for a particular Space
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Provides the different options specific for the
** 					BatCave class. Based on the user selection,
** 					a series of interactions takes place and the
** 					specific menu char variable is returned.
*********************************************************************/
char BatCave::spaceMenu()
{
	// Clear the menu choice vector
	subMenu.clearMenu();
	// Populate the menu choices
	subMenu.add_choice("Head up to Wayne Manner. I hear Bruce Wayne lives there (sounds like a cool guy)");
	subMenu.add_choice("Head right to Arkham Asylum");
	subMenu.add_choice("Head down to Ivy's Lair");
	subMenu.add_choice("Head left to Gotham Warehouse");
	subMenu.add_choice("Add the Grapple Hook to your Utility Belt");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Use ReGen Potion");
	subMenu.add_choice("Batman Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");

	// Get the valid menu selection from the user
	menuChoice = subMenu.makeChoice();

	// Head up to Wayne Manner
	if (menuChoice == 1)
		return 'U';
	// Head right to to Arkham Asylum
	else if (menuChoice == 2)
		return 'R';
	// Head down to Ivy's Lair
	else if (menuChoice == 3)
		return 'D';
	// Head left to Riddler's Warehouse
	else if (menuChoice == 4)
		return 'L';
	// Place the Grapple Hook into Batman's Utility Belt
	else if (menuChoice == 5)
		return 'A';
	// Manage Batman's Utility Belt inventory
	else if (menuChoice == 6)
		return 'I';
	// Recover some of Batman's strength using the ReGen potion
	else if (menuChoice == 7) {
		std::string response = "";
		// Make sure Batman has the ReGen Potion and his strength is less than 100
		if (IamBat->search_items("ReGen Potion") && IamBat->get_strength() < 100) {
			std::cout << "\nWould you like to use a ReGen Potion to increase your strength by 25(Y/N)?\n";
			std::string varString = "Please enter Y or N\n";
			SafeInput <std::string>(response,
				[=](std::string Input) -> bool {
				std::transform(Input.begin(), Input.end(),
					Input.begin(), ::toupper);
				return (Input.compare("Y") == 0 || Input.compare("N") == 0);
			}, varString);

			// If the user opts to use one of the potions
			if (response == "y" || response == "Y") {
				// Add 25 strength to Batman (or up to max of 100)
				IamBat->recover_strength();
			}
			// Wait for user to press Enter
			pause();
		}
		// If Batman already has strength at 100, then no need to apply ReGen potion
		else if (IamBat->search_items("ReGen Potion") && IamBat->get_strength() == 100)
		{
			std::cout << "\nYou already have all the strength you can handle.\n";
			// Wait for user to press Enter
			pause();
		}
		// No ReGen potions currently available. Need to battle Ivy to get some
		else {
			std::cout << "\nYou don't have any ReGen Potions available in your Utility Belt.\n";
			pause();
		}
		return 'B';
	}
	// Display information on Batman and a small hint
	else if (menuChoice == 8)
	{
		this->displayVillainInfo();
		// Wait for user to press Enter
		pause();
		return 'H';
	}
	else 
		return 'Q';
}

/*********************************************************************
** Function: BatCave::displaySpaceInfo()
** Description: Abstract function from base class to print the Space
** 				specific tag
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints a standard background about the Batcave.
*********************************************************************/
void BatCave::displaySpaceInfo()
{
	std::cout << "The bat cave is dark and damp but you feel comfortable (because of the bats and you're Batman!)\n";
}

/*********************************************************************
** Function: ArkhamAsylum::displaySpaceMap()
** Description: Abstract function from base class to print the ASCII
** 				image for the BatCave map
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints out the ASCII text to the screen
*********************************************************************/
void BatCave::displaySpaceMap()
{
	std::string image = "";
	std::string fileName = "batCave.txt";

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
}

/*********************************************************************
** Function: BatCave::~BatCave()
** Description: BatCave Destructor
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
BatCave::~BatCave(){}
