// Rectangle.cpp
#include "Rectangle.h"

Rectangle::Rectangle(int w, int h)
{
	initialHeight = h;
	initialWidth = w;
	width = w;
	height = h;
}

// destructor
Rectangle::~Rectangle()
{
	cout << "bye bye" << endl;
}

bool Rectangle::setWidth(int w)
{
	if (w < 0 || w > 1000)
		return false;
	else {
		width = w;
		return true;
	}
}

bool Rectangle::setHeight(int h) {
	if (h < 0 || h > 1000)
		return false;
	else {
		height = h;
		return true;
	}
}

// Two simple getter functions. These hide the actual method of storage.
int Rectangle::getHeight() const {
	return height;
}

int Rectangle::getWidth() const {
	return width;
}

void Rectangle::doubleSize()
    {
		int width;
		width = width * 2;
		height = height * 2;
	}

/*int main()
{
	Rectangle rectangle1;
	rectangle1.width = 5;
	rectangle1.height = 10;

	rectangle1.doubleSize();

	cout << "width:   " << rectangle1.width << endl;

	return 0;
}
*/