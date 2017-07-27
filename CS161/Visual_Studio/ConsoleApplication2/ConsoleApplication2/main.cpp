#include <iostream>
#include <thread>
#include <chrono>
#include "langton.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	Ant* ant = new Ant();
	ant->setX(Plane::WIDTH / 2);
	ant->setY(Plane::HEIGHT / 2); // starting position.

	Plane* plane = new Plane();
	plane->setAnt(ant);

	while (true) {
		plane->output();
		plane->moveAnt();
		cout << std::endl;
		std::this_thread::sleep_for (std::chrono::seconds(1));
	}

	delete ant;
	delete plane;
}