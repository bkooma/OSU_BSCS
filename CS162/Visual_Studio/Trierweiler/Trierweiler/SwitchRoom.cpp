/******************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: Implementation for the SwitchRoom class
******************************************************************************/
#include "SwitchRoom.hpp"

/******************************************************************************
* Description: Default constructor that passed all necessary atrributes to the
* base class constructor. isMainRoom is used to initially print the player,
* (where the player will start), and numGaurds is the number of vampire gaurds
* that will be in the space. The maximum of gaurds allowed is 8, and the 
* minmum is 1. If those conditions are met gaurd objects are created. Afterwards
* the spaces grid is created
******************************************************************************/
SwitchRoom::SwitchRoom(Space* passedNorthSpace, Space* passedEastSpace, 
                       Space* passedSouthSpace, Space* passedWestSpace,
		       int passedNumRows, int passedNumColumns, 
                       char passedSpecialCharacter, std::string passedSpaceName,
	               BlueMen* passedBlueMen, int passedNumGaurds, bool passedIsMainRoom)
           :Space(passedNorthSpace, passedEastSpace, passedSouthSpace, 
                  passedWestSpace, passedNumRows, passedNumColumns, 
                  passedSpecialCharacter, passedSpaceName, passedBlueMen)
{
	isMainRoom = passedIsMainRoom;
	numGaurds = passedNumGaurds;

	//if condiction met create gaurd objects
	if (passedNumGaurds > 0 && passedNumGaurds <= 8)
	{
		gaurdArray = new Gaurd*[passedNumGaurds];
		for (int i = 0; i < numGaurds; i++)
		{
			gaurdArray[i] = new Gaurd();
		}
	}
	else
	{
		gaurdArray = NULL;
	}
	createGrid();
}

/******************************************************************************
* Description: Default destructor that deletes dynamically allocated memory
******************************************************************************/
SwitchRoom::~SwitchRoom()
{
	for (int i = 0; i < numGaurds; i++)
	{
		delete gaurdArray[i];
	}
	delete[] gaurdArray;
}

/******************************************************************************
* Description: Method that displays the spaces hint
******************************************************************************/
void SwitchRoom::hint()
{
	std::cout << "Room Hint: " << std::endl;
	std::cout << "Press enter to flip the switch  'S'" << std::endl;
	std::cout << "All doors are hidden until then " << std::endl;
	std::cout << "Beware of vampire gaurds. Do not get caught by one!" 
                  << std::endl;
	std::cout << "You are safe when traveling around the room's circumference" 
                  << std::endl;
	std::cout << std::endl;
	std::cout << "Press enter to continue....";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/******************************************************************************
* Description: Method that creates the space by filling the 2D char array
******************************************************************************/
void SwitchRoom::createGrid()
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

	//adding the special character needed to change space state
	grid[numRows / 2][numColumns / 2] = specialCharacter;

	//adding vampire gaurds if any
	int gaurdRow = 0;
	int gaurdColumn = 0;
	Gaurd* tempGaurd = NULL;
	for (int i = 0; i < numGaurds; i++)
	{
		tempGaurd = gaurdArray[i];
		gaurdRow = rand() % (numRows - 4) + 2;
		gaurdColumn = rand() % (numColumns - 4) + 2;

		while (grid[gaurdRow][gaurdColumn] != ' ')
		{
			gaurdRow = rand() % (numRows - 4) + 2;
			gaurdColumn = rand() % (numColumns - 4) + 2;
		}
		tempGaurd->setRowPosition(gaurdRow);
		tempGaurd->setColumnPosition(gaurdColumn);
		tempGaurd->setDisplay('V');
		grid[gaurdRow][gaurdColumn] = tempGaurd->getDisplay();
	}

	//adding the player if the space is the main room
	if (isMainRoom == true)
	{
		grid[numRows - 2][numColumns / 2] = 'O';
	}
}

/******************************************************************************
* Description: Method that changes the spaces state. If the player is next to
* the specialCharacter and presses the enter key, the state of the space
* changes if it has not been changed already. In the switch room, all doors 
* are revealed to the player. After the vampire gaurds are moved, and calls
* are made to check if the player has been caught by one.
******************************************************************************/
void SwitchRoom::changingState(char input)
{
	int blueMenRow = Bluemen->getRowPosition();
	int blueMenColumn = Bluemen->getColumnPosition();
	char blueMenDirection = Bluemen->getDirection();
	
	//added condition to avoid segmentation fault from proceeding if
	if (blueMenRow != 0 &&  blueMenRow != numRows - 1 &&
	    blueMenColumn != 0 && blueMenColumn != numColumns -1 )
	{
		//check to see if user is by the switch and has pressed enter
		if ((grid[blueMenRow - 1][blueMenColumn] == specialCharacter  ||
	     	     grid[blueMenRow][blueMenColumn + 1] == specialCharacter  ||
             	     grid[blueMenRow + 1][blueMenColumn] == specialCharacter  ||
	     	     grid[blueMenRow][blueMenColumn - 1] == specialCharacter) &&
	    	    input == '\0')
		{
			//change space state if it has not changed
			if (changeState == false)
			{
				
				//state has changed revealing hidden doors
				changeState = true;
				std::cout << "You have flipped the switch. ";
                        	std::cout << " All doors have been revealed." 
                                          << std::endl;
				std::cout << std::endl;
			
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
			}
			//otherwise Show message stating it has already changed
			else
			{	
				std::cout << "You have already flipped the switch." 
                                          << std::endl;
				std::cout << std::endl;
			}
			std::cout << "Press enter to continue....";
			std::cin.ignore(
			std::numeric_limits<std::streamsize>::max(), '\n');	
		}
	}

	//check to see if the player has been caught by a gaurd
	bool captured = checkForGaurds();
	if (captured == false)
	{
		moveGaurds();
		captured = checkForGaurds();
	}
	//if the player has been captured the game is over
	if (captured == true)
	{
		std::cout << "\033[2J\033[1;1H";
		printGrid();
		std::cout << std::endl;
		std::cout << "Game Over: " << std::endl;
		std::cout << "You have been captured by a vampire gaurd" 
                          << std::endl;
		std::cout << std::endl;
		std::cout << "Press enter to continue....";
		std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
		gameOver = true;
	}
}

/******************************************************************************
* Description: Method that returns true if the player and a gaurd are in the
* same position in the space, otherwise returns false
******************************************************************************/
bool SwitchRoom::checkForGaurds()
{
	Gaurd* tempGaurd = NULL;
	for (int i = 0; i < numGaurds; i++)
	{
		tempGaurd = gaurdArray[i];
		if (tempGaurd->getRowPosition() == Bluemen->getRowPosition() && 
		    tempGaurd->getColumnPosition() == Bluemen->getColumnPosition())
		{
			grid[tempGaurd->getRowPosition()]
                            [tempGaurd->getColumnPosition()] = 
                             tempGaurd->getDisplay();

			return true;
		}
		tempGaurd = NULL;
	}
	return false;
}

/******************************************************************************
* Description: Method that moves the gaurds in the space. The gaurds are always
* positioned so that the perimeter (not the bounds of the space) is free for
* the user to roam without getttng captured. The gaurds move according to an
* int generated by rand() where 0 = North, 1 = East, 2 = South, 3 = West. The
* gaurds get one chance to move regardless if the previous attempt was 
* unsuccessful
******************************************************************************/
void SwitchRoom::moveGaurds()
{
	
	int direction = 0; 
	int gaurdRow = 0;
	int gaurdColumn = 0;
	Gaurd* tempGaurd = NULL;

	for (int i = 0; i < numGaurds; i++)
	{
		tempGaurd = gaurdArray[i];
		direction = rand() % 4;
		gaurdRow = tempGaurd->getRowPosition();
		gaurdColumn = tempGaurd->getColumnPosition();

		//moving gaurd North
		if (direction == 0)
		{
			//checking to see if the next position North is open
			if (gaurdRow - 1 != 1 && 
                            (grid[gaurdRow - 1][gaurdColumn] == ' ' ||
			    (gaurdRow - 1 == Bluemen->getRowPosition() && 
			     gaurdColumn == Bluemen->getColumnPosition())))
			{
				grid[gaurdRow][gaurdColumn] = ' ';
				tempGaurd->setRowPosition(gaurdRow - 1);
				grid[gaurdRow - 1][gaurdColumn] = 
                                     tempGaurd->getDisplay();
			}
		}
		//moving gaurd East
		else if (direction == 1)
		{
			//checking to see if the next position East is open
			if (gaurdColumn + 1 != numColumns - 2 && 
                            (grid[gaurdRow][gaurdColumn + 1] == ' ' ||
			    (gaurdRow == Bluemen->getRowPosition() &&
		             gaurdColumn + 1 == Bluemen->getColumnPosition())))
			{
				grid[gaurdRow][gaurdColumn] = ' ';
				tempGaurd->setColumnPosition(gaurdColumn + 1);
				grid[gaurdRow][gaurdColumn + 1] = 
                                     tempGaurd->getDisplay();
			}

		}
		//moving gaurd South
		else if (direction == 2)
		{
			//checking to see if the next position South is open
			if (gaurdRow + 1 != numRows - 2 && 
                            (grid[gaurdRow + 1][gaurdColumn] == ' ' ||
			    (gaurdRow + 1 == Bluemen->getRowPosition() &&
			     gaurdColumn == Bluemen->getColumnPosition())))
			{
				grid[gaurdRow][gaurdColumn] = ' ';
				tempGaurd->setRowPosition(gaurdRow + 1);
				grid[gaurdRow + 1][gaurdColumn] = 
                                     tempGaurd->getDisplay();
			}

		}
		//moving gaurd West
		else
		{	
			//checking to see if the next position West is open
			if (gaurdColumn - 1 != 1 && 
                            (grid[gaurdRow][gaurdColumn - 1] == ' ' ||
			    (gaurdRow == Bluemen->getRowPosition() &&
			     gaurdColumn - 1 == Bluemen->getColumnPosition())))
			{
				grid[gaurdRow][gaurdColumn] = ' ';
				tempGaurd->setColumnPosition(gaurdColumn - 1);
				grid[gaurdRow][gaurdColumn - 1] = 
                                     tempGaurd->getDisplay();
			}
		}
		tempGaurd = NULL;
	}
}



