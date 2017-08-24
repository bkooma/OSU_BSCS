/******************************************************************************
** Space.hpp is the Space Base class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** Description: Header file for the Space class.
******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include "Creature.hpp"
//#include "Batman.hpp"
#include "userMenu.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

class Space
{
protected:
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
	Space(std::string name, Creature* batman, Creature* vil);
	
	virtual char spaceMenu() = 0;
	virtual void displaySpaceInfo() = 0;
	
	virtual void displayVillainInfo();

	std::string getSpaceName() {return spaceName;};

	virtual void setAdjSpace(Space*, char);
	virtual Space* moveSpace(char);
	virtual void pause();

	void printRound(Creature* pOffense, Creature* pDefense);

	void playRound(Creature* pOffense, Creature* pDefense, int round, bool player);

	virtual ~Space();

};
#endif
