/*************************************************************************************
** IvyLair.cpp is the Poison Ivy Lair derived class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The IvyLair class represents a Space derived class. It inherits the variables
** from the Space base class. It also uses the virtual functions from the base class
** for the displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
***************************************************************************************/

#include "IvyLair.hpp"

/*********************************************************************
** Function: IvyLair::spaceMenu()
** Description: Abstract function from base class to implement the menu
** 				options for a particular Space
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Provides the different options specific for the
** 					IvyLair class. Based on the user selection,
** 					a series of interactions takes place and the
** 					specific menu char variable is returned.
*********************************************************************/
char IvyLair::spaceMenu()
{
	// Clear the menu choice vector
	subMenu.clearMenu();
	// Populate the menu choices
	subMenu.add_choice("Head back to the Batcave to rethink your strategy.");
	subMenu.add_choice("Destroy Ivy's lab, including the helpless plants");
	subMenu.add_choice("Give Ivy a kiss. One kiss won't hurt");
	subMenu.add_choice("Fight Ivy, Batman style");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Villain Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");

	// Get the valid menu selection from the user
	menuChoice = subMenu.makeChoice();

	// Head back to the Batcave (Up)
	if (menuChoice == 1)
		return 'U';
	// Destroy Ivy's lab but this doesn't really help you too much
	else if (menuChoice == 2) {
		std::cout << "\nYou needlessly destroyed Ivy's lab and release plant toxins. You lost 15 strength.\n";
		// Inflict pain on Batman (30 attack minus 15 defense causes the loss of 15 strength)
		IamBat->pain(30, 0);
		pause();
		return 'P';
	}
	// Give Ivy a kiss to see if she will hand over some Plant Toxin
	else if (menuChoice == 3) {
		// If Batman is Incolulated to Ivy's seduction toxin, then he can retrieve the plant toxin
		if (IamBat->search_items("Inoculation") && Villain->search_items("Plant toxin")) {
			std::cout << "\nYou have have been immunized to resist Ivy's charms, but don't play with fire too much.\n";
			// Transfer the Plant toxin from Poison Ivy's Items and place in Batman's Utility Belt
			Villain->transfer_qty("Plant toxin", IamBat);
			// Wait for user to press Enter
			pause();
		}
		// If Batman kisses Ivy but she doesn't have any Plant toxin left
		else if (IamBat->search_items("Inoculation") && !Villain->search_items("Plant toxin")) {
			std::cout << "\nYou pushed your luck and the Inoculation ran out. Wedding bells are in your future.\n";
			std::cout << "You lose 25 strength\n";
			// Pushing your luck causes a loss of 25 strength (40 attack minus 15 armor)
			IamBat->pain(40, 0);
			pause();
		}
		// If Batman kisses Ivy and doesn't have any Inoculation to resist
		else {
			std::cout << "\nYou don't have the Inoculation to resist Ivy's advances and lose 25 strength. \n";
			// Causes a loss of 25 strength (40 attack minus 15 armor)
			IamBat->pain(40, 0);
			// Check to see if this was enough to kill Batman
			if (!IamBat->defeated())
				std::cout << "Run back to the Batcave to escape before it's too late.\n";
			// If Batman is dead
			else
				std::cout << "You just couldn't take the hint, could you. All your strength is drained and the fun is over.\n";
			// Wait for user to press Enter
			pause();
		}
		return 'K';
	}
	// Battle Poison Ivy using the Game simulator from previous project
	else if (menuChoice == 4) {
		std::string response = "";
		// Make sure Batman has the Inoculation to resist Ivy's Seduction
		if (!IamBat->search_items("Inoculation")) {
			// Prompt the user if they want to battle anyway
			std::cout << "\nYou don't have anything to protect you from Ivy's Seduction. Are you sure you want to continue (Y/N)?\n";
			std::string varString = "Please enter Y or N\n";
			SafeInput <std::string>(response,
				[=](std::string Input) -> bool {
				std::transform(Input.begin(), Input.end(),
					Input.begin(), ::toupper);
				return (Input.compare("Y") == 0 || Input.compare("N") == 0);
			}, varString);
			// If the user decides to play anyway
			if (response == "Y" || response == "y") {
				// Play the Game simulator where Batman may be killed if Ivy uses Seduction
				printRound(IamBat, Villain);
				// Wait for user to press Enter
				pause();
			}
		}
		// If Batman has Inoculation, start the Game simulator
		else {
			// Play the Game simulator where Batman will be immune to Ivy's SEDUCE
			printRound(IamBat, Villain);
			// After Ivy is defeated, transfer ReGen potion to Batman
			if (Villain->defeated()) {
				Villain->transfer_qty("ReGen Potion", IamBat);
				Villain->transfer_qty("ReGen Potion", IamBat);
				Villain->transfer_qty("ReGen Potion", IamBat);
			}
			// Wait for user to press Enter
			pause();
		}
		return 'F';
	}
	// Manage Batman's Utility Belt inventory
	else if (menuChoice == 5)
		return 'I';
	// Display information on Poison Ivy and a small hint to help the player
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
** Function: IvyLair::displaySpaceInfo()
** Description: Abstract function from base class to print the Space
** 				specific tag
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints a standard background about Ivy's Lair
*********************************************************************/
void IvyLair::displaySpaceInfo()
{
	std::cout << "A pleasant smelling Lair, much better than your damp Batcave. There are aromas all around and\n";
	std::cout << "the plants make you feel relaxed. There is a sense you could just let yourself go and be happy,\n";
	std::cout << "but you can never be happy. You are Batman!\n";
}

/*********************************************************************
** Function: IvyLair::displaySpaceMap()
** Description: Abstract function from base class to print the ASCII
** 				image for the Ivy Lair map
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints out the ASCII text to the screen
*********************************************************************/
void IvyLair::displaySpaceMap()
{
	std::string image = "";
	std::string fileName = "ivyLair.txt";

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
** Function: IvyLair::~IvyLair()
** Description: IvyLair Destructor
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
IvyLair::~IvyLair()
{
}
