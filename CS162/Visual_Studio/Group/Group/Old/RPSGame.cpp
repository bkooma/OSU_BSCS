/**************************************************************************************
** RPSGame.cpp is the RPS Game class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/30
** Description: CS162 Week5 Group10
** The RPSGame class represents an RPS Game
****************************************************************************************/

#include "RPSGame.hpp"
#include <iostream>
#include <iomanip>
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"

// Deafault constructor for RPSGame
RPSGame::RPSGame()
{
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
}

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
	return;
}

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
	return;
}


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
		std::cout << "No winners this time.\n" << std::endl;
		ties++;
	}
	delete human;
	delete computer;	
}

void RPSGame::printScore() {
	// Print the results of each round
	std::cout << std::left << std::setw(20) << "Human wins:" << std::setw(10) << this->human_wins << std::endl;
	std::cout << std::setw(20) << "Computer wins:" << std::setw(10) << this->computer_wins << std::endl;
	std::cout << std::setw(20) << "Ties:" << std::setw(10) << this->ties << std::endl;
}

// Destructor
RPSGame::~RPSGame() {
}
