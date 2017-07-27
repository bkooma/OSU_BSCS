/************************************************************************************
** LineSegment.hpp is the LineSegment class specification file
** Author:  Byron Kooima
** Date : 2017 / 02 / 13
************************************************************************************/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include "Point.hpp"
#include <iostream>

class LineSegment
{
private:
	Point endPoint1;
	Point endPoint2;

public:
	LineSegment();

	// constructor with parameters
	LineSegment(Point, Point);
	
	// Method for length and slope
	double length();
	double slope();

	//setters
	void setEnd1(Point);
	void setEnd2(Point);

	// getters
	Point getEnd1();
	Point getEnd2();

	//destructor
	~LineSegment();

};

#endif // !LINESEGMENT_HPP

