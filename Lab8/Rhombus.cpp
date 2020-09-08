#include <iostream>
#include <cmath>
#include "Rhombus.h"

Rhombus::Rhombus() : Rhombus(0, 0) {}

Rhombus::Rhombus(double a, double b) : side_a(a), side_b(b) {
	//std::cout << "Rhombus created: " << side_a << ", " << side_b << std::endl;
}

Rhombus::Rhombus(std::istream &is) {
	is >> side_a;
	is >> side_b;
	if (side_a < 0 || side_b < 0) {
		std::cerr << "Error: sides must be >= 0." << std::endl;
		side_a = 0;
		side_b = 0;
	}
}

Rhombus::Rhombus(const Rhombus& orig) {
	std::cout << "Rhombus copy created." << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	if (side_a < 0 || side_b < 0) {
		std::cerr << "Error: diagonales must be >= 0." << std::endl;
		side_a = 0;
		side_b = 0;
	}
}

double Rhombus::Square() {
	return side_a * side_b / 2;
}

void Rhombus::Print() {
	std::cout << "Rhombus with diagonales a = " << side_a << ", b = " << side_b;
}

std::ostream & operator<<(std::ostream & os, const Rhombus & right) {
	os << "Rhombus with diagonal a = " << right.side_a << ", diagonal b = " << right.side_b;
	return os;
}

Rhombus::~Rhombus() {}