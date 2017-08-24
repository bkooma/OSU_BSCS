#include "IvyLair.hpp"



char IvyLair::spaceMenu()
{
	subMenu.clearMenu();
	subMenu.add_choice("Head back to the Batcave to rethink your strategy.");
	subMenu.add_choice("Destroy Ivy's lab, including the helpless plants");
	subMenu.add_choice("Give Ivy a kiss. One kiss won't hurt");
	subMenu.add_choice("Fight Ivy, Batman style");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Villain Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");
	menuChoice = subMenu.makeChoice();

	if (menuChoice == 1)
		return 'U';
	else if (menuChoice == 2) {
		std::cout << "\nYou needlessly destroyed Ivy's lab and release plant toxins. You lost 15 strength.\n";
		IamBat->pain(35, 0);
		pause();
		return 'P';
	}
	else if (menuChoice == 3) {
		if (IamBat->search_items("Inoculation") && Villain->search_items("Plant toxin")) {
			std::cout << "\nYou have have been immunized to resist Ivy's charms, but don't play with fire too much.\n";
			Villain->transfer_qty("Plant toxin", IamBat);
			pause();
		}
		else if (IamBat->search_items("Inoculation") && !Villain->search_items("Plant toxin")) {
			std::cout << "\nYou pushed your luck and the Inoculation ran out. Wedding bells are in your future.\n";
			IamBat->pain(200, 0);
			pause();
		}
		else {
			std::cout << "\nYou don't have the Inoculation to resist Ivy's advances and lose 25 strength. \n";
			IamBat->pain(45, 0);
			if (!IamBat->defeated())
				std::cout << "Run back to the Batcave to escape before it's too late.\n";
			else
				std::cout << "You just couldn't take the hint, could you. All your strength is drained and the fun is over.\n";
			pause();
		}
		return 'K';
	}
	else if (menuChoice == 4) {
		std::string response = "";
		if (!IamBat->search_items("Inoculation")) {
			std::cout << "\nYou don't have anything to protect you from Ivy's Seduction. Are you sure you want to continue (Y/N)?\n";
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
		return 'F';
	}
	else if (menuChoice == 5)
		return 'I';
	else if (menuChoice == 6) {
		this->displayVillainInfo();
		pause();
		return 'H';
	}
	else
		return 'Q';
}

void IvyLair::displaySpaceInfo()
{
	std::cout << "\nA pleasant smelling Lair, much better than your damp Batcave. There are aromas all around and\n";
	std::cout << "the plants make you feel relaxed. There is a sense you could just let yourself go and be happy,\n";
	std::cout << "but you can never be happy. You are Batman!\n";
}

IvyLair::~IvyLair()
{
}
