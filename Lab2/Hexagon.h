#ifndef OOP_LAB2_HEXAGON_H
#define OOP_LAB2_HEXAGON_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"


class Hexagon : public  Figure{
public:
    Hexagon();
    Hexagon(std::istream &is);
    Hexagon(size_t i);
    size_t GetSide();
    double  Square() override;
    void Print() override;

    virtual  ~Hexagon();

private:
    size_t side_a;

};


#endif //OOP_LAB2_HEXAGON_H
