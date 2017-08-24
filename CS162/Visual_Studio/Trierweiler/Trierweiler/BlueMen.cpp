/*******************************************************************************
* Author: Daniel Trierweiler
* Date: November 20th, 2016
* Description: Implementation for the BlueMen class
*
* Update December 6th, 2016: Updates noted in BlueMen.hpp and Creature class
*******************************************************************************/
#include "BlueMen.hpp"

/*******************************************************************************
* Description: Default constructor that calls upon the parent class to
* initialize the BlueMen's data fields
*
* Update: Direction defaul is set to North 'w', reduceBlueMen is set to 2 since
* there is 1 BlueMen to start, and ItemIndex is 0 since the BlueMen start with
* no items
*******************************************************************************/
BlueMen::BlueMen(int passedAttackRoll, int passedAttackDie, int passedDefenseRoll,
	         int passedDefenseDie, int passedArmor, int passedStrength,
                 std::string passedName)
	:Creature(passedAttackRoll, passedAttackDie, passedDefenseRoll, 
                  passedDefenseDie, passedArmor, passedStrength, passedName)
{
	direction = 'w';
	reduceBlueMen = 2;
	itemIndex = 0;
}

/*******************************************************************************
* Description: Method that returns true if the BlueMen have the dungeon key,
* otherwise, returns false
*******************************************************************************/
bool  BlueMen::hasKey()
{
	for (int i = 0; i < itemIndex; i++)
	{
		if (items[i] == 'K')
		{
			return true;
		}
	}
	return false;
}

/*******************************************************************************
* Description: Method that returns true if the BlueMen have collected any fellow
* BlueMen from the dungeon otherwise, returns false
*******************************************************************************/
int BlueMen::hasBlueMen()
{
	int count = 0;
	for (int i = 0; i < itemIndex; i++)
	{
		if (items[i] == 'B')
		{
			count++;
		}
	}
	return count;
}

/****************************************************************************
* Description: Method that add a collected item to the BlueMen's items
****************************************************************************/
void BlueMen::addItem(char newItem)
{
	//no more room for items
	if (itemIndex >  2)
	{
		std::cout << "You have no more room for items" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		//if found item is a BlueMen increase the amount of BlueMen
		if(reduceBlueMen != 0 && newItem == 'B')
		{
			reduceBlueMen--;
			defenseRoll++;
			strength += 4;
		}
		//adding item to BlueMen's items
		items[itemIndex] = newItem;
		itemIndex++;
	}
}

/****************************************************************************
* Description: Method that shows the BlueMen's items
****************************************************************************/
void BlueMen::showItems()
{
	if (hasBlueMen() == 0 && hasKey()  == false)
	{
		std::cout << "You have collected no items" << std::endl;
	}
	else
	{
		std::cout << "Current Items: " << std::endl;
		if (hasKey()  == true)
		{
			std::cout << "Dungeon key" << std::endl;
		}
		if (hasBlueMen() != 0)
		{
			std::cout << hasBlueMen() << " BlueMen" << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Press enter to continue....";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

/*******************************************************************************
* Description: methods that returns the sum of rolling the attack die as an
* integer
*******************************************************************************/
int BlueMen::attack()
{ 
	int attack = rollDie(attackRoll, attackDie);
	std::cout << name << " attacks with a power of " << attack << std::endl;
	return attack;
}

/******************************************************************************
* Description: Method that defends against an incoming at by rolling the
* defense die. If the sum of the defense die is greater than the incoming
* attack the attack was successfully defended. A single BlueMen is lost
* for every 4 points of daamage taken.
*******************************************************************************/
void BlueMen::defense(int passedAttack)
{
	int defense = armor + rollDie(defenseRoll, defenseDie);
	std::cout << name << " defends with a power of " << defense << std::endl;

	passedAttack -= defense;
	if (passedAttack > 0)
	{
		strength -= passedAttack;
		std::cout << name << " has taken " << passedAttack << " damage" 
                          << std::endl;
		if (strength <= 0)
		{
			strength = 0;
			dead = true;
			std::cout << std::endl;
			std::cout << name << " has no strength left. ";                       
			std::cout << " The battle is over" << std::endl;
		}
		else
		{
			std::cout << name << " has " << strength << " strength left" 
                                  << std::endl;
		}
	}
	else
	{
		std::cout << name << " has successfully defended the attack" 
                          << std::endl;
	}

	std::cout << std::endl;
	
	if (dead == false)
	{
		reduceDie();
	}

}

/*******************************************************************************
* Description: Method that reduces BlueMen according to their strength. A 
* single BlueMen is lost for every 4 points of damage
*******************************************************************************/
void BlueMen::reduceDie()
{
	if (strength <= 8 && strength > 4)
	{
		if (reduceBlueMen == 0)
		{
			std::cout << "A " << name << " has died, there are two ";
                        std::cout << " Bluemen left" << std::endl;
			std::cout << std::endl;
			defenseRoll--;
			reduceBlueMen++;
		} 
	}

	if (strength <= 4)
	{
		if (reduceBlueMen == 1)
		{
			std::cout << "A " << name << " has died, there is one "; 
                        std::cout << "Bluemen left" << std::endl;
			std::cout << std::endl;
			defenseRoll--;
			reduceBlueMen++;
		}
		if (reduceBlueMen == 0)
		{
			std::cout << "Two " << name << " have died, there is one ";
                        std::cout << "Bluemen left" << std::endl;
			std::cout << std::endl;
			defenseRoll--;
			reduceBlueMen += 2;
		}
	}
}




