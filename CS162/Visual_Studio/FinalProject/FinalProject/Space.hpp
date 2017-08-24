/******************************************************************************
** Space.hpp is the Space Base class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Space class represents a Space Base Class for the batmanGame. This class
** is abstract with some pure virtual functions
******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include "Creature.hpp"
#include "userMenu.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

class Space
{
protected:
	// Initialize the directional Spaces
	Space* up;
	Space* right;
	Space* down;
	Space* left;

	userMenu subMenu;
	Creature* Villain = NULL;
	Creature* IamBat = NULL;
	bool specialItem;
	bool stunApplied = false;
	bool gasApplied = false;
	char menuChoice;
	std::string spaceName;
public:
	// Constructor for initializing a Space
	Space(std::string name, Creature* batman, Creature* vil);
	
	// Pure abstract functions
	// Display the Space specific Menu
	virtual char spaceMenu() = 0;
	// Display the Space specific Info
	virtual void displaySpaceInfo() = 0;
	// Display the Space specific ASCII txt map
	virtual void displaySpaceMap() = 0;

	// Display the Villain Info assigned to the current Space
	virtual void displayVillainInfo();
	// Generic function to return the Space's name
	std::string getSpaceName() {return spaceName;};

	// Default function for assigning the adjacent rooms to a passed-in Space.
	virtual void setAdjSpace(Space*, char);
	//Default function for moving from current Space to	adjacent Space.
	virtual Space* moveSpace(char);
	//Default function for waiting on user to push Enter
	virtual void pause();
	//Base level function to encompass all of the printed text and round status
	void printRound(Creature* pOffense, Creature* pDefense);
	//Plays a single match between two creatures and prints	the result of each round
	void playRound(Creature* pOffense, Creature* pDefense, int round, bool player);

	// Destructor
	virtual ~Space();

};
#endif
