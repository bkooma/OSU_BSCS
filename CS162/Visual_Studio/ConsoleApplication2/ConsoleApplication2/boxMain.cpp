#include<iostream>

#include "Box.hpp"

using std::cout;
using std::endl;

int main()
{
	Box box1(-2.4, 7.1, 5.0);
	Box box2;

	if (!box1.setHeight(-2.4))
		cout << "Invalid box height entered! \n";
	else if (!box1.setLength(7.1))
		cout << "Invalid box length entered! \n";
	else if (!box1.setWidth(5.0))
		cout << "Invalid box width entered! \n";
	else
	{
		double volume1 = box1.getVolume();
		double surfaceArea1 = box1.getSurfaceArea();
		cout << "Here is the box's data:\n";
		cout << "SurfaceArea1: " << surfaceArea1 << endl;
		cout << "Volume1: " << volume1 << endl;
	}

	double volume2 = box2.getVolume();
	double surfaceArea2 = box2.getSurfaceArea();
	cout << "SurfaceArea2: " << surfaceArea2 << endl;
	cout << "Volume2: " << volume2 << endl;

	return 0;
}