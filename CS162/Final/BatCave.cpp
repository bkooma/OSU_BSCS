#include "BatCave.hpp"

char BatCave::spaceMenu()
{
	subMenu.clearMenu();
	subMenu.add_choice("Head up to Wayne Manner. I hear Bruce Wayne lives there (sounds like a cool guy)");
	subMenu.add_choice("Head right to Arkham Asylum");
	subMenu.add_choice("Head down to Ivy's Lair");
	subMenu.add_choice("Head left to Gotham Warehouse");
	subMenu.add_choice("Add the Grapple Hook to your Utility Belt");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Use ReGen Potion");
	subMenu.add_choice("Batman Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");
	menuChoice = subMenu.makeChoice();

	if (menuChoice == 1)
		return 'U';
	else if (menuChoice == 2)
		return 'R';
	else if (menuChoice == 3)
		return 'D';
	else if (menuChoice == 4)
		return 'L';
	else if (menuChoice == 5)
		return 'A';
	else if (menuChoice == 6)
		return 'I';
	else if (menuChoice == 7) {
		std::string response = "";
		if (IamBat->search_items("ReGen Potion") && IamBat->get_strength() < 100) {
			std::cout << "\nWould you like to use a ReGen Potion to increase your strength by 25?\n";
			// Make sure the user is selecting a Student or an Instructor
			std::string varString = "Please enter Y or N\n";
			SafeInput <std::string>(response,
				[=](std::string Input) -> bool {
				std::transform(Input.begin(), Input.end(),
					Input.begin(), ::toupper);
				return (Input.compare("Y") == 0 || Input.compare("N") == 0);
			}, varString);

			if (response == "y" || response == "Y") {
				IamBat->recover_strength();
			}
			pause();
		}
		else if (IamBat->search_items("ReGen Potion") && IamBat->get_strength() < 100)
		{
			std::cout << "\nYou already have all the strength you can handle.\n";
			pause();
		}
		else {
			std::cout << "\nYou don't have any ReGen Potions available in your Utility Belt.\n";
			pause();
		}
		return 'B';
	}
	else if (menuChoice == 8)
	{
		this->displayVillainInfo();
		pause();
		return 'H';
	}
	else 
		return 'Q';
}

void BatCave::displaySpaceInfo()
{
	std::cout << "\nThe bat cave is dark and damp but you feel comfortable (because of the bats and you're Batman!)\n";
}

BatCave::~BatCave(){}
