/************************************************************************************
** Box.cpp is the Box class function implementation file. 
** Author:  Byron Kooima
** Date: 2017/02/07
** Description: The Box class has three double fields called height, width and length.
** The class has set methods for each field. It has a three-parameter constructor that
** takes three doubles and passes them to the set methods to initialize the fields of 
** the Box. It has a default constructor that uses the set methods to initialize each 
** field to 1.  It has a method that calculates and returns the volume of the Box and
** a method that calculates and returns the surface area of the Box. 
**************************************************************************************/

#include "Box.hpp"


// Box constructor
Box::Box(double w, double h, double l)
{
	width = w;
	height = h;
	length = l;
}

// Box destructor
Box::~Box()
{}


/************************************************************************************
*                             Box::setWidth
* If argument passed to the setWidth function is zero or greater, it is copied into
* variable width, and true is returned. If negative, false is returned and the value
* remains the same.
*************************************************************************************/
bool Box::setWidth(double w)
{
	if (w < 0)
		return false;
	else {
		width = w;
		return true;
	}
}

/************************************************************************************
*                             Box::setHeight
* If argument passed to the setHeight function is zero or greater, it is copied into
* variable height, and true is returned. If negative, false is returned and the value
* remains the same.
*************************************************************************************/
bool Box::setHeight(double h) {
	if (h < 0)
		return false;
	else {
		height = h;
		return true;
	}
}

/************************************************************************************
*                             Box::setLength
* If argument passed to the setLength function is zero or greater, it is copied into
* variable length, and true is returned. If negative, false is returned and the value
* remains the same.
*************************************************************************************/
bool Box::setLength(double l) {
	if (l < 0)
		return false;
	else {
		length = l;
		return true;
	}
}

/************************************************************************************
*                             Box::getVolume
* This function calculates and returns the volume of a box.
*************************************************************************************/
double Box::getVolume() {
	return length * height * width;
}

/************************************************************************************
*                             Box::getSurfaceArea
* This function calculates and returns the surface area of a box.
*************************************************************************************/
double Box::getSurfaceArea()
    {
	return ((width * height) * 2) + ((width * length) * 2) + ((height * length) * 2);
	}