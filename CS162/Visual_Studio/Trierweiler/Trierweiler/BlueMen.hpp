/*******************************************************************************
* Author: Daniel Trierweiler
* Date: November 20th, 2016
* Description: BlueMen clas that inherits from the parent class Creature. 
* BlueMen defines the virtual abstract functions attack and defense. BlueMen
* are a unit of 3, and will die for every 4 points of damage. For every 
* one that dies a correspondoing defense die is lost  
*
* Update December 6th, 2016: Added item (char array of size 3) to add items
* that are found in spaces for the Final Project. Item index is used to keep
* track of the arrays index 
*******************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"
class BlueMen : public Creature
{
private:
	int reduceBlueMen;
	char items[3];
	int itemIndex;

public:
	BlueMen(int, int, int, int, int, int, std::string);
	
	void addItem(char);
	bool hasKey();
	
	int  hasBlueMen();
	void showItems();
	virtual int attack();
	virtual void defense(int passedAttack);
	void reduceDie();
};

#endif

