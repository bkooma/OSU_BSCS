/****************************************************************************
* Author: Daniel Trierweiler
* Date: November 20th, 2016
* Description: Implementation for Creature class 
****************************************************************************/
#include "Creature.hpp"

/******************************************************************************
* Description: Default constructor that assigns the creature's data fields
* according to the passed arguments
*
* Update: Sets row and column position to 1 and direction to North 'w'
*******************************************************************************/
Creature::Creature(int passedAttackRoll, int passedAttackDie, int passedDefenseRoll, 
		   int passedDefenseDie, int passedArmor, int passedStrength, 
                   std::string passedName)
{
	attackRoll = passedAttackRoll;
	attackDie = passedAttackDie;
	defenseRoll = passedDefenseRoll;
	defenseDie = passedDefenseDie;
	armor = passedArmor;
	strength = passedStrength;
	name = passedName;
	dead = false;
	rowPosition = 1;
	columnPosition = 1;
	direction = 'w'; 

	srand(time(NULL));
}

/******************************************************************************
* Description: Method that returns the name of the creature as a string
******************************************************************************/
std::string Creature::getName()
{
	return name;
}

/******************************************************************************
* Description: Method that returns the row position of the creature as an int
******************************************************************************/
int Creature::getRowPosition()
{
	return rowPosition;
}

/******************************************************************************
* Description: Method that returns the column position of the creature as an int
******************************************************************************/
int Creature::getColumnPosition()
{
	return columnPosition;
}

/******************************************************************************
* Description: Method that returns the direction of the creature as an int
******************************************************************************/
char Creature::getDirection()
{
	return direction;
}

/******************************************************************************
* Description: Method that sets the row position according to the passed 
* argument
******************************************************************************/
void Creature::setRowPosition(int newRowPosition)
{
	rowPosition = newRowPosition;
}

/******************************************************************************
* Description: Method that sets the column position according to the passed 
* argument
******************************************************************************/
void Creature::setColumnPosition(int newColumnPosition)
{
	columnPosition = newColumnPosition;
}

/******************************************************************************
* Description: Method that sets the direction  according to the passed 
* argument
******************************************************************************/
void Creature::setDirection(char newDirection)
{
	direction = newDirection;
}

/******************************************************************************
* Description: Method that returns whether the not the creature is dead. True
* if the creature is dead, otherwise false
******************************************************************************/
bool Creature::isDead()
{
	return dead;
}

/****************************************************************************
* Description: method that returns an integer representing the sum of rolling
* the creatures die
****************************************************************************/
int Creature::rollDie(int passedRoll, int passedDie)
{
	int dieSum = 0;

	for (int i = 0; i < passedRoll; i++)
	{
		dieSum += rand() % passedDie + 1;
	}

	return dieSum;
}



