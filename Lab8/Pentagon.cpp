#include <iostream>
#include <cmath>
#include "Pentagon.h"

Pentagon::Pentagon() : Pentagon(0) {}

Pentagon::Pentagon(double a) : side_a(a) {
	//std::cout << "Pentagon created: " << side_a << std::endl;
}

Pentagon::Pentagon(std::istream &is) {
	std::cout << "Insert side of Hexagon: \n";
	is >> side_a;
	if (side_a < 0) {
		std::cerr << "Error: side must be more than 0." << std::endl;
		side_a = 0;
	}
}

Pentagon::Pentagon(const Pentagon& orig) {
	std::cout << "Pentagon copy created." << std::endl;
	side_a = orig.side_a;
	if (side_a < 0) {
		std::cerr << "Error: side must be more than 0." << std::endl;
		side_a = 0;
	}
}

double Pentagon::Square() {
	return side_a * side_a * 0.25 * sqrt(25 + 10 * sqrt(5));
}

void Pentagon::Print() {
	std::cout << "Pentagon with side = " << side_a;
}

std::ostream & operator<<(std::ostream & os, const Pentagon & right) {
	os << "Pentagon with side = " << right.side_a;
	return os;
}

Pentagon::~Pentagon() {}