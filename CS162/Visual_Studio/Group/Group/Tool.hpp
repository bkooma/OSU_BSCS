/******************************************************************************
** tool.hpp is the Tool class specification file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week5 Group 10
** Description: Header file for the Tool class. 
******************************************************************************/
#ifndef TOOL_HPP
#define TOOL_HPP

// This enum is used to inform if a battle was won, lost, or tied.
enum FightResult {WIN, LOSE, DRAW};

// This class is the abstract representation of a tool used in rock paper sisscors.
class Tool {
protected:
	int strength;
	char type;

public:
	Tool();
	Tool(int strength);
	void setStrength(int strength);
	int getStrength() const;
	char getType() const;
	virtual FightResult fight(Tool *tool) = 0; // abstract function
	virtual ~Tool();
};

#endif
