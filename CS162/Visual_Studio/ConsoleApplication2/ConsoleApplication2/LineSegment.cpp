/************************************************************************************
** LineSegment.cpp is the LineSegment class function implementation file.
** Author:  Byron Kooima
** Date: 2017/02/13
** Description: The LineSegment class contains two Points that represent its two 
** endpoints. It has get and set methods to initialize the data members. It contains 
** a method called length that returns the length of the LineSegment (using the 
** distanceTo method) and a method called slope that returns the dlope of the 
** LineSegment. 
**************************************************************************************/

#include <cmath>
#include <iostream>
#include "LineSegment.hpp"

// default constructor
LineSegment::LineSegment()
{
}

// Point constructor
LineSegment::LineSegment(Point endPoint1In, Point endPoint2In)
{
	endPoint1 = endPoint1In;
	endPoint2 = endPoint2In;
}


// Point destructor
LineSegment::~LineSegment()
{}


/************************************************************************************
*                             LineSegment::getEnd1
* This function returns the current endPoint1.
*************************************************************************************/
Point LineSegment::getEnd1()
{
	return endPoint1;
}

/************************************************************************************
*                             LineSegment::getEnd2
* This function returns the current endPoint2.
*************************************************************************************/
Point LineSegment::getEnd2()
{
	return endPoint2;
}

/************************************************************************************
*                             LineSegment::setEnd1
* This function sets the passed in Point to endPoint1.
*************************************************************************************/
void LineSegment::setEnd1(Point endPoint1In)
{
	endPoint1 = endPoint1In;
}

/************************************************************************************
*                             LineSegment::setEnd2
* This function sets the passed in Point to endPoint2.
*************************************************************************************/
void LineSegment::setEnd2(Point endPoint2In)
{
	endPoint2 = endPoint2In;
}

/************************************************************************************
*                             LineSegment::slope
* This function calculates and returns the length (distanceTo) of two points.
*************************************************************************************/
double LineSegment::length()
{
	return endPoint1.distanceTo(endPoint2);
}

/************************************************************************************
*                             LineSegment::slope
* This function calculates and returns the slope of two points.
*************************************************************************************/
double LineSegment::slope()
{
	return(endPoint2.getYCoord() - endPoint1.getYCoord()) / (endPoint2.getXCoord() - endPoint1.getXCoord());
}
