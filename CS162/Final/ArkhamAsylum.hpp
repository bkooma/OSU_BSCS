/******************************************************************************
** ArkhamAsylum.hpp is the ArkhamAsylum derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The ArkhamAsylum class represents a Space derived class. It inherits the
** variables from the Space base class. It also uses the virtual functions.
******************************************************************************/
#ifndef ARKHAMASYLUM_HPP
#define ARKHAMASYLUM_HPP

#include "Space.hpp"
#include "ArkhamAsylum.hpp"

class ArkhamAsylum : public Space
{
public:
	ArkhamAsylum(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	char spaceMenu();
	virtual void displaySpaceInfo();
	~ArkhamAsylum();
};
#endif