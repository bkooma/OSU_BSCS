/******************************************************************************
** BatCave.hpp is the BatCave derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The BatCave class represents a Space derived class. It inherits the
** variables from the Space base class. It also uses the virtual functions.
******************************************************************************/
#ifndef BATCAVE_HPP
#define BATCAVE_HPP

#include "Space.hpp"
#include "Batman.hpp"

class BatCave : public Space
{
public:
	BatCave(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	char spaceMenu();
	virtual void displaySpaceInfo();
	~BatCave();
};
#endif