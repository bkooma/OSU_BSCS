/*******************************************************************************
* Author: Daniel Trierweiler
* Date: November 20th, 2016
* Description: Adaption from Assignment# 3. Made creature class abstract
* by making attack and defense virtual abstrac methods. 
*
* Update December 6th, 2016: Added row and column postion, and direction to 
* display the object on spaces in the final project. Deleted glare methods
* since Medusa is no longer involved in any fights between creatures
*******************************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <time.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <limits>

class Creature
{

protected:
	int attackRoll;
	int attackDie;
	int defenseRoll;
	int defenseDie;
	int strength;
	int armor;
	std::string name;
	int rowPosition;
	int columnPosition;
	char direction;
	int  damage;
	bool dead;

	int rollDie(int, int);

public:
	Creature(int, int, int, int, int, int, std::string);

	std::string getName();
	int getRowPosition();
	int getColumnPosition();
	char getDirection();
	void setRowPosition(int);
	void setColumnPosition(int);
	void setDirection(char);
	bool isDead();

	virtual int attack() = 0;
	virtual void defense(int) = 0;
};

#endif



