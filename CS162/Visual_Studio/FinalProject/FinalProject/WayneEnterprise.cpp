/*************************************************************************************
** WayneEnterprise.cpp is the Wayne Enterprises derived class function implementation.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The WayneEnterprise class represents a Space derived class. It inherits the variables
** from the Space base class. It also uses the virtual functions from the base class
** for the displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
***************************************************************************************/

#include "WayneEnterprise.hpp"

/*********************************************************************
** Function: WayneEnterprise::spaceMenu()
** Description: Abstract function from base class to implement the menu
** 				options for a particular Space
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Provides the different options specific for the
** 					WayneEnterprise class. Based on the user selection,
** 					a series of interactions takes place and the
** 					specific menu char variable is returned.
*********************************************************************/
char WayneEnterprise::spaceMenu()
{
	// Clear the menu choice vector
	subMenu.clearMenu();
	// Populate the menu choices
	subMenu.add_choice("Head back down to the Wayne Manner.");
	subMenu.add_choice("Apply gas to instill a little fear");
	subMenu.add_choice("Use Batarang to slightly stun Ra's Al Ghul");
	subMenu.add_choice("Fight Ra's Al Ghul, Batman style");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Villain Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");

	// Get the valid menu selection from the user
	menuChoice = subMenu.makeChoice();

	// Head back to Wayne Manner (Down)
	if (menuChoice == 1)
		return 'D';
	// Apply Fear Gas to Ra's Al Ghul
	else if (menuChoice == 2) {
		// Make sure Batman has the Fear Gas and that he hasn't already used it against Ra's
		if (IamBat->search_items("Fear Gas") && !gasApplied) {
			// Ra's doesn't take as much damage as the League but still loses 20 strength
			std::cout << "\nYou inflict a little fear into Ra's Al Ghul . He has trained to resist your parlor tricks.\n";
			this->gasApplied = true;
			// Take away a small amount of Ra's strength (40 attack minus 17 armor)
			Villain->pain(40, 0);
			// Wait for user to press Enter
			pause();
		}
		// If Batman applies Fear Gas one more time
		else if (IamBat->search_items("Fear Gas") && gasApplied) {
			std::cout << "\nYou have already tried to instill fear into Ra's but he is immune to the gas.\n";
			// Wait for user to press Enter
			pause();
		}
		// If Batman tried to apply fear and doesn't have any Fear Gas to apply
		else {
			std::cout << "\nYou don't have the proper tool to instill fear into Rah's Al Ghul.\n";
			std::cout << "He hits you with a quick strike. It hurts you a decent amount and you lose 20 strength.\n";
			// Causes a loss of 20 strength (35 attack minus 15 armor)
			IamBat->pain(35, 0);
			// Wait for user to press Enter
			pause();
		}
		return 'G';
	}
	// Use Batarang to stun Ra's Al Ghul
	else if (menuChoice == 3) {
		// Make sure Batman has the Batarang and Ra's is not already stunned
		if (IamBat->search_items("Batarang") && !stunApplied) {
			std::cout << "\nYour fight with the Ra's Al Ghul will be a little easier as he is partially stunned.\n";
			this->stunApplied = true;
			// Wait for user to press Enter
			pause();
		}
		// If Batman attempts to stun Ra's one more time
		else if (IamBat->search_items("Batarang") && stunApplied) {
			std::cout << "\nYou have already stunned the Ra's Al Ghul. Nothing to be done.\n";
			// Wait for user to press Enter
			pause();
		}
		// If Batman tried to stun without the Batarang
		else {
			std::cout << "\nYou don't have the proper tool to stun Ra's Al Ghul.\n";
			std::cout << "He hits you with a quick strike. It stuns you a little and you lose 15 strength.\n";
			// Causes a loss of 15 strength (30 attack, 15 armor)
			IamBat->pain(30, 0);
			// Wait for user to press Enter
			pause();
		}
		return 'S';
	}
	// Battle Ra's Al Ghul using the Game simulator from previous project
	else if (menuChoice == 4) {
		std::string response = "";
		// Make sure Batman has applied Fear Gas and Stunned Ra's before fighting
		if (!gasApplied || !stunApplied) {
			// Prompt the user if they want to battle anyway
			std::cout << "\nYou haven't applied all of the debuffs against Ra's. You will most likely fail.\n";
			std::cout << "Continue anyway (Y/N)?\n";
			std::string varString = "Please enter Y or N\n";
			SafeInput <std::string>(response,
				[=](std::string Input) -> bool {
				std::transform(Input.begin(), Input.end(),
					Input.begin(), ::toupper);
				return (Input.compare("Y") == 0 || Input.compare("N") == 0);
			}, varString);
			// If the user decides to play anyway
			if (response == "Y" || response == "y") {
				// Play the Game simulator where Batman will most likely lose
				printRound(IamBat, Villain);
				// Pass back if Batman defeats Ra's
				if (Villain->defeated()) {
					return 'W';
				}
				// Wait for user to press Enter
				pause();
			}
		}
		// If Batman has applied Fear Gas and Stunned Ra's, start the Game simulator
		else {
			printRound(IamBat, Villain);
			// Pass back if Batman defeats Ra's
			if (Villain->defeated()) {
				return 'W';
			}
			// Wait for user to press Enter
			pause();
		}
		return 'F';
	}
	// Manage Batman's Utility Belt inventory
	else if (menuChoice == 5)
		return 'I';
	// Display information on Ra's Al Ghul and a small hint to help the player
	else if (menuChoice == 6) {
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
** Function: WayneEnterprise::displaySpaceInfo()
** Description: Abstract function from base class to print the Space
** 				specific tag
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints a standard background about WayneEnterprise
*********************************************************************/
void WayneEnterprise::displaySpaceInfo()
{
	std::cout << "Wayne Enterprises is owned by billionaire Bruce Wayne. It was founded by merchant\n";
	std::cout << "ancestors of the Wayne family in the 17th century. The Industrial Revolution fueled\n";
	std::cout << "Wayne Enterprises into becoming a major powerhouse. In addition to providing income\n";
	std::cout << "for Bruce Wayne, its defense division also helps facilitate crime suppression in Gotham.\n";
}

/*********************************************************************
** Function: WayneEnterprise::displaySpaceMap()
** Description: Abstract function from base class to print the ASCII
** 				image for the WayneEnterprise map
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints out the ASCII text to the screen
*********************************************************************/
void WayneEnterprise::displaySpaceMap()
{
	std::string image = "";
	std::string fileName = "wayneEnterprise.txt";

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
** Function: WayneEnterprise::~WayneEnterprise()
** Description: WayneEnterprise Destructor
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
WayneEnterprise::~WayneEnterprise()
{
}
