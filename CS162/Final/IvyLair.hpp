/******************************************************************************
** IvyLair.hpp is the IvyLair derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The IvyLair class represents a Space derived class. It inherits the
** variables from the Space base class. It also uses the virtual functions.
******************************************************************************/
#ifndef IVYLAIR_HPP
#define IVYLAIR_HPP

#include "Space.hpp"
class IvyLair :
	public Space
{
public:
	IvyLair(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	char spaceMenu();
	virtual void displaySpaceInfo();
	~IvyLair();
};

#endif