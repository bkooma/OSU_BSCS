/******************************************************************************
** Tool.hpp is the Tool Base class specification file.
** Authors:  Byron Kooima, Alexander Jennison, Polly Sobeck,
**           Dai Duong Nguyen, Zachary Bellone
** Date: 2017/07/23
** Description: CS162 Week5 Group 10
** The Tool class represents a Tool Base class. It creates the strength, type, 
** and fight() function for the RPG derived classes. The fight function passes
** in a Tool pointer and establishes the strength of Tool when playing against
** computer Tool. fight() returns the enumerated "FightResult" value based on 
** the results of taking on the computer's Tool.
******************************************************************************/
#ifndef TOOL_HPP
#define TOOL_HPP

// Enumerated Fight results to determine outcome of the fight
enum FightResult {WIN, LOSE, DRAW};

class Tool {
protected:
	int strength;
	char type;

public:
	// Default Constructor
	Tool();
	// User defined constructor
	Tool(int strength);
	// Pure abstract function
	virtual FightResult fight(Tool *tool) = 0;
	// Set the Tool strength
	void setStrength(int);
	// Getters
	// Get the Tool strength
	int getStrength();
	// Get the Tool type
	char getType();
	// Virtual Destructor
	virtual ~Tool();
};

#endif
