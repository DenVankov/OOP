#ifndef OOP_LAB4_FIGURE_H
#define OOP_LAB4_FIGURE_H

#include <stdlib.h>
#include <iostream>
class Figure {
public:
    virtual size_t GetSide() = 0;
    virtual double Square() = 0;
    virtual void Print() = 0;
    virtual  ~Figure(){};

};


#endif //OOP_LAB4_FIGURE_H
