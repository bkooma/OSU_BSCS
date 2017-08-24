#include "Warehouse.hpp"



char Warehouse::spaceMenu()
{
	subMenu.clearMenu();
	subMenu.add_choice("Head back to the Batcave to rethink your strategy.");
	subMenu.add_choice("Play the Riddler's game");
	subMenu.add_choice("Suspend Riddler from the rafters");
	subMenu.add_choice("Fight Riddler, Batman style");
	subMenu.add_choice("Manage Utility Belt items");
	subMenu.add_choice("Villain Profile (hints)");
	subMenu.add_choice("Finish the Game (because Batman never quits)");
	menuChoice = subMenu.makeChoice();

	if (menuChoice == 1)
		return 'R';
	else if (menuChoice == 2) {
		int randomNum = 0;
		int answer = 0;
		bool correctAnswer = false;
		std::string varString = "That isn't even a number. You truly are intellectually superior to me.\n";

		std::cout << "\nI have put together some children's number riddles just for you Batman to test your puny Bat brain.\n";
		std::cout << "Riddle me this Batman: \n";
		randomNum = rand() % 3 + 1;

		if (randomNum == 1) {
			std::cout << "If two's company and three's a crowd, what are four and five?\n";
			SafeInput <int>(answer,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
			}, varString);
			if (answer == 9)
				correctAnswer = true;
		}
		else if (randomNum == 2) {
			std::cout << "If there are four apples and you take away three, how many do you have?\n";
			SafeInput <int>(answer,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
			}, varString);
			if (answer == 3)
				correctAnswer = true;
		}
		else if (randomNum == 3) {
			std::cout << "How many eggs can you put in an empty basket?\n";
			SafeInput <int>(answer,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0));
			}, varString);
			if (answer == 1)
				correctAnswer = true;
		}

		if (correctAnswer && Villain->search_items("Inoculation")) {
			std::cout << "Great job Batman. You are smarter than a five year old.\n";
			Villain->transfer_qty("Inoculation", IamBat);
			pause();
		}
		else if (correctAnswer && !Villain->search_items("Inoculation")) {
			std::cout << "While you proved you are smarter than a five your old, there is nothing to award you with.\n";
			std::cout << "Great job wasting one of your moves to answer a brain-less riddle.\n";
			pause();
		}
		else {
			std::cout << "WRONG WRONG WRONG!!! Did you even try? Defeating you will be easier than taking candy\n";
			std::cout << "from a baby. Especially since you are as smart as one.\n";
			std::cout << "Answering the question wrong causes mental and physical pain. You lose 10 strength.\n";
			IamBat->pain(30, 0);
			pause();
		}
		return 'G';
	}
	else if (menuChoice == 3) {
		if (IamBat->search_items("Grapple Gun") && Villain->search_items("Antidote")) {
			std::cout << "\nYou suspend Riddler from the rafters and he screams to let him down.\n";
			std::cout << "He promises to give you something to combat Fear Gas if you let him down.\n";
			Villain->transfer_qty("Antidote", IamBat);
			pause();
		}
		else if (IamBat->search_items("Grapple Gun") && !Villain->search_items("Antidote")) {
			std::cout << "\nYou suspend Riddler from the rafters but has nothing to offer.\n";
			pause();
		}
		else {
			std::cout << "\nYou don't have the proper tool to suspend Riddler from the rafters.\n";
			std::cout << "Riddler hits you with his question mark cane. It is a piddly blow but you lose 10 strength.\n";
			IamBat->pain(30, 0);
			pause();
		}
		return 'S';
	}
	else if (menuChoice == 4) {
		printRound(IamBat, Villain);
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

void Warehouse::displaySpaceInfo()
{
	std::cout << "\nYou can't see much in this maze of a building. There are question marks scattered all around.\n";
	std::cout << "Nothing annoys Batman more than a dark abandoned place with rodents that come out at night.\n";
	std::cout << "What really makes Batman angry though is the incessant questioning by the headless voice.\n";
}

Warehouse::~Warehouse()
{
}
