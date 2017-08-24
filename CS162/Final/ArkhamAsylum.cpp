#include "ArkhamAsylum.hpp"

char ArkhamAsylum::spaceMenu()
{
	subMenu.clearMenu();
	subMenu.add_choice("Head back to the Batcave to rethink your strategy.");
	subMenu.add_choice("Steal Fear Gas from Scarecrow's stash");
	subMenu.add_choice("Fight fire with fire. Release plant toxin");
	subMenu.add_choice("Fight Scarecrow, Batman style");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Villain Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");
	menuChoice = subMenu.makeChoice();

	if (menuChoice == 1)
		return 'L';
	else if (menuChoice == 2) {
		if (IamBat->search_items("Batarang") && Villain->search_items("Fear Gas")) {
			std::cout << "\nYou use the Batarang to fit under the locked door. As any good Batarang does, \n";
			std::cout << "it brings the Scarecrow's Fear Gas back to you\n";
			Villain->transfer_qty("Fear Gas", IamBat);
			pause();
		}
		else if (IamBat->search_items("Batarang") && !Villain->search_items("Fear Gas")) {
			std::cout << "\nThere is nothing to retrieve from Scarecrow's office and the Batarang comes \n";
			std::cout << "back empty. Bad Batarang, bad!\n";
			pause();
		}
		else {
			std::cout << "\nScarecrow's stash is locked in his office. The space under the door might just be\n";
			std::cout << "big enough to fit a curved metal object that can retrieve things.\n";
			pause();
		}
		return 'S';
	}
	else if (menuChoice == 3) {
		if (IamBat->search_items("Plant toxin") && Villain->search_items("Batarang")) {
			std::cout << "\nYou use Ivy's plant toxin and Scarecrow is temporarily stunned and drops a curved metal object.\n";
			std::cout << "You pick up the object that looks kind-of like a bat so it must be a Batarang.\n";
			Villain->transfer_qty("Batarang", IamBat);
			pause();
		}
		else if (IamBat->search_items("Plant toxin") && !Villain->search_items("Batarang")) {
			std::cout << "\nScarecrow has developed an immunity to Ivy's toxin. It has no effect.\n";
			pause();
		}
		else {
			std::cout << "\nYou don't have any toxin in your Utility Belt. Maybe you should find someone that might dabble with plant toxins\n";
			pause();
		}
		return 'T';
	}
	else if (menuChoice == 4)
		return 'F';
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

void ArkhamAsylum::displaySpaceInfo()
{
	std::cout << "\nArkham Asylum is filled with all sorts of crazy Batman villains. Every criminal Batman faces\n";
	std::cout << "has spent a stint in Arkham's finest institution. There seems to be a heightened level of fear in \n";
	std::cout << "these ominous halls as of late.\n";
}

ArkhamAsylum::~ArkhamAsylum(){

}
