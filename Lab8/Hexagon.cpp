#include <iostream>
#include <cmath>
#include "Hexagon.h"

Hexagon::Hexagon() : Hexagon(0) {}

Hexagon::Hexagon(double a) : side_a(a) {
	//std::cout << "Hexagon created: " << side_a << std::endl;
}

Hexagon::Hexagon(std::istream &is) {
	std::cout << "Insert side of Hexagon: \n";
	is >> side_a;
	if (side_a < 0) {
		std::cerr << "Error: side must be more than 0." << std::endl;
		side_a = 0;
	}
}

Hexagon::Hexagon(const Hexagon& orig) {
	std::cout << "Hexagon copy created." << std::endl;
	side_a = orig.side_a;
	if (side_a < 0) {
		std::cerr << "Error: side must be more than 0." << std::endl;
		side_a = 0;
	}
}

double Hexagon::Square() {
	return side_a * side_a * 1.5 * sqrt(3);
}

void Hexagon::Print() {
	std::cout << "Hexagon with side = " << side_a;
}

std::ostream & operator<<(std::ostream & os, const Hexagon & right) {
	os << "Hexagon with side = " << right.side_a;
	return os;
}

Hexagon::~Hexagon() {}