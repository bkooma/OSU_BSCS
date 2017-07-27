#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

class Circle
{	private:
		double radius;

	public:
		Circle();
		void setRadius(double);
		double calcArea();
};

Circle::Circle()
{
	radius = 1.0;
}

void Circle::setRadius(double r)
{	if (r >= 0.0)
	radius = r;
}

double Circle::calcArea()
{
	return 3.14 * pow(radius, 2);
}

int main()
{
	Circle circle1;

	Circle circle2;
	circle2.setRadius(2.5);
	
	cout << "The area of circle1 is " << circle1.calcArea() << endl;
	cout << "The area of circle2 is " << circle2.calcArea() << endl;
   
	return 0;
}
