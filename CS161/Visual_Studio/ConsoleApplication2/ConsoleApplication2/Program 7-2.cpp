#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

class Circle
{	private:
		double radius;

	public:
		void setRadius(double);
		double calcArea();
};

void Circle::setRadius(double r)
{
	radius = r;
}

double Circle::calcArea()
{
	return 3.14 * pow(radius, 2);
}

int main()
{
	Circle circle1,
		circle2;

	circle1.setRadius(1);
	circle2.setRadius(2.5);
	
	cout << "The area of circle1 is " << circle1.calcArea() << endl;
	cout << "The area of circle2 is " << circle2.calcArea() << endl;
}