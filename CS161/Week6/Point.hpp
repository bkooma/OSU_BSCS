/************************************************************************************
** Point.hpp is the Point class specification file
** Author:  Byron Kooima
** Date : 2017 / 02 / 13
************************************************************************************/

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point
{
private:
	double xCoord;
	double yCoord;

public:
	// default constructor
	Point();

	// constructor with parameters
	Point(double x, double y);
	
	// Method for distanceTo
	double distanceTo(const Point&);

	//setters
	void setXCoord(double);
	void setYCoord(double);

	// getters
	double getXCoord();
	double getYCoord();

	//destructor
	~Point();

};

#endif // !POINT_HPP

