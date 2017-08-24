/*******************************************************************************
* Author: Daniel Trierweiler
* Date: November 20th, 2016
* Description: Implementation for the vampire class
*
* Update December 6th, 2016: Updates noted in Creature class
*******************************************************************************/
#include "Vampire.hpp"

/*******************************************************************************
* Description: Default constructor that calls upon the parent class to 
* initialize the vampire's data fields
*******************************************************************************/
Vampire::Vampire(int passedAttackRoll, int passedAttackDie, int passedDefenseRoll,
		 int passedDefenseDie, int passedStrength, int passedArmor, 
                 std::string passedName)
	:Creature(passedAttackRoll, passedAttackDie, passedDefenseRoll, passedDefenseDie, 
	          passedStrength, passedArmor, passedName)
{
}

/*******************************************************************************
* Description: methods that returns the sum of rolling the attack die as an 
* integer
*******************************************************************************/
int Vampire::attack()
{
	int attack = rollDie(attackRoll, attackDie);
	std::cout << name << " attacks with a power of " << attack 
                  << std::endl;
	return attack;
}

/*******************************************************************************
* Description: Method that defends against an incoming at by rolling the
* defense die. If the sum of the defense die is greater than te incoming
* attack, the attack was successfully defended. Vampire has a 50% chance of
* casting charm, which will negate any attack
*******************************************************************************/
void Vampire::defense(int passedAttack)
{

	if (rand() % 2 != 0)
	{
		int defense = armor + rollDie(defenseRoll, defenseDie);
		std::cout << name << " defends with a power of " << defense 
                          << std::endl;
		passedAttack -= defense;
		if (passedAttack > 0)
		{
			strength -= passedAttack;
			std::cout << name << " has taken " << passedAttack 
                                  << " damage" << std::endl;
			if (strength <= 0)
			{
				strength = 0;
				dead = true;
				std::cout << std::endl;
				std::cout << name << " has no strength left. "; 
                		std::cout << "The battle is over" << std::endl;
			}
			else
			{
				std::cout << name << " has " << strength 
                                          << " strength left" << std::endl;
			}
		}
		else
		{
			std::cout << name << " has successfully defended the attack" 
                                  << std::endl;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << name << " invokes charm, the attack is ineffective." 
                          << std::endl;
		std::cout << std::endl;
	}
}


