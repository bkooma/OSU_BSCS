/**************************************************************************************
** RPSGame.cpp is the RPS Game class function implementation file.
** Authors:  Byron Kooima, Alexander Jennison, Polly Sobeck,
**           Dai Duong Nguyen, Zachary Bellone
** Date: 2017/07/30
** Description: CS162 Week5 Group10
** The RPSGame class represents an RPS Game where the human Tool is defined and the 
** computer Tool is randomly generated. The play function determines who won the current
** round and the print function displays the tallied results of all the rounds
****************************************************************************************/

#include "RPSGame.hpp"
#include <iostream>
#include <iomanip>
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"

// Default constructor for RPSGame. Initializes scoreboard values to 0.
RPSGame::RPSGame() : human_wins(0), computer_wins(0), ties(0)
{
}

/*********************************************************************************
** Function: 		RPSGame::setPlayerTool
** Description:		This function takes a user input choice of Tool type and 
**					creates the cooresponding Tool type for the human to play in 
**					the current round
** Parameters:		User input Tool type, case insensitive.
**					The strength of each tool, set to 1 unless the user chooses 
**					to input their own
** Pre-Conditions: 	human member must be empty or nullptr to avoid memory leak
** Post-Conditions: Human Tool object set and ready for play
**********************************************************************************/

void RPSGame::setPlayerTool(std::string toolType, int rStr, int pStr, int sStr)
{
	human = nullptr;
	// Create new Rock object
	if (toolType == "r" || toolType == "R")
		human = new Rock(rStr);
	// Create new Paper object
	else if (toolType == "p" || toolType == "P")
		human = new Paper(pStr);
	// Create new Scissors object
	else if (toolType == "s" || toolType == "S")
		human = new Scissors(sStr);
}

/*******************************************************************************
** Function: 		RPSGame::setComputerTool
** Description:		This function generates a random number to respresent the
					Computer's random choice of Tool type. The function corelates
					the random number to a Tool type and sets the Computer's Tool
					choice for the current turn.
** Parameters:		The strength of each tool, set to 1 unless the user chooses 
**					to input their own
** Pre-Conditions: 	computer member must be empty or nullptr to avoid memory leak 
** Post-Conditions: Random Computer Tool object set and ready for play
********************************************************************************/

void RPSGame::setComputerTool(int rStr, int pStr, int sStr)
{
	// Create a rand int from 1-3
	int computerTool = rand() % 3 + 1;

	// If the random int is 1, create a new Rock object
	if(computerTool == 1)
	{
		computer = new Rock(rStr);
		std::cout << "The computer chose Rock\n";
		std::cout << "With a strength of " << rStr << std::endl;
	}
	// If the random int is 2, create a new Paper object
	if (computerTool == 2)
	{
		computer = new Paper(pStr);
		std::cout << "The computer chose Paper\n";
		std::cout << "With a strength of " << pStr << std::endl;
	}
	// If the random int is 3, create a new Scissors object
	if(computerTool == 3)
	{
		computer = new Scissors(sStr);
		std::cout << "The computer chose Scissors\n";
		std::cout << "With a strength of " << sStr << std::endl;
	}
}

/*********************************************************************
** Function: 		RPSGame::play
** Description:		This function executes a round of the RPS game and
**					handles the result of the round.
** Parameters:		N/A
** Pre-Conditions: 	human and computer members must contain a Tool 
**					object
** Post-Conditions: The round is played and the appropriate scoreboard 
**					member is incremented
*********************************************************************/
void RPSGame::play()
{
	FightResult result;

	// The user Tool fights the computer Tool
	result = human->fight(computer);

	if(result == WIN)
	{
		std::cout << "You win!\n" << std::endl;
		human_wins++;
	}	
	else if(result == LOSE)
	{
		std::cout << "Computer wins! :-(\n" << std::endl;
		computer_wins++;
	}
	else
	{
		std::cout << "The round was a tie.\n" << std::endl;
		ties++;
	}
	delete human;
	delete computer;	
}

/*********************************************************************
** Function: 		RPSGame::print
** Description:		This function prints a formated output of the 
**					scoreboard memebers to the console.
** Parameters:		N/A
** Pre-Conditions: 	N/A
** Post-Conditions: N/A
*********************************************************************/
void RPSGame::print() {
	// Print the results of each round
	std::cout << std::left << std::setw(20) << "Human wins:" << std::setw(10) << this->human_wins << std::endl;
	std::cout << std::setw(20) << "Computer wins:" << std::setw(10) << this->computer_wins << std::endl;
	std::cout << std::setw(20) << "Ties:" << std::setw(10) << this->ties << std::endl;
}

// Destructor
RPSGame::~RPSGame() {
}
