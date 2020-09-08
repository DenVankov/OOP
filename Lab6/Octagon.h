#ifndef OOP_LAB4_OCTAGON_H
#define OOP_LAB4_OCTAGON_H

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include "Figure.h"


class Octagon : public  Figure{
public:
    Octagon();
    Octagon(std::istream &is);
    Octagon(size_t i);
    size_t GetSide() override;
    double  Square() override;
    void Print() override;

    bool operator==(const Octagon &obj) const;
    bool operator!=(const Octagon &obj) const;
    Octagon &operator=(const Octagon &obj);

    friend std::ostream &operator<<(std::ostream &os, const Octagon &obj);
    friend std::istream &operator>>(std::istream &is, Octagon &obj);


    virtual  ~Octagon();

private:
    size_t side_a;

};

#endif //OOP_LAB4_OCTAGON_H
