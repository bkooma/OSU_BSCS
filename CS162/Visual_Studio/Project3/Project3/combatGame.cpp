/*************************************************************************************
** Program name: combatGame.cpp is the Fantasy Combat Game implementation file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week6 Project3
** The Main program allows the user to select a menu option to pit two Creatures against
** eachother in a combat simulator. The user can select any two Creatures for the a 
** single match. There is also an option to run the Test Harness where every combination
** of Creature matches is tested.
***************************************************************************************/
#include "userMenu.hpp"
#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>

// Function prototypes for the main combat game
// Function for the test harness to test all combinations of Creatures
void randomCombat();
// Play a single game between two creatures
void playRound(Creature* pOffense, Creature* pDefense, int round, bool player);
// Duplicate printing statements to use in game output
void printRound(Creature* pOffense, Creature* pDefense);

int main() 
{
	// Seed the random generator
	std::srand(static_cast<unsigned int>(time(0)));

	// Create two Creature objects
	Creature* O1 = nullptr;
	Creature* O2 = nullptr;

	// Set up the userMenu classes
	userMenu mainMenu;
	int mainChoice = 0;
	userMenu combatMenu;
	int combatChoice = 0;
	
	// Seed the main menu vector with selections
	mainMenu.add_choice("Run the Game Simulator");
	mainMenu.add_choice("Test Harness:: Play Round Robin with All of the Creatures");
	mainMenu.add_choice("Exit the Game");

	// Seed the Creature combat menu with options
	combatMenu.add_choice("Vampire\t\t1d12\t\t1d6(Charm)\t1\t18");
	combatMenu.add_choice("Barbarian\t\t2d6\t\t2d6\t\t0\t12");
	combatMenu.add_choice("Blue Men\t\t2d10\t\t3d6\t\t3\t12(Mob)");
	combatMenu.add_choice("Medusa\t\t2d6(Glare)\t1d6\t\t3\t8");
	combatMenu.add_choice("Harry Potter\t2d6\t\t2d6\t\t0\t10/20(Hogwarts)");
	
	std::cout << "Welcome to the Fantasy Combat Simulator\n";
	mainChoice = mainMenu.makeChoice();

	// While the user doesn't exit the game
	while (mainChoice != 3) {
		// User will select two Creatures to fight a single round of play
		if (mainChoice == 1) {
			// Clear out Creatuer objects in case this is a subsequent round
			delete O1;
			O1 = nullptr;
			delete O2;
			O2 = nullptr;

			// String variable to concatinate multiple strings to help with cout statements
			std::string p1Round;
			std::string p2Round;

			// Sub menu to allow the user to select the Creature player 1 will start with (O1)
			std::cout << "Please select Player 1's Creature Type\n";
			std::cout << "Creature Type\t\tAttack\t\tDefense\t\tArmor\tStrength Points\n";
			combatChoice = combatMenu.makeChoice();
			if (combatChoice == 1)
				O1 = new Vampire();
			else if (combatChoice == 2)
				O1 = new Barbarian();
			else if (combatChoice == 3)
				O1 = new BlueMen();
			else if (combatChoice == 4)
				O1 = new Medusa();
			else if (combatChoice == 5)
				O1 = new HarryPotter();

			std::cout << "\nPlayer 1 is ready to fight with " << O1->get_name() << ". Good Luck!\n\n";
		
			// Sub menu to allow the user to select the Creature player 2 will start with (O2)
			std::cout << "Please select Player 2's Creature Type\n";
			std::cout << "Creature Type\t\tAttack\t\tDefense\t\tArmor\tStrength Points\n";
			combatChoice = combatMenu.makeChoice();
			if (combatChoice == 1)
				O2 = new Vampire();
			else if (combatChoice == 2)
				O2 = new Barbarian();
			else if (combatChoice == 3)
				O2 = new BlueMen();
			else if (combatChoice == 4)
				O2 = new Medusa();
			else if (combatChoice == 5)
				O2 = new HarryPotter();

			std::cout << "\nPlayer 2 is ready to fight with " << O2->get_name() << ". Good Luck!\n\n";

			std::cout << "Let's get ready to Rumble!\n";

			// Prints all the rounds of play in a single game
			printRound(O1, O2);

			// Recover the strength of the Creatures
			O1->recover_strength();
			O2->recover_strength();
		}

		// Option to use the test harness to test all combinations of Creature combat
		else if (mainChoice == 2) {
			randomCombat();
		}

		// Prompt the user for menu option again
		mainChoice = mainMenu.makeChoice();
	}
	// Delete the Creature objects
	delete O1;
	delete O2;
}

/*********************************************************************
** Function: randomCombat
** Description: Test Harness function to test all the combinations
**				of Creature battles
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: All 25 rounds of creature combinations will be 
**					executed.
*********************************************************************/
void randomCombat()
{
	// Variable to set the number of Creatures to battle
	int numCreatures = 5;
	int matches = 0;
	std::string p1Round;
	std::string p2Round;

	// Create a vector of Creatures to step through two loops
	std::vector<Creature*> set1;
	std::vector<Creature*> set2;

	// Populate the first vector with all of the Creatures
	set1.push_back(new Vampire());
	set1.push_back(new Barbarian());
	set1.push_back(new BlueMen());
	set1.push_back(new Medusa());
	set1.push_back(new HarryPotter());

	// Populate the second vector with all of the Creatures
	set2.push_back(new Vampire());
	set2.push_back(new Barbarian());
	set2.push_back(new BlueMen());
	set2.push_back(new Medusa());
	set2.push_back(new HarryPotter());

	// Loop through both vectors to test all combinations of Creature battles
	for (int i = 0; i < numCreatures; i++) {
		for (int j = 0; j < numCreatures; j++) {
			// Set Creatures to current vector pairs
			Creature* O1 = set1[j];
			Creature* O2 = set2[i];

			std::cout << "Let's get ready to Rumble!\n";
			// Function to play a single round and print the output
			printRound(O1, O2);

			// Recover the strength of the two Creatures 
			O1->recover_strength();
			O2->recover_strength();
			// Counter for the number of matches played
			matches++;
		}
	}

	// Let the user know how many matches were run
	std::cout << "There were " << matches << " mathces played during the tournament.\n";

	// Delete the Creatures out of the vector
	for (size_t i = 0; i < set1.size(); i++) {
		delete set1[i];
	}
	for (size_t j = 0; j < set2.size(); j++) {
		delete set2[j];
	}
}

/*********************************************************************
** Function: playRound(Creature*, Creature*, int, bool)
** Description: Plays a single match between two creatures and prints
**				the result of each round
** Parameters:	pOffense		Current Creature attacking
				pDefense		Current Creature defending
				round			Pass in initialized round for 
								recursive loop
				pStart			bool to determine which random player
								was selected to start the game
** Pre-Conditions: N/A
** Post-Conditions: The match plays out between two creatures with
**					the output of each round displayed to the prompt
*********************************************************************/
void playRound(Creature * pOffense, Creature * pDefense, int round, bool pStart)
{
	std::string p1Round;
	std::string p2Round;
	std::string pOff;
	std::string pDef;

	// Recursive function to continue attacks until one of the Creatures is defeated
	while (!pOffense->defeated() && !pDefense->defeated()) {
		int damage = 0;
		int defenseRoll;
		// Roll die for the attack
		int offenseRoll = pOffense->attack_roll();

		// Check if Medusa used GLARE in the attack
		if (pOffense->get_special() == "GLARE") {
			// Set Medusa's attack strength equal to the remaining strength of defender plus total defense
			offenseRoll = 100;
//			defenseRoll = pDefense->defense_roll(offenseRoll);
		}

		// Roll die for the defense
		defenseRoll = pDefense->defense_roll(offenseRoll);

		// Set player strings based on who was randomly selected to start
		if (!pStart) {
			pOff = "O1: ";
			pDef = "O2: ";
		}
		else {
			pOff = "O2: ";
			pDef = "O1: ";
		}

		// For every odd round, set up the output statements
		if (round % 2 == 1) {
			p1Round = "Attack:  ";
			// Determine if any offensive specials were used and output to screen 
			if (pOffense->get_special() != "") {
				p1Round = p1Round + "(" + pOffense->get_special() + ")";
			}
			// If no specials were used, print the strength of the offense roll
			else {
				p1Round = p1Round + std::to_string(offenseRoll);
			}

			p2Round = "|  Defense: ";
			// Determine if any defensive specials were used and output to screen
			if (pDefense->get_special() != "") {
				p2Round = p2Round + "(" + pDefense->get_special() + ")";
			}
			// If no specials were used, print the strength of the defensive roll + armor
			else {
				p2Round = p2Round + std::to_string(pDefense->get_defPoints()) + " + armor: " + std::to_string(pDefense->get_armor());
			}

			// Format the output for each round
			std::cout << std::setw(10) << round << std::setw(33) << p1Round << std::setw(33) << p2Round;
			std::cout << std::setw(5) << pDef + "-" << std::setw(5) << defenseRoll;
			std::cout << std::setw(5) << pDef << std::setw(5) << pDefense->get_strength() << std::endl;
		}

		// For every odd round, set up the output statements
		if (round % 2 == 0) {
			p1Round = "Defense:  ";
			// Determine if any defensive specials were used and output to screen
			if (pDefense->get_special() != "") {
				p1Round = p1Round + "(" + pDefense->get_special() + ")";
			}
			// If no specials were used, print the strength of the defensive roll + armor
			else {
				p1Round = p1Round + std::to_string(pDefense->get_defPoints()) + " + armor: " + std::to_string(pDefense->get_armor());
			}
			// Determine if any offensive specials were used and output to screen
			p2Round = "|  Attack: ";
			if (pOffense->get_special() != "") {
				p2Round = p2Round + "(" + pOffense->get_special() + ")";
			}
			// If no specials were used, print the strength of the offense roll
			else {
				p2Round = p2Round + std::to_string(offenseRoll);
			}

			// Format the output for each round
			std::cout << std::setw(10) << round << std::setw(33) << p1Round << std::setw(33) << p2Round;
			std::cout << std::setw(5) << pDef + "-" << std::setw(5) << defenseRoll;
			std::cout << std::setw(5) << pDef << std::setw(5) << pDefense->get_strength() << std::endl << std::endl;
		}
		// Increment the round counter
		round++;
		// Determine if the opponent is defeated
		if (!pDefense->defeated()) {
			// If not defeated set boolean to opposite player (p1 true or false)
			pStart = !pStart;
			// Recursive function call to pass the opposite players to the function
			playRound(pDefense, pOffense, round, pStart);
		}

	}
}

/*********************************************************************
** Function: printRound(Creature*, Creature*)
** Description: Base level function to encompass all of the printed
**				text and round status
** Parameters:	O1		Player 1 selected Creature
				O2		Player 2 selected Creature
** Pre-Conditions: N/A
** Post-Conditions: The match plays out between two creatures with
**					the output of each match displayed to the prompt
*********************************************************************/
void printRound(Creature * O1, Creature * O2)
{
	std::string p1Round;
	std::string p2Round;
//	int O1Wins = 0;
//	int O2Wins = 0;
	int round = 1;
	bool pStart;

	// See which player gets to start.
	pStart = (rand() % 2);

	// Set up the string with the name of the Creature and its starting strength
	p1Round = O1->get_name() + " (STR: " + std::to_string(O1->get_strength()) + ")";
	p2Round = O2->get_name() + " (STR: " + std::to_string(O2->get_strength()) + ")";

	// If player 1 gets to start
	if (!pStart) {
		std::cout << "Player 1 (O1) Will Start the Combat Game\n";
		std::cout << std::string(95, '-') << std::endl;

		// Set the format of the output
		std::cout << std::left << std::setw(10) << "Roll #";
		std::cout << std::setw(5) << "O1: " << std::setw(28) << p1Round;
		std::cout << std::setw(8) << "|  O2: " << std::setw(25) << p2Round;
		std::cout << std::setw(10) << "Damage" << std::setw(10) << "Strength" << std::endl;

		// Play the match for the two Creatures
		playRound(O1, O2, round, pStart);

		// Print out the final strengths of the two Creatures
		std::cout << std::string(95, '-') << std::endl;
		std::cout << std::setw(10) << "" << std::setw(20) << "O1 Final Strength Pts: " << std::setw(10) << O1->get_strength();
		std::cout << std::setw(20) << "|  O2 Final Strength Pts: " << std::setw(10) << O2->get_strength() << std::endl << std::endl;
	}
	// If player 2 gets to start
	else if (pStart) {
		std::cout << "Player 2 (O2) Will Start the Combat Game\n";
		std::cout << std::string(95, '-') << std::endl;

		// Set the format of the output
		std::cout << std::left << std::setw(10) << "Roll #";
		std::cout << std::setw(5) << "O2: " << std::setw(28) << p2Round;
		std::cout << std::setw(8) << "|  O1: " << std::setw(25) << p1Round;
		std::cout << std::setw(10) << "Damage" << std::setw(10) << "Strength" << std::endl;

		// Play the match for the two Creatures
		playRound(O2, O1, round, pStart);

		// Print out the final strengths of the two Creatures
		std::cout << std::string(95, '-') << std::endl;
		std::cout << std::setw(10) << "" << std::setw(20) << "O2 Final Strength Pts: " << std::setw(10) << O2->get_strength();
		std::cout << std::setw(20) << "|  O1 Final Strength Pts: " << std::setw(10) << O1->get_strength() << std::endl << std::endl;
	}

	// Print out who wins the match
	std::cout << std::string(95, '=') << std::endl;
	if (O1->defeated()) {
		std::cout << "Player2's " << O2->get_name() << " is the winner!\n\n";
	}
	else if (O2->defeated()) {
		std::cout << "Player1's " << O1->get_name() << " is the winner!\n\n";
	}
}
