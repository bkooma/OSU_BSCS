//Box.hpp
#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

class Box
{
private:
	double height;
	double width;
	double length;

public:
	//default constructor
	Box() {
		width = 1;
		height = 1;
		length = 1;
	}

	// constructor with parameters
	Box(double w, double h, double l);

	//destructor
	~Box();

	//setters
	bool setWidth(double);
	bool setHeight(double);
	bool setLength(double);

	// getters
	double getVolume();
	double getSurfaceArea();
};

#endif // !BOX_HPP

