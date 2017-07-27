#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Rectangle
{
private:
	double length;
	double width;
public:
	void setLength(double);
	void setWidth(double);
	double getLength();
	double getWidth();
	double calcArea();
};

void Rectangle::setLength(double len)
{
	if (len >= 0.0)
		length = len;
	else
	{
		length = 1.0;
		cout << "Invalid length. Using a default value of 1.0\n";
	}
}

void Rectangle::setWidth(double w)
{
	if (w >= 0.0)
		width = w;
	else
	{
		width = 1.0;
		cout << "Invalid width. Using a default value of 1.0\n";
	}
}

double Rectangle::getLength()
{
	return length;
}

double Rectangle::getWidth()
{
	return width;
}

double Rectangle::calcArea()
{
	return length * width;
}

/*int main()
{
	Rectangle box;
	double boxLength, boxWidth;

	cout << "This program will calculate the area of a rectangle.\n";
	cout << "What is the length? ";
	cin >> boxLength;
	cout << "What is the width? ";
	cin >> boxWidth;


	box.setLength(boxLength);
	box.setWidth(boxWidth);

	cout << "\n Here is the rectangle's data:\n";
	cout << "Length: " << box.getLength() << endl;
	cout << "Width : " << box.getWidth() << endl;
	cout << "Area  : " << box.calcArea() << endl;
	return 0;
}
*/