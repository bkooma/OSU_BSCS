/*************************************************************************************
** ArkhamAsylum.cpp is the Arkham Asylum derived class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The ArkhamAsylum class represents a Space derived class. It inherits the variables
** from the Space base class. It also uses the virtual functions from the base class
** for the displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
***************************************************************************************/

#include "ArkhamAsylum.hpp"

/*********************************************************************
** Function: ArkhamAsylum::spaceMenu()
** Description: Abstract function from base class to implement the menu
** 				options for a particular Space
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Provides the different options specific for the
** 					ArkhamAsylum class. Based on the user selection,
** 					a series of interactions takes place and the
** 					specific menu char variable is returned.
*********************************************************************/
char ArkhamAsylum::spaceMenu()
{
	// Clear the menu choice vector
	subMenu.clearMenu();
	// Populate the menu choices
	subMenu.add_choice("Head back to the Batcave to rethink your strategy.");
	subMenu.add_choice("Steal Fear Gas from Scarecrow's stash");
	subMenu.add_choice("Fight fire with fire by releasing plant toxin");
	subMenu.add_choice("Fight Scarecrow, Batman style");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Villain Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");

	// Get the valid menu selection from the user
	menuChoice = subMenu.makeChoice();

	// Head back to the Batcave (Left)
	if (menuChoice == 1)
		return 'L';
	// Steal Fear Gas from Scarecrow's office
	else if (menuChoice == 2) {
		// Make sure Batman has the Batarang and Fear Gas hasn't already been retrieved
		if (IamBat->search_items("Batarang") && Villain->search_items("Fear Gas")) {
			std::cout << "\nYou use the Batarang to fit under the locked door. As any good Batarang does, \n";
			std::cout << "it brings the Scarecrow's Fear Gas back to you\n";
			// Transfer the Fear Gas from Scarecrow's Items and place in Batman's Utility Belt
			Villain->transfer_qty("Fear Gas", IamBat);
			// Wait for user to press Enter
			pause();
		}
		// If Batman attempts to retrieve Fear Gas again from the same location
		else if (IamBat->search_items("Batarang") && !Villain->search_items("Fear Gas")) {
			std::cout << "\nThere is nothing to retrieve from Scarecrow's office and the Batarang comes \n";
			std::cout << "back empty. Bad Batarang, bad!\n";
			// Wait for user to press Enter
			pause();
		}
		// Provide info if Batman doesn't currently hold the Batarang
		else {
			std::cout << "\nScarecrow's stash is locked in his office. The space under the door might just be\n";
			std::cout << "big enough to fit a curved metal object that can retrieve things.\n";
			// Wait for user to press Enter
			pause();
		}
		return 'S';
	}
	// Release Poison Ivy's Plant toxin on Scarecrow
	else if (menuChoice == 3) {
		// Make sure Batman has the Plant toxin and Batarang hasn't already been retrieved
		if (IamBat->search_items("Plant toxin") && Villain->search_items("Batarang")) {
			std::cout << "\nYou use Ivy's plant toxin and Scarecrow is temporarily stunned and drops a curved metal object.\n";
			std::cout << "You pick up the object that looks kind-of like a bat so it must be a Batarang.\n";
			// Transfer Batarang from Scarecrow's Items and place in Batman's Utility Belt
			Villain->transfer_qty("Batarang", IamBat);
			// Wait for user to press Enter
			pause();
		}
		// If Batman attempts to retrieve Batarang after he has already taken it from Scarecrow
		else if (IamBat->search_items("Plant toxin") && !Villain->search_items("Batarang")) {
			std::cout << "\nScarecrow has developed an immunity to Ivy's toxin. It has no effect.\n";
			// Wait for user to press Enter
			pause();
		}
		// Provide info if Batman doesn't currently have the Plant toxin
		else {
			std::cout << "\nYou don't have any toxin in your Utility Belt. Maybe you should find someone that might dabble with plant toxins\n";
			pause();
		}
		return 'T';
	}
	// Battle Scarecrow using the Game simulator from previous project
	else if (menuChoice == 4) {
		std::string response = "";
		// Make sure Batman has the Antidote to Fear Gas before going into battle
		if (!IamBat->search_items("Antidote")) {
			// Prompt the user if they want to battle anyway
			std::cout << "\nYou don't have anything to protect you from Scarecrow's Fear Gas. Are you sure you want to continue (Y/N)?\n";
			std::string varString = "Please enter Y or N\n";
			SafeInput <std::string>(response,
				[=](std::string Input) -> bool {
				std::transform(Input.begin(), Input.end(),
					Input.begin(), ::toupper);
				return (Input.compare("Y") == 0 || Input.compare("N") == 0);
			}, varString);
			// If user decides to play anyway
			if (response == "Y" || response == "y") {
				// Play the Game simulator where Batman will take more damage without Antidote
				printRound(IamBat, Villain);
				// Wait for user to press Enter
				pause();
			}
		}
		// If Batman has Antidote, start the Game simulator
		else {
			// Play the Game simulator where Batman will take less damage
			printRound(IamBat, Villain);
			// After Scarecrow has been defeated, transfer Fear Gas to Batman
			if (Villain->defeated()) {
				Villain->transfer_qty("Fear Gas", IamBat);
			}
			// Wait for user to press Enter
			pause();
		}
		return 'F';
	}
	// Manage Batman's Utility Belt inventory
	else if (menuChoice == 5)
		return 'I';
	// Display information on Scarecrow and a small hint to help the player
	else if (menuChoice == 6) {
		this->displayVillainInfo();
		// Wait for user to press Enter
		pause();
		return 'H';
	}
	else
		return 'Q';
}

/*********************************************************************
** Function: ArkhamAsylum::displaySpaceInfo()
** Description: Abstract function from base class to print the Space
** 				specific tag
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints a standard background about Arkham Asylum
*********************************************************************/
void ArkhamAsylum::displaySpaceInfo()
{
	std::cout << "Arkham Asylum is filled with all sorts of crazy Batman villains. Every criminal Batman faces\n";
	std::cout << "has spent a stint in Arkham's finest institution. There seems to be a heightened level of fear in \n";
	std::cout << "these ominous halls as of late.\n";
}

/*********************************************************************
** Function: ArkhamAsylum::displaySpaceMap()
** Description: Abstract function from base class to print the ASCII
** 				image for the Arkham Asylum map
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints out the ASCII text to the screen
*********************************************************************/
void ArkhamAsylum::displaySpaceMap()
{
	std::string image = "";
	std::string fileName = "arkhamAsylum.txt";

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
** Function: ArkhamAsylum::~ArkhamAsylum()
** Description: ArkhamAsylum Destructor
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
ArkhamAsylum::~ArkhamAsylum(){

}
