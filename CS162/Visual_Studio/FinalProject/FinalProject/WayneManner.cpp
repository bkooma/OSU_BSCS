/*************************************************************************************
** WayneManner.cpp is the Wayne Manner derived class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The WayneManner class represents a Space derived class. It inherits the variables
** from the Space base class. It also uses the virtual functions from the base class
** for the displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
***************************************************************************************/

#include "WayneManner.hpp"

/*********************************************************************
** Function: WayneManner::spaceMenu()
** Description: Abstract function from base class to implement the menu
** 				options for a particular Space
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Provides the different options specific for the
** 					WayneManner class. Based on the user selection,
** 					a series of interactions takes place and the
** 					specific menu char variable is returned.
*********************************************************************/
char WayneManner::spaceMenu()
{
	// Clear the menu choice vector
	subMenu.clearMenu();
	// Populate the menu choices
	subMenu.add_choice("Head back to the Batcave to rethink your strategy.");
	subMenu.add_choice("Head to Wayne Enterprises to face Ra's Al Ghul.");
	subMenu.add_choice("Apply gas to instill some fear in the League");
	subMenu.add_choice("Use Batarang to stun half the members of the League");
	subMenu.add_choice("Fight the League, Batman style");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Villain Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");

	// Get the valid menu selection from the user
	menuChoice = subMenu.makeChoice();

	// Head back to the Batcave (Down)
	if (menuChoice == 1)
		return 'D';
	// Head to Wayne Enterprise to battle Ra's Al Ghul (Up)
	if (menuChoice == 2)
		return 'U';
	// Apply Fear Gas to the League of Shadows
	else if (menuChoice == 3) {
		// Make sure Batman has the Fear Gas and that he hasn't already used it against the League
		if (IamBat->search_items("Fear Gas") && !gasApplied) {
			// The League has their strength cut in half
			std::cout << "\nYou inflict additional fear into the League. Their strength is cut in half.\n";
			this->gasApplied = true;
			// Take away half of the League's strength (60 attack minus 10 armor)
			Villain->pain(60, 0);
			// Wait for user to press Enter
			pause();
		}
		// If Batman applies Fear Gas one more time
		else if (IamBat->search_items("Fear Gas") && gasApplied) {
			std::cout << "\nYou have already instilled enough fear into the League. Nothing to be done.\n";
			pause();
		}
		// If Batman tried to apply fear and doesn't have any Fear Gas to apply
		else {
			std::cout << "\nYou don't have the proper tool to instill fear into the members of the League.\n";
			std::cout << "They hit you with a quick strike. It only hurts you a little and you lose 10 strength.\n";
			// Causes a loss of 10 strength (25 attack minus 15 armor)
			IamBat->pain(25, 0);
			// Wait for user to press Enter
			pause();
		}
		return 'G';
	}
	// Use Batarang to stun the League
	else if (menuChoice == 4) {
		// Make sure Batman has the Batarang and the League is not already stunned
		if (IamBat->search_items("Batarang") && !stunApplied) {
			std::cout << "\nYour fight with the League will be much easier only fighting half of them.\n";
			this->stunApplied = true;
			// Wait for user to press Enter			
			pause();
		}
		// If Batman attempts to stun the League one more time
		else if (IamBat->search_items("Batarang") && stunApplied) {
			std::cout << "\nYou have already stunned the League of Shadows. Nothing to be done.\n";
			// Wait for user to press Enter
			pause();
		}
		// If Batman tried to stun without the Batarang
		else {
			std::cout << "\nYou don't have the proper tool to stun members of the League.\n";
			std::cout << "They hit you with a quick strike. It only stuns you a little and you lose 10 strength.\n";
			// Causes a loss of 10 strength (25 attack, 15 armor)
			IamBat->pain(25, 0);
			// Wait for user to press Enter
			pause();
		}
		return 'S';
	}
	// Battle League of Shadows using the Game simulator from previous project
	else if (menuChoice == 5) {
		std::string response = "";
		// Make sure Batman has applied Fear Gas and Stunned the League before fighting
		if (!gasApplied || !stunApplied) {
			// Prompt the user if they want to battle anyway
			std::cout << "\nYou haven't applied all of the debuffs against the League. You can still prevail but risk\n";
			std::cout << "losing more strength. Continue anyway (Y/N)?\n";
			std::string varString = "Please enter Y or N\n";
			SafeInput <std::string>(response,
				[=](std::string Input) -> bool {
				std::transform(Input.begin(), Input.end(),
					Input.begin(), ::toupper);
				return (Input.compare("Y") == 0 || Input.compare("N") == 0);
			}, varString);
			// If the user decides to play anyway
			if (response == "Y" || response == "y") {
				printRound(IamBat, Villain);
				// Play the Game simulator where Batman will most likely lose most of his health
				if (Villain->defeated()) {
					// Transfer the Map and Lazarus Water from the Leagues's Items and place in Batman's Utility Belt
					Villain->transfer_qty("Map to Ghul", IamBat);
					Villain->transfer_qty("Lazarus Pit Water", IamBat);
				}
				// Wait for user to press Enter
				pause();
			}
		}
		// If Batman has applied Fear Gas and Stunned the League, start the Game simulator
		else {
			printRound(IamBat, Villain);
			// Transfer the Map and Lazarus Water from the Leagues's Items and place in Batman's Utility Belt
			if (Villain->defeated()) {
				Villain->transfer_qty("Map to Ghul", IamBat);
				Villain->transfer_qty("Lazarus Pit Water", IamBat);
			}
			// Wait for user to press Enter
			pause();
		}
		return 'F';
	}
	// Manage Batman's Utility Belt inventory
	else if (menuChoice == 6)
		return 'I';
	// Display information on League of Shadows and a small hint to help the player
	else if (menuChoice == 7) {
		this->displayVillainInfo();
		// Wait for user to press Enter
		pause();
		return 'H';
	}
	// User has decided to quit the game
	else
		return 'Q';
}

/*********************************************************************
** Function: WayneManner::displaySpaceInfo()
** Description: Abstract function from base class to print the Space
** 				specific tag
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints a standard background about WayneManner
*********************************************************************/
void WayneManner::displaySpaceInfo()
{
	std::cout << "A sprawling and expansive estate of Bruce Wayne, billionaire industrialist and\n";
	std::cout << "notorious playboy. They say there are hidden caves around the premises but no one\n";
	std::cout << "dares venture in because they are infested with bats.\n";
}

/*********************************************************************
** Function: WayneManner::displaySpaceMap()
** Description: Abstract function from base class to print the ASCII
** 				image for the WayneManner map
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints out the ASCII text to the screen
*********************************************************************/
void WayneManner::displaySpaceMap()
{
	std::string image = "";
	std::string fileName = "wayneManner.txt";

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
** Function: WayneManner::~WayneManner()
** Description: WayneManner Destructor
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
WayneManner::~WayneManner()
{
}
