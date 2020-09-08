#ifndef OOP_LAB4_PENTAGON_H
#define OOP_LAB4_PENTAGON_H

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include "Figure.h"


class Pentagon : public  Figure{
public:
    Pentagon();
    Pentagon(std::istream &is);
    Pentagon(size_t i);
    size_t GetSide() override;
    double  Square() override;
    void Print() override;

    bool operator==(const Pentagon &obj) const;
    bool operator!=(const Pentagon &obj) const;
    Pentagon &operator=(const Pentagon &obj);

    friend std::ostream &operator<<(std::ostream &os, const Pentagon &obj);
    friend std::istream &operator>>(std::istream &is, Pentagon &obj);


    virtual  ~Pentagon();

private:
    size_t side_a;

};

#endif //OOP_LAB4_PENTAGON_H
