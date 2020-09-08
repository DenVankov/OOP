#ifndef OOP_LAB1_OCTAGON_H
#define OOP_LAB1_OCTAGON_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class Octagon : public  Figure{
public:
    Octagon();
    Octagon(std::istream &is);
    Octagon(size_t i);
    Octagon(const Octagon& orig);
    double  Square() override;
    void Print() override;

    virtual  ~Octagon();

private:
    size_t side_a;

};

#endif //OOP_LAB1_OCTAGON_H
