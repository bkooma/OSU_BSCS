/************************************************************************************
** Point.cpp is the Point class function implementation file.
** Author:  Byron Kooima
** Date: 2017/02/13
** Description: The Point class has two double fields called that represent x- and y-
** coordinates. It has get and set methods for both fields. It has a constructor that 
** takes two double parameters and passes those values to the set methods to initialize
** the fields. It has a default constructor that initializes both coordinates to 0.
** It contains a method called distanceTo that takes a constant reference parameter to 
** another Point and returns the distance from the Point that was passed to the Point
** that was called the method of. 
**************************************************************************************/

#include <cmath>
#include <iostream>
#include "Point.hpp"

// default constructor
Point::Point()
{
	setXCoord(0.0);
	setYCoord(0.0);
}

// Point constructor
Point::Point(double x, double y)
{
	xCoord = x;
	yCoord = y;
}

// Point destructor
Point::~Point()
{}

/************************************************************************************
*                             Point::setXCoord
* This function sets the passed in double to xCoord.
*************************************************************************************/
void Point::setXCoord(double x)
{
	xCoord = x;
}

/************************************************************************************
*                             Point::setYCoord
* This function sets the passed in double to yCoord.
*************************************************************************************/
void Point::setYCoord(double y)
{
	yCoord = y;
}

/************************************************************************************
*                             Point::getXCoord
* This function returns the current xCoord.
*************************************************************************************/
double Point::getXCoord()
{
	return xCoord;
}

/************************************************************************************
*                             Point::getYCoord
* This function returns the current yCoord.
*************************************************************************************/
double Point::getYCoord()
{
	return yCoord;
}

/************************************************************************************
*                             Point::distanceTo
* This function calculates and returns the distance between two points.
*************************************************************************************/
double Point::distanceTo(const Point& other)
{
	double temp;
	temp = (xCoord - other.xCoord) * (xCoord - other.xCoord) + (yCoord - other.yCoord)* (yCoord - other.yCoord);
	return sqrt(temp);
}
