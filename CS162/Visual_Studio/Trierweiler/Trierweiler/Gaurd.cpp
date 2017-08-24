/******************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: Implementation for the Gaurd class
******************************************************************************/
#include "Gaurd.hpp"

/******************************************************************************
* Description: Default constructor that sets row and column values to 1 and
* the display to G
******************************************************************************/
Gaurd::Gaurd()
{
	rowPosition = 1;
	columnPosition = 1;
	display = 'G';
}

/******************************************************************************
* Description: Default destructor
******************************************************************************/
Gaurd::~Gaurd()
{
}

/******************************************************************************
* Description: Set method that sets the Gaurds row position to the passed
* argument
******************************************************************************/
void Gaurd::setRowPosition(int newRow)
{
	rowPosition = newRow;
}

/******************************************************************************
* Description: Set method that sets the Gaurds column  position to the passed
* argument
******************************************************************************/
void Gaurd::setColumnPosition(int newColumn)
{
	columnPosition = newColumn;
}

/******************************************************************************
* Description: Set method that sets the Gaurds display to the passed
* argument
******************************************************************************/
void Gaurd::setDisplay(char newDisplay)
{
	display = newDisplay;
}

/******************************************************************************
* Description: Get method that returns the Gaurds row position as an int
******************************************************************************/
int Gaurd::getRowPosition()
{
	return rowPosition;
}

/******************************************************************************
* Description: Get method that returns the Gaurds column position as an int
******************************************************************************/
int Gaurd::getColumnPosition()
{
	return columnPosition;
}

/******************************************************************************
* Description: Get method that returns the Gaurds display as a char
******************************************************************************/
int Gaurd::getDisplay()
{
	return display;
}

