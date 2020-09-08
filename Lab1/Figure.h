#ifndef OOP_LAB1_FIGURE_H
#define OOP_LAB1_FIGURE_H

class Figure {
public:
    virtual double Square() = 0;
    virtual void Print() = 0;
    virtual  ~Figure(){};
};


#endif //OOP_LAB1_FIGURE_H
