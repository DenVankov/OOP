#ifndef OOP_LAB1_PENTAGON_H
#define OOP_LAB1_PENTAGON_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class Pentagon : public  Figure{
public:
    Pentagon();
    Pentagon(std::istream &is);
    Pentagon(size_t i);
    Pentagon(const Pentagon& orig);
    double  Square() override;
    void Print() override;

    virtual  ~Pentagon();

private:
    size_t side_a;

};

#endif //OOP_LAB1_PENTAGON_H
