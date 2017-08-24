/******************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: Driver function for the 2D dungeon game. The user can play
* until they decide to quit.
******************************************************************************/
#include "SwitchRoom.hpp"
#include "TreasureRoom.hpp"
#include "BossRoom.hpp"

void intro();

int main()
{
	bool play = true;
	std::string playAgain;

	//Playing game until the user decides to quit
	intro();
	while (play)
	{
		//Creating BlueMen and Space pointers to object and linked
		//spaces together
		BlueMen* Bluemen = new BlueMen(2, 10, 1, 6, 3, 4, "BlueMen");
		Bluemen->setRowPosition(5);
		Bluemen->setColumnPosition(3);
		Space* sMain = new SwitchRoom(NULL, NULL, NULL, NULL, 7, 7, 'S', 
                                              "Main Switch Room", Bluemen, 0, true);
		Space* sEast = new SwitchRoom(NULL, NULL, NULL, sMain, 11, 11, 'S', 
                                              "East Switch Room", Bluemen, 4, false);
		Space* sSouth = new SwitchRoom(sMain, NULL, NULL, NULL, 11, 11, 'S', 
                                               "South Switch Room", Bluemen, 4, false);
		Space* sWest = new SwitchRoom(NULL, sMain, NULL, NULL, 11, 11, 'S', 
                                              "West Switch Room", Bluemen, 4, false);
		sMain->setEastSpace(sEast);
		sMain->setSouthSpace(sSouth);
		sMain->setWestSpace(sWest);
		Space* tEast = new TreasureRoom(NULL, NULL, NULL, sEast, 7, 7, 'T', 
                                                "East Treasure Room", Bluemen, 'B', false);
		Space* tWest = new TreasureRoom(NULL, sWest, NULL, NULL, 7, 7, 'T', 
                                                "West Treasure Room", Bluemen, 'B', false);
		Space* tSouth = new TreasureRoom(sSouth, NULL, NULL, NULL, 7, 7, 'T', 
                                                 "South Treasure Room", Bluemen, 'K', true);
		sEast->setEastSpace(tEast);
		sSouth->setSouthSpace(tSouth);
		sWest->setWestSpace(tWest);
		Space* bossRoom = new BossRoom(NULL, NULL, sMain, NULL, 9, 9, 'D', 
                                               "Dracula's Liar", Bluemen, false);
		sMain->setNorthSpace(bossRoom); 

		//calling space userInput function until the game is over (BlueMen
		//defeat/lose to Dracula, or BlueMen were captured by gaurds)
		Space* temp = sMain;
		while (!temp->getGameOver())
		{
			if (temp->userInput())
			{
				temp = temp->moveToRoom();
			}
		}
		
		//Asking user if they want to play again and input validation
		bool validInput = false;
		while (!validInput)
		{
			std::cout << "Do you wish to play again?" << std::endl;
			std::cout << "['y' = yes, 'n' = no]: ";
			std::getline(std::cin, playAgain);
			std::cout << std::endl;

			if (playAgain[0] != 'n' && playAgain[0] != 'y')
			{
				std::cout << "Error: Invalid Input" << std::endl;
				std::cout << std::endl;
			}
			else if (playAgain[0] == 'n')
			{
				play = false;
				validInput = true;
			}
			else
			{
				validInput = true;
			}

		}
	
		//deleting dynamically allocated memory
		delete bossRoom;
		delete tEast;
		delete sEast;
		delete tSouth;
		delete sSouth;
		delete tWest;
		delete sWest;
		delete sMain;
		delete Bluemen;
	}

	return 0;
}

void intro()
{
	std::cout << "*****************************************************" << std::endl;
	std::cout << "                  BlueMen Adventure                  " << std::endl;
	std::cout << "*****************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "The BlueMen have been trapped in Dracula's Dungeon " << std::endl;
	std::cout << "Finally one is free. Defeat Dracula to escape! " << std::endl;
	std::cout << "Remember the BlueMen are strongest when together..." << std::endl;
	std::cout << std::endl;
	std::cout << "Press any key to continue....";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}
