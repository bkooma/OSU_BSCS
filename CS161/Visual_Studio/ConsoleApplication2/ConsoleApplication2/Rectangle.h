//Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>


class Rectangle
{
private:
	int initialHeight;
	int initialWidth;
	int height;
	int width;

public:
	//default constructor
	Rectangle() {
		initialHeight = 0;
		initialWidth = 0;
		width = 0;
		height = 0;
	}

	// constructor with parameters
	Rectangle(int w, int h);

	//destructor
	~Rectangle();

	// getters
	int getWidth() const;
	int getHeight() const;

	//setters
	bool setWidth(int);
	bool setHeight(int);

	void doubleSize();
};

#endif // !RECTANGLE_H

