/******************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: Gaurd class holds data fields for its row and columns position, 
* as well as, a char value that holds its display. There are get and set 
* methods to access and change its data fields. Used to update the position
* and to set its display on a space
******************************************************************************/
#ifndef GAURD_HPP
#define GAURD_HPP

class Gaurd
{
private:
	int rowPosition;
	int columnPosition;
	char display;

public:
	Gaurd();
	~Gaurd();

	void setRowPosition(int);
	void setColumnPosition(int);
	void setDisplay(char);
	int getRowPosition();
	int getColumnPosition();
	int getDisplay();
};

#endif


