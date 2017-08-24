/******************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: Implementation for the Space class
******************************************************************************/
#include "Space.hpp"

/******************************************************************************
* Description: Default constructor that sets the appropriate data member to the
* passed arguments. Minimum number of rows or columns for the game must be
* >= 7. If the number passed is < 7 the minimum value is assigned. Special
* character is the char value that the player interacts with to change the spaces
* state, changeState is used to check if the spaces state has changed, 
* canEnter is used to check if the player can enter the space, and gameOver is 
* used by the driver function to check if the game over. Space pointers are used
* to connect the dungeon, and the Blueman pointer is manipulated by the user's
* and spaces input
******************************************************************************/  
Space::Space(Space* passedNorthSpace, Space* passedEastSpace, 
             Space* passedSouthSpace, Space* passedWestSpace,
	     int passedNumRows, int passedNumColumns, 
             char passedSpecialCharacter, std::string passedSpaceName,
	     BlueMen* passedBlueMen)
{
	//connecting spaces 
	northSpace = passedNorthSpace;
	eastSpace = passedEastSpace;
	southSpace = passedSouthSpace;
	westSpace = passedWestSpace;
	//checking if the minimum rows and columns were passed
	if (passedNumRows < 7)
	{
		numRows = 7;
	}
	else
	{
		numRows = passedNumRows;
	}
	if (passedNumColumns < 7)
	{
		numColumns = 7;
	}
	else
	{
		numColumns = passedNumColumns;
	}
	specialCharacter = passedSpecialCharacter;
	changeState = false;
	gameOver = false;
	canEnter = true;
	spaceName = passedSpaceName;
	Bluemen = passedBlueMen;
	
	//creating the grid for the space
	grid = new char*[passedNumRows];
	for (int row = 0; row < passedNumRows; row++)
	{
		grid[row] = new char[passedNumColumns];
	}

	srand(time(NULL));
}

/******************************************************************************
* Description: Default destructor that deletes dynamically allocated memory
******************************************************************************/
Space::~Space()
{
	for (int row = 0; row < numRows; row++)
	{
		delete[] grid[row];
	}	
	delete[]  grid;
	Bluemen = NULL;
	northSpace = NULL;
	eastSpace = NULL;
	southSpace = NULL;
	westSpace = NULL;
}

/******************************************************************************
* Description: Method that sets the northSpace pointer to the passed pointer
******************************************************************************/
void Space::setNorthSpace(Space* passedNorthSpace)
{
	northSpace = passedNorthSpace;
}

/******************************************************************************
* Description: Method that sets the eastSpace pointer to the passed pointer
******************************************************************************/
void Space::setEastSpace(Space* passedEastSpace)
{
	eastSpace = passedEastSpace;
}

/******************************************************************************
* Description: Method that sets the southSpace pointer to the passed pointer
******************************************************************************/
void Space::setSouthSpace(Space* passedSouthSpace)
{
	southSpace = passedSouthSpace;
}

/******************************************************************************
* Description: Method that sets the westSpace pointer to the passed pointer
******************************************************************************/
void Space::setWestSpace(Space* passedWestSpace)
{
	westSpace = passedWestSpace;
}

/******************************************************************************
* Description: Method that sets the location of the BlueMen (the player) on 
* the space. Used when the player enters another room
******************************************************************************/
void Space::setBlueMen(int passedColumn, int passedRow)
{
	grid[passedColumn][passedRow] = 'O';
}

/******************************************************************************
* Description: Method that returns true if the game is over, otherwise, returns
* false
******************************************************************************/
bool Space::getGameOver()
{
	return gameOver;
}

/******************************************************************************
* Description: Method that prints the games menu
******************************************************************************/
void Space::printMenu()
{
	std::cout << "*****************************************************" 
                  << std::endl;
	std::cout << "                         Menu                        " 
                  << std::endl;
	std::cout << "*****************************************************" 
                  << std::endl;
	std::cout << "['w' = move North, 'd' = move East]" << std::endl;
	std::cout << "['s' = move South, 'a' = move West]" << std::endl;
	std::cout << "['i' = show items                 ]" << std::endl;
        std::cout << "['h' = show space hint            ]" << std::endl;
	std::cout << "['x' = quit                       ]" << std::endl;
	std::cout << std::endl;
}

/******************************************************************************
* Description: Method that prints the space
******************************************************************************/
void Space::printGrid()
{
	printMenu();
	std::cout << spaceName << ":" << std::endl;
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			if (column == 0 || column == numColumns - 1)
			{
				std::cout << grid[row][column];
			}
			else if (grid[row][column] == '-')
			{
				std::cout << grid[row][column] << '-' << '-';
				if (column < numColumns - 2)
				{
					std::cout << '-';
				}
			}
			else
			{
				std::cout << ' ' << grid[row][column] << ' ';
				if (column < numColumns - 2)
				{
					if (grid[row][column + 1] == '-')
					{
						std::cout << '-';
					}
					else
					{
						std::cout << ' ';
					}
				}
			}
		}
		std::cout << std::endl;

		if (row > 0 && row < numRows - 2)
		{
			std::cout << '+';
			for (int i = 0; i < numColumns - 2; i++)
			{
				std::cout << ' ' << ' ' << ' ' << '+';
			}
			std::cout << std::endl;
		}
	}
}

/******************************************************************************
* Description: Method that returns true if a player can enter the space they are
* trying to enter. If the player contains the dungeon key they can unlock all 
* spaces. Method checks if the user has they key, and will set the spaces 
* canEnter field to true, and will return true. Otherwise, the method will 
* return false. The player is trying to enter a space when they are in the middle
* of a bound (ie numRows == 0 and numColumns == numColumns/2).
* If the player cannot enter the space there position is set so that they 
* cannot travel around the bounds of the space.
******************************************************************************/
bool Space::canEnterRoom()
{
	int blueMenRow = Bluemen->getRowPosition();
	int blueMenColumn = Bluemen->getColumnPosition();
	char blueMenDirection = Bluemen->getDirection();
	Space* tempSpace = NULL;

	//checking if player can move to the Northern space
	if (blueMenRow == 0 && blueMenColumn == numColumns / 2 &&
	    blueMenDirection == 'w')
	{
		tempSpace = northSpace;
		if (tempSpace->canEnter == false && Bluemen->hasKey() == false)
		{

			//reseting position on the current space player is  not on 
			//the Nothern bound of the space 
			grid[blueMenRow][blueMenColumn] = ' ';
			Bluemen->setRowPosition(blueMenRow + 1);
			grid[Bluemen->getRowPosition()]
                            [Bluemen->getColumnPosition()] = 'O';
		}
	}
	//checking if player can move to the Eastern space
	else if (blueMenRow == numRows / 2 && blueMenColumn == numColumns - 1 &&
		 blueMenDirection == 'd')
	{
		tempSpace = eastSpace;
		if (tempSpace->canEnter == false && Bluemen->hasKey() == false)
		{
			//reseting position on the current space player is  not on 
			//the Easter bound of the space 
			grid[blueMenRow][blueMenColumn] = ' ';
			Bluemen->setColumnPosition(blueMenColumn - 1);
			grid[Bluemen->getRowPosition()]
                            [Bluemen->getColumnPosition()] = 'O';
		}
	}
	//checking if player can move to the Southern space
	else if (blueMenRow == numRows - 1 && blueMenColumn == numColumns / 2 &&
		 blueMenDirection == 's')
	{
		tempSpace = southSpace;
		if (tempSpace->canEnter == false && Bluemen->hasKey() == false)
		{
			//reseting position on the current space player is  not on 
			//the Southern bound of the space 
			grid[blueMenRow][blueMenColumn] = ' ';
			Bluemen->setRowPosition(blueMenRow - 1);
			grid[Bluemen->getRowPosition()]
                            [Bluemen->getColumnPosition()] = 'O';
		}
	}
	//checking if player can move to the Western  space
	else if (blueMenRow == numRows / 2 && blueMenColumn == 0 &&
		 blueMenDirection == 'a')
	{	
		tempSpace = westSpace;
		if (tempSpace->canEnter == false && Bluemen->hasKey() == false)
		{
			//reseting position on the current space player is  not on 
			//the Western bound of the space 
			grid[blueMenRow][blueMenColumn] = ' ';
			Bluemen->setColumnPosition(blueMenColumn + 1);
			grid[Bluemen->getRowPosition()]
                            [Bluemen->getColumnPosition()] = 'O';
		}
	}
	
	//If player has key, set the pointer canEnter field to true
	if (tempSpace != NULL)
	{
		if (tempSpace->canEnter == false)
		{
			if (Bluemen->hasKey() == true)
			{
				std::cout << "You have unlocked " 
                                          << tempSpace->spaceName << std::endl;
				tempSpace->canEnter = true;
			}
			else
			{
				std::cout << "You need the dungeon key to enter " 
                                          << tempSpace->spaceName << std::endl;
			}
			std::cout << std::endl;
			std::cout << "Press enter to continue....";
			std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(), '\n');
		}
		return tempSpace->canEnter;
	}
	else
	{
		return false;
	}
}

/******************************************************************************
* Description: Method that returns a Space pointer based on the position of the
* player. The player is trying to enter a space when they are in the middle
* of a bound (ie numRows == 0 and numColumns == numColumns/2). The players
* position is reset so they are in the appropriate spot on the next space.  
******************************************************************************/
Space* Space::moveToRoom()
{
	int blueMenRow = Bluemen->getRowPosition();
	int blueMenColumn = Bluemen->getColumnPosition();
	char blueMenDirection = Bluemen->getDirection();
	Space* tempSpace = NULL;

	//Entering Northern space, and reset the players position
 	if (blueMenRow == 0 && blueMenColumn == numColumns / 2 && 
	    blueMenDirection == 'w')
	{
		grid[blueMenRow][blueMenColumn] = ' ';
		Bluemen->setRowPosition(northSpace->numRows - 2);
		Bluemen->setColumnPosition(northSpace->numColumns / 2);
		tempSpace = northSpace;
	}
	//Entering Eastern space, and reset the players position
	else if (blueMenRow == numRows / 2 && blueMenColumn == numColumns - 1 && 
		 blueMenDirection == 'd')
	{
		grid[blueMenRow][blueMenColumn] = ' ';
		Bluemen->setRowPosition(eastSpace->numRows / 2);
		Bluemen->setColumnPosition(1);
		tempSpace = eastSpace;
	}
	//Entering Southern space, and reset the players position
	else if (blueMenRow == numRows - 1 && blueMenColumn == numColumns / 2 && 
		 blueMenDirection == 's')
	{
		grid[blueMenRow][blueMenColumn] = ' ';
		Bluemen->setRowPosition(1);
		Bluemen->setColumnPosition(southSpace->numColumns / 2);
		tempSpace = southSpace;
	}	
	//Entering Northern space, and reset the players position
	else
	{
		grid[blueMenRow][blueMenColumn] = ' ';
		Bluemen->setRowPosition(westSpace->numRows / 2);
		Bluemen->setColumnPosition(westSpace->numColumns - 2);
		tempSpace = westSpace;
	}

	tempSpace->setBlueMen(Bluemen->getRowPosition(), 
                              Bluemen->getColumnPosition());
	
	return tempSpace;
}

/******************************************************************************
* Description: Method that implements the dungeon. It prints the space and 
* gathers the user's input. Based on user input it will display the space's hint,
* display the BlueMens items, will move the BlueMen, or will set the gameOver
* field to true. After every move, the space's state is checked. The method 
* returns the boolean value from the canEnterSpace() method. This is done to let
* the driver know it can successfully change its space pointer. Invalid input
* is ignored, and nothing will happen.
******************************************************************************/
bool Space::userInput()
{
	//clear screen and print the grid
	std::cout << "\033[2J\033[1;1H"; 
	printGrid();
		
	//gather user input
	std::string input;
	std::cout << "Your move: ";	
	std::getline(std::cin, input);
	std::cout << std::endl;	

	//move the player and check the spaces state
	if (input[0] == 'w' || input[0] == 'd' || input[0] == 's' || 
            input[0] == 'a' || input[0] == '\0')
	{
		int blueMenRow = Bluemen->getRowPosition();
		int blueMenColumn = Bluemen->getColumnPosition();
		Bluemen->setDirection(input[0]);

		//checking that the player is not on a bound of the space
		if (blueMenRow != 0 && blueMenRow != numRows - 1 &&
		    blueMenColumn != 0 && blueMenColumn != numColumns - 1)
		{
			//move North and reset players position
			if (input[0] == 'w' &&  
                    	    grid[blueMenRow - 1][blueMenColumn] != '-' &&
		    	    grid[blueMenRow - 1]
                            [blueMenColumn] != specialCharacter) 
			{
				grid[blueMenRow][blueMenColumn] = ' ';
				Bluemen->setRowPosition(blueMenRow - 1);
				grid[Bluemen->getRowPosition()]
                            	    [Bluemen->getColumnPosition()] = 'O';	
			}
			//move East and reset players position
			else if (input[0] == 'd' &&
                        	 grid[blueMenRow][blueMenColumn + 1] != '|' &&
                         	 grid[blueMenRow]
                             	 [blueMenColumn + 1] != specialCharacter)
			{
				grid[blueMenRow][blueMenColumn] = ' ';
				Bluemen->setColumnPosition(blueMenColumn + 1);
				grid[Bluemen->getRowPosition()]
                                    [Bluemen->getColumnPosition()] = 'O';
			
			}
			//move South and reset players position
			else if (input[0] == 's' &&
		        	 grid[blueMenRow + 1][blueMenColumn] != '-' && 
                         	 grid[blueMenRow + 1]
                             	     [blueMenColumn] != specialCharacter)
			{
				grid[blueMenRow][blueMenColumn] = ' ';
				Bluemen->setRowPosition(blueMenRow + 1);
				grid[Bluemen->getRowPosition()]
                            	    [Bluemen->getColumnPosition()] = 'O';
			}
			//move West and reset players position
			else if (input[0] == 'a' && 
		         	 grid[blueMenRow][blueMenColumn - 1] != '|' &&
                         	 grid[blueMenRow]
                             	     [blueMenColumn - 1] != specialCharacter)
			{
				grid[blueMenRow][blueMenColumn] = ' ';
				Bluemen->setColumnPosition(blueMenColumn - 1);
				grid[Bluemen->getRowPosition()]
                            	    [Bluemen->getColumnPosition()] = 'O';
			}

			//checking the spaces state
			changingState(input[0]);
		}
	}
	//display BlueMens items
	else if (input[0] == 'i')
	{
		Bluemen->showItems();
	}
	//display spaces hint
	else if (input[0] == 'h')
	{
		hint();
	}
	//quit the program
	else if (input[0] == 'x')
	{
		gameOver = true;
	}	
	
	//return if the player can enter a room
	return canEnterRoom();
}



