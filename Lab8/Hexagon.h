#ifndef HEXAGON_H
#define HEXAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Hexagon : public Figure
{
public:
	Hexagon();
	Hexagon(double side_a);
	Hexagon(std::istream &is);
	Hexagon(const Hexagon& orig);

	double Square() override;
	void Print() override;

	friend std::ostream& operator<<(std::ostream& os, const Hexagon& right);

	virtual ~Hexagon();
private:
	double side_a;
};
#endif // !HEXAGON_H