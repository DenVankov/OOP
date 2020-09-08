// Ваньков Денис
// M8о-207Б
// Лабораторная работа 1, Необходимо спроектировать и запрограммировать на языке C++ классы фигур, согласно варианту задания.
// Вариант 14: 5-угольник, 6-угольник, 8-угольник
#include <iostream>
#include <cstdlib>
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"

void help()
{
    std::cout << "Press 0 to get help" << std::endl;
    std::cout << "Press 1 to work with Pentagon" << std::endl;
    std::cout << "Press 2 to work with Hexagon" << std::endl;
    std::cout << "Press 3 to work with Octagon" << std::endl;
    std::cout << "Press 4 to exit" << std::endl;
}

int main() {

    help();
    int k;
    while(std::cin >> k)
    {
        if (k == 0) {
            help();
        }

        if (k == 1) {
            Figure *ptr = new Pentagon(std::cin);
            ptr->Print();
            std::cout << "Square = " << ptr->Square() << std::endl;
            delete ptr;
        }

        if(k == 2) {
            Figure *ptr = new Hexagon(std::cin);
            ptr->Print();
            std::cout << "Square = " << ptr->Square() << std::endl;
            delete ptr;
        }

        if(k == 3) {
            Figure *ptr = new Octagon(std::cin);
            ptr->Print();
            std::cout << "Square = " << ptr->Square() << std::endl;
            delete ptr;
        }

        if(k == 4) {
            break;
        }
    }
    return 0;
}