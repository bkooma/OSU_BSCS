/**************************************************************************************
** RPSGame.hpp is the RPS Game class specification file.
** Authors:  Byron Kooima, Alexander Jennison, Polly Sobeck,
**           Dai Duong Nguyen, Zachary Bellone
** Date: 2017/07/30
** Description: CS162 Week5 Group10
** The RPSGame class represents an RPS Game where the human Tool is defined and the
** computer Tool is randomly generated. The play function determines who won the current
** round and the print function displays the tallied results of all the rounds
****************************************************************************************/

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include <string>
#include "Tool.hpp"

class RPSGame {
protected:
	// Define the parameters
	Tool *human = nullptr;
	Tool *computer = nullptr;
	int human_wins;
	int computer_wins;	
	int ties;		

public:
	// Default constructor
	RPSGame();

	// Function to determine the winner of human/computer selected tools
	void play();
	// Establishes the computer tool through a random int (1-3)
	void setComputerTool(int rStr, int pStr, int sStr);
	// Set the player Tool based on user input
	void setPlayerTool(std::string toolType, int rStr, int pStr, int sStr);
	// Print the status of the rounds of RPS play
	void print();

	// Destructor
	~RPSGame();
};

#endif
