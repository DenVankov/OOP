#ifndef OOP_LAB4_HEXAGON_H
#define OOP_LAB4_HEXAGON_H

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include "Figure.h"


class Hexagon : public  Figure{
public:
    Hexagon();
    Hexagon(std::istream &is);
    Hexagon(size_t i);
    size_t GetSide() override;
    double  Square() override;
    void Print() override;

    bool operator==(const Hexagon &obj) const;
    bool operator!=(const Hexagon &obj) const;
    Hexagon &operator=(const Hexagon &obj);

    friend std::ostream &operator<<(std::ostream &os, const Hexagon &obj);
    friend std::istream &operator>>(std::istream &is, Hexagon &obj);


    virtual  ~Hexagon();

private:
    size_t side_a;

};

#endif //OOP_LAB4_HEXAGON_H
