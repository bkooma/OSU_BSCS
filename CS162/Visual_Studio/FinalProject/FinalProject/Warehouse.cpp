/*************************************************************************************
** Warehouse.cpp is the Riddler Warehouse derived class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Warehouse class represents a Space derived class. It inherits the variables
** from the Space base class. It also uses the virtual functions from the base class
** for the displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
** Retrieved the ascii image for the Warehouse from the following ascii site:
** http://www.chris.com/ascii/index.php?art=objects/buildings
***************************************************************************************/

#include "Warehouse.hpp"

/*********************************************************************
** Function: Warehouse::spaceMenu()
** Description: Abstract function from base class to implement the menu
** 				options for a particular Space
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Provides the different options specific for the
** 					Warehouse class. Based on the user selection,
** 					a series of interactions takes place and the
** 					specific menu char variable is returned.
*********************************************************************/
char Warehouse::spaceMenu()
{
	// Clear the menu choice vector
	subMenu.clearMenu();
	// Populate the menu choices
	subMenu.add_choice("Head back to the Batcave to rethink your strategy.");
	subMenu.add_choice("Play the Riddler's game");
	subMenu.add_choice("Suspend Riddler from the rafters");
	subMenu.add_choice("Fight Riddler, Batman style");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Villain Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");

	// Get the valid menu selection from the user
	menuChoice = subMenu.makeChoice();

	// Head back to the Batcave (Right)
	if (menuChoice == 1)
		return 'R';
	// Play riddle game provided by the Riddler
	else if (menuChoice == 2) {
		int randomNum = 0;
		int answer = 0;
		bool correctAnswer = false;

		// Used for user input validation
		std::string varString = "That isn't even a number. You truly are intellectually superior to me.\n";

		std::cout << "\nI have put together some children's number riddles just for you Batman to test your puny Bat brain.\n";
		std::cout << "Riddle me this Batman: \n";

		// Randomly generate a question from three options
		randomNum = rand() % 3 + 1;

		// First riddle option (answer is 9)
		if (randomNum == 1) {
			std::cout << "If two's company and three's a crowd, what are four and five?\n";
			SafeInput <int>(answer,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
			}, varString);
			// If user is correct
			if (answer == 9)
				correctAnswer = true;
		}
		// Second riddle option (answer is 3)
		else if (randomNum == 2) {
			std::cout << "If there are four apples and you take away three, how many do you have?\n";
			SafeInput <int>(answer,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
			}, varString);
			// If user is correct
			if (answer == 3)
				correctAnswer = true;
		}
		// Third riddle option (answer is 1)
		else if (randomNum == 3) {
			std::cout << "How many eggs can you put in an empty basket?\n";
			SafeInput <int>(answer,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
			}, varString);
			// If user is correct
			if (answer == 1)
				correctAnswer = true;
		}

		// If the user answers correctly and Riddler still has Inoculation
		if (correctAnswer && Villain->search_items("Inoculation")) {
			std::cout << "Great job Batman. You are smarter than a five year old.\n";
			Villain->transfer_qty("Inoculation", IamBat);
			// Wait for user to press Enter
			pause();
		}
		// If the user answers correctly but Riddler no longer has any Inoculation
		else if (correctAnswer && !Villain->search_items("Inoculation")) {
			std::cout << "While you proved you are smarter than a five your old, there is nothing to award you with.\n";
			std::cout << "Great job wasting one of your moves to answer a brain-less riddle.\n";
			// Wait for user to press Enter
			pause();
		}
		// If the user answers wrong
		else {
			std::cout << "WRONG WRONG WRONG!!! Did you even try? Defeating you will be easier than taking candy\n";
			std::cout << "from a baby. Especially since you are as smart as one.\n";
			std::cout << "Answering the question wrong causes mental and physical pain. You lose 10 strength.\n";
			// Batman loses 10 strength (attack of 25 minus armor of 15)
			IamBat->pain(25, 0);
			pause();
		}
		return 'G';
	}
	// Hang Riddler from the rafters using his Grappling Hook
	else if (menuChoice == 3) {
		// Make sure Batman has the Grapple Gun and the Antidote hasn't already been retrieved
		if (IamBat->search_items("Grapple Gun") && Villain->search_items("Antidote")) {
			std::cout << "\nYou suspend Riddler from the rafters and he screams to let him down.\n";
			std::cout << "He promises to give you something to combat Fear Gas if you let him down.\n";
			// Transfer Grapple Gun from Riddler's Items and place in Batman's Utility Belt
			Villain->transfer_qty("Antidote", IamBat);
			// Wait for user to press Enter
			pause();
		}
		// If Batman attempts to retrieve Antidote after he has already taken it from Riddler
		else if (IamBat->search_items("Grapple Gun") && !Villain->search_items("Antidote")) {
			std::cout << "\nYou suspend Riddler from the rafters but has nothing to offer.\n";
			// Wait for user to press Enter
			pause();
		}
		// Provide info if Batman doesn't currently have the Grapple Gun
		else {
			std::cout << "\nYou don't have the proper tool to suspend Riddler from the rafters.\n";
			std::cout << "Riddler hits you with his question mark cane. It is a piddly blow but you lose 10 strength.\n";
			// Batman loses 10 strength (25 attack minus 15 armor)
			IamBat->pain(25, 0);
			pause();
		}
		return 'S';
	}
	// Battle Riddler using the Game simulator from previous project
	else if (menuChoice == 4) {
		// Start the Game simulator
		printRound(IamBat, Villain);
		// After Riddler has been defeated, transfer Inoculation to Batman
		if (Villain->defeated()) {
			Villain->transfer_qty("Inoculation", IamBat);
		}
		// Wait for user to press Enter
		pause();
		return 'F';
	}
	// Manage Batman's Utility Belt inventory
	else if (menuChoice == 5)
		return 'I';
	// Display information on Riddler and a small hint to help the player
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
** Function: Warehouse::displaySpaceInfo()
** Description: Abstract function from base class to print the Space
** 				specific tag
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints a standard background about the Warehouse
*********************************************************************/
void Warehouse::displaySpaceInfo()
{
	std::cout << "You can't see much in this maze of a building. There are question marks scattered all around.\n";
	std::cout << "Nothing annoys Batman more than a dark abandoned place with rodents that come out at night.\n";
	std::cout << "What really makes Batman angry though is the incessant questioning by the headless voice.\n";
}

/*********************************************************************
** Function: Warehouse::displaySpaceMap()
** Description: Abstract function from base class to print the ASCII
** 				image for the Warehouse map
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Prints out the ASCII text to the screen
*********************************************************************/
void Warehouse::displaySpaceMap()
{
	std::string image = "";
	std::string fileName = "warehouse.txt";

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
** Function: Warehouse::~Warehouse()
** Description: Warehouse Destructor
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
Warehouse::~Warehouse()
{
}
