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

// Basic constructor for RPSGame class
RPSGame::RPSGame()
{
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
}

// Deconstructor for RPSGame class
RPSGame::~RPSGame() {
	std::cout << "In the destructor.\n";
}


void RPSGame::setComputerTool(int rStr, int pStr, int sStr)
{
	int c = rand() % 3 + 1;

	if(c == 1)
	{
		computer = new Rock(rStr);
		std::cout << "The computer chose Rock\n";
		std::cout << "With a strength of " << rStr << std::endl;
	}
	if(c == 2)
	{
		computer = new Paper(pStr);
		std::cout << "The computer chose Paper\n";
		std::cout << "With a strength of " << pStr << std::endl;
	}	
	if(c == 3)
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
	if (toolType == "r" || toolType == "R") {
		human = new Rock(rStr);
	}
	else if (toolType == "p" || toolType == "P") {
		human = new Paper(pStr);
	}
	else if (toolType == "s" || toolType == "S") {
		human = new Scissors(sStr);
	}
	return;
}


void RPSGame::play()
{
	FightResult result;

	result = human->fight(computer);

	if(result == WIN)
	{
		std::cout << "Human wins!\n" << std::endl;
		human_wins++;
	}	
	else if(result == LOSE)
	{
		std::cout << "Computer wins!\n" << std::endl;
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

	std::cout << std::left << std::setw(20) << "Human Wins:" << std::setw(10) << this->human_wins << std::endl;
	std::cout << std::setw(20) << "Computer Wins:" << std::setw(10) << this->computer_wins << std::endl;
	std::cout << std::setw(20) << "Ties:" << std::setw(10) << this->ties << std::endl;

}
