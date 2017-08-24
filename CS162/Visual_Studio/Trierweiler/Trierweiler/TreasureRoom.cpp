/******************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: Implementation for the TreasureRoom class
******************************************************************************/
#include "TreasureRoom.hpp"

/******************************************************************************
* Description: Default constructor that passed all necessary atrributes to the
* base class constructor. Adjusts the canEnter state passed on the passed
* argument. Treasure is also set accroding to the passed value, where the
* char 'B' is a BlueMen and 'K' is the dungeon key. Afterwards the spaces grid
* is created
******************************************************************************/
TreasureRoom::TreasureRoom(Space* passedNorthSpace, Space* passedEastSpace, 
                           Space* passedSouthSpace, Space* passedWestSpace,
			   int passedNumRows, int passedNumColumns, 
                           char passedSpecialCharacter, std::string passedSpaceName,
	                   BlueMen* passedBlueMen, char passedTreasure, bool passedCanEnter)
	     :Space(passedNorthSpace, passedEastSpace, passedSouthSpace, 
                    passedWestSpace, passedNumRows, passedNumColumns,
		    passedSpecialCharacter, passedSpaceName, passedBlueMen)
{
	canEnter = passedCanEnter;
	treasure = passedTreasure;
	createGrid();
}

/******************************************************************************
* Description: Default destructor 
******************************************************************************/
TreasureRoom::~TreasureRoom()
{
}

/******************************************************************************
* Description: Method that displays the spaces hint
******************************************************************************/
void TreasureRoom::hint()
{
	
	std::cout << "Room Hint: " << std::endl;
	std::cout << "Press enter  to collect the treasure 'T'" << std::endl;
	std::cout << "It will help you on your quest to escape!" << std::endl;
	std::cout << std::endl;
	std::cout << "Press enter to continue....";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/******************************************************************************
* Description: Method that creates the space by filling the 2D char array
******************************************************************************/
void TreasureRoom::createGrid()
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
* changes if it has not been changed already. In the treasure room an item is
* added to the BlueMens collection of items
******************************************************************************/
void TreasureRoom::changingState(char input)
{	
	int blueMenRow = Bluemen->getRowPosition();
	int blueMenColumn = Bluemen->getColumnPosition();
	char blueMenDirection = Bluemen->getDirection();

	//added condition to avoid segmentation fault from proceeding if
	if (blueMenRow != 0 &&  blueMenRow != numRows - 1 &&
	    blueMenColumn != 0 && blueMenColumn != numColumns -1)
	{
		//check to see if user is by the treasure and has pressed enter
		if ((grid[blueMenRow - 1][blueMenColumn] == specialCharacter ||
	     	     grid[blueMenRow][blueMenColumn + 1] == specialCharacter ||
             	     grid[blueMenRow + 1][blueMenColumn] == specialCharacter ||
	     	     grid[blueMenRow][blueMenColumn - 1] == specialCharacter) &&
	   	    input == '\0') 
		{
			if (changeState == false) 
			{
				//state has changed adding item to BlueMen
				changeState = true;
				std::cout << "You have opened the treasure chest" 
				 	  << std::endl;

			if (treasure  == 'B')
			{
				std::cout << "You have collected a fellow BlueMen!" 
                                          << std::endl;
				std::cout << std::endl;
			}
			else if (treasure == 'K')
			{
				std::cout << "You have collected the dungeon key!" 
                                                  << std::endl;
					std::cout << std::endl;
				}	
				Bluemen->addItem(treasure);
			
			}
			//otherwise display a message stating it has already changed
			else
			{
				std::cout << "You have already opened the treasure chest." 
                                          << std::endl;
				std::cout << std::endl;
			}	
			std::cout << "Press enter  to continue....";
	        	std::cin.ignore(
			std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}
