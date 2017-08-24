#include "WayneManner.hpp"



char WayneManner::spaceMenu()
{
	subMenu.clearMenu();
	subMenu.add_choice("Head back to the Batcave to rethink your strategy.");
	subMenu.add_choice("Head to Wayne Enterprises to face Ra's Al Ghul.");
	subMenu.add_choice("Apply gas to instill some fear in the League");
	subMenu.add_choice("Use Batarang to stun half the members of the League");
	subMenu.add_choice("Fight the League, Batman style");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Villain Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");
	menuChoice = subMenu.makeChoice();

	if (menuChoice == 1)
		return 'D';
	if (menuChoice == 2)
		return 'U';
	else if (menuChoice == 3) {
		if (IamBat->search_items("Fear Gas") && !gasApplied) {
			std::cout << "\nYou inflict additional fear into the League. Their strength is cut in half.\n";
			this->gasApplied = true;
			pause();
		}
		else if (IamBat->search_items("Fear Gas") && gasApplied) {
			std::cout << "\nYou have already instilled enough fear into the League. Nothing to be done.\n";
			pause();
		}
		else {
			std::cout << "\nYou don't have the proper tool to instill fear into the members of the League.\n";
			std::cout << "They hit you with a quick strike. It only hurts you a little and you lose 10 strength.\n";
			IamBat->pain(30, 0);
			pause();
		}

		return 'G';
	}
	else if (menuChoice == 4) {
		if (IamBat->search_items("Batarang") && !stunApplied) {
			std::cout << "\nYour fight with the League will be much easier only fighting half of them.\n";
			this->stunApplied = true;
			
			pause();
		}
		else if (IamBat->search_items("Batarang") && stunApplied) {
			std::cout << "\nYou have already stunned the League of Shadows. Nothing to be done.\n";
			pause();
		}
		else {
			std::cout << "\nYou don't have the proper tool to stun members of the League.\n";
			std::cout << "They hit you with a quick strike. It only stuns you a little and you lose 10 strength.\n";
			IamBat->pain(30, 0);
			pause();
		}
		return 'S';
	}
	else if (menuChoice == 5) {
		std::string response = "";
		if (!gasApplied || !stunApplied) {
			std::cout << "\nYou haven't applied all of the debuffs against the League. You can still prevail but risk\n";
			std::cout << "losing more strength. Continue anyway (Y/N)?\n";
			std::string varString = "Please enter Y or N\n";
			SafeInput <std::string>(response,
				[=](std::string Input) -> bool {
				std::transform(Input.begin(), Input.end(),
					Input.begin(), ::toupper);
				return (Input.compare("Y") == 0 || Input.compare("N") == 0);
			}, varString);

			if (response == "Y" || response == "y") {
				printRound(IamBat, Villain);
				pause();
			}
		}
		else {
			printRound(IamBat, Villain);
			pause();
		}
		if (Villain->defeated()) {
			Villain->transfer_qty("Map to Ghul", IamBat);
			Villain->transfer_qty("Lazarus Pit Water", IamBat);
		}
		return 'F';
	}
	else if (menuChoice == 6)
		return 'I';
	else if (menuChoice == 7) {
		this->displayVillainInfo();
		pause();
		return 'H';
	}
	else
		return 'Q';
}

void WayneManner::displaySpaceInfo()
{
	std::cout << "\nA sprawling and expansive estate of Bruce Wayne, billionaire industrialist and\n"
	std::cout << "notorious playboy. They say there are hidden caves around the premises but no one\n";
	std::cout << "dares venture in because they are infested with bats.\n";
}

WayneManner::~WayneManner()
{
}
