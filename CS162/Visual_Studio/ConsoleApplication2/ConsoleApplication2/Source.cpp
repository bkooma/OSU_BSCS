#include <iostream>
using namespace std;
class Rectangle
{
private:
	int initialWidth;
	int initialHeight;
	int width;
	int height;

public:
	// setters
	bool setWidth(int);
	bool setHeight(int);

	// getters
	int getWidth();
	int getHeight();

	void doubleSize();
};

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
int Rectangle::getHeight() {
	return height;
}

int Rectangle::getWidth() {
	return width;
}

void Rectangle::doubleSize()
    {
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