/**************************************************************************************
** RPSGame.hpp is the RPS Game class specification file.
** Author:  Byron Kooima
** Date: 2017/07/30
** Description: CS162 Week5 Group10
** The RPSGame class represents an RPS Game
****************************************************************************************/

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include <string>
#include "Tool.hpp"

class RPSGame {
protected:
	Tool *human = nullptr;
	Tool *computer = nullptr;
	int human_wins;
	int computer_wins;	
	int ties;		

public:
	RPSGame();

	void play();
	void setComputerTool(int rStr, int pStr, int sStr);
	void setPlayerTool(std::string toolType, int rStr, int pStr, int sStr);
	void printScore();

	~RPSGame();
};

#endif
