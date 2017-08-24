/******************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: Implementation for the BossRoom  class
******************************************************************************/
#include "BossRoom.hpp"

/******************************************************************************
* Description: Default constructor that passed all necessary atrributes to the
* base class constructor. Adjusts the canEnter state passed on the passed
* argument. The Vampire object is what the BlueMen will fight. Its values
* have been changed so that 1 BlueMen will unlikely win,  2 BlueMen might win,
* and 3 BlueMen are more than likely to win.
******************************************************************************/
BossRoom::BossRoom(Space* passedNorthSpace, Space* passedEastSpace, 
                   Space* passedSouthSpace, Space* passedWestSpace,
	           int passedNumRows, int passedNumColumns, 
                   char passedSpecialCharacter, std::string passedSpaceName,
	           BlueMen* passedBlueMen, bool passedCanEnter)
	 :Space(passedNorthSpace, passedEastSpace, passedSouthSpace, 
                passedWestSpace,passedNumRows, passedNumColumns, 
                passedSpecialCharacter, passedSpaceName, passedBlueMen)
{
	canEnter = passedCanEnter;
	Dracula = new Vampire(2, 8, 2, 6, 1, 18, "Dracula");
	createGrid();
}

/******************************************************************************
* Description: Default destructor that deletes dynamically allocated memory
******************************************************************************/
BossRoom::~BossRoom()
{
	delete Dracula;
	Dracula = NULL;
}

/******************************************************************************
* Description: Method that displays the spaces hint
******************************************************************************/
void BossRoom::hint()
{
	std::cout << "Room Hint: " << std::endl;
	std::cout << "Press enter to fight Dracula 'D'"  << std::endl;
	std::cout << "Defeat Dracula to escape the dungeon" << std::endl;
	std::cout << "Remember you are stronger with all of your fellow BlueMen!" 
                  << std::endl;
	std::cout << std::endl;
	std::cout << "Press enter continue....";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/******************************************************************************
* Description: Method that creates the space by filling the 2D char array
******************************************************************************/
void BossRoom::createGrid()
{
	//adding the space bounds and filling the rest with ' ' spaces
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			if (row == 0 || row == numRows - 1)
			{
				grid[row][column] = '-';
			}
			else if (column == 0 || column == numColumns - 1)
			{
				grid[row][column] = '|';
			}
			else
			{
				grid[row][column] = ' ';
			}
		}
	}

	//adding doors that lead to other spaces
	if (northSpace != NULL)
	{
		grid[0][numColumns / 2] = ' ';
	}
	if (eastSpace != NULL)
	{
		grid[numRows / 2][numColumns - 1] = ' ';

	}
	if (southSpace != NULL)
	{
		grid[numRows - 1][numColumns / 2] = ' ';
	}
	if (westSpace != NULL)
	{
		grid[numRows / 2][0] = ' ';
	}

	//adding the special character needed to change space state
	grid[numRows / 2][numColumns / 2] = specialCharacter;
}

/******************************************************************************
* Description: Method that changes the spaces state. If the player is next to
* the specialCharacter and presses the enter key, the state of the space
* changes if it has not been changed already. In the BossRoom the BlueMen
* fight the Vampire Creature using the algorithm from assignment 3 and 4
******************************************************************************/
void BossRoom::changingState(char input)
{
	int blueMenRow = Bluemen->getRowPosition();
	int blueMenColumn = Bluemen->getColumnPosition();
	char blueMenDirection = Bluemen->getDirection();
	
	//added condition to avoid segmentation fault from proceeding if
	if (blueMenRow != 0 &&  blueMenRow != numRows - 1 &&
	    blueMenColumn != 0 && blueMenColumn != numColumns -1 )
	{
		//check to see if user is by Dracula and has pressed enter
		if ((grid[blueMenRow - 1][blueMenColumn] == specialCharacter ||
		     grid[blueMenRow][blueMenColumn + 1] == specialCharacter ||
          	     grid[blueMenRow + 1][blueMenColumn] == specialCharacter ||
	     	     grid[blueMenRow][blueMenColumn - 1] == specialCharacter) &&
            	    input == '\0' && changeState == false)
		{
			//state has changed implementing fight algorithm from 
			//assignment 3 and 4
			changeState = true;
			bool fight = true;
			int turnNum = 1;

			std::cout << "\033[2J\033[1;1H";
			std::cout << Bluemen->getName() << " vs " 
				  << Dracula->getName() << std::endl;
			std::cout << "There are " << Bluemen->hasBlueMen() + 1 
                                  << " BlueMen" << std::endl;
			std::cout << "Fight!" << std::endl;
			std::cout << std::endl;
			std::cout << "Press enter to continue....";
			std::cin.ignore(
			std::numeric_limits<std::streamsize>::max(), '\n');

			//continuing fight until BlueMen or Vampire have no strength
			while (fight)
			{
				if (!Bluemen->isDead() && !Dracula->isDead())
				{
					std::cout << "Turn# " << turnNum++ << ":" 
					          << std::endl;
					int attack = Bluemen->attack();
					Dracula->defense(attack);
				}
				if (!Bluemen->isDead() && !Dracula->isDead())
				{
					std::cout << "Turn# " << turnNum++ << ":" 
						  << std::endl;
					int attack = Dracula->attack();
					Bluemen->defense(attack);
				}		
				if (Bluemen->isDead() || Dracula->isDead())
				{
					//vampire has no strength
					if (Dracula->isDead())
					{
						grid[Dracula->getRowPosition()]
                                    		    [Dracula->getColumnPosition()] = ' ';
						std::cout << Bluemen->getName() << " wins"
						          << std::endl;
					}	
					//BlueMen has no strength
					else
					{
						grid[Bluemen->getRowPosition()]
                                    		    [Bluemen->getColumnPosition()] = ' ';
						std::cout << Dracula->getName() << " wins"
						<< std::endl;
					}		
					fight = false;
					gameOver = true; 
					std::cout << std::endl;
				}	
			}	
			//The game is over displaying the result to the user
			std::cout << "Press enter to continue....";
			std::cin.ignore(
			std::numeric_limits<std::streamsize>::max(), '\n');
	
			std::cout << "\033[2J\033[1;1H";
			printGrid();
	
			if (Bluemen->isDead())
			{
				grid[Bluemen->getRowPosition()]
				    [Bluemen->getColumnPosition()] = ' ';
				std::cout << "Game Over: " << std::endl;
				std::cout << "You were defeated by Dracula" 
					  << std::endl;
				std::cout << std::endl;
			}
			else
			{
				grid[Dracula->getRowPosition()]
				    [Dracula->getColumnPosition()] = ' ';
				std::cout << "Congratulations! " << std::endl;
				std::cout << "You have escaped " << spaceName 
                                          << std::endl;
				std::cout << std::endl; 
			}
		}
	}
}



