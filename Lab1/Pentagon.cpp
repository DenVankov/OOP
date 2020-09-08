#include "Pentagon.h"
#include <istream>
#include <cmath>

Pentagon::Pentagon() :Pentagon(0) {

}

Pentagon::Pentagon(size_t i) : side_a(i){
        std::cout << "Pentagon created: " << side_a << std::endl;
}

Pentagon::Pentagon(std::istream &is) {
    int ptr;
    std::cout << "Insert side a:" << std::endl;
    is >> ptr;
    while (ptr < 0) {
        std:: cout << "Please, insert correct data" << std:: endl;
        is >> ptr;
    }
    side_a = ptr;
}

Pentagon::Pentagon(const Pentagon &orig) {
    std::cout << "Pentagon copy created" << std::endl;

    side_a = orig.side_a;
}

double Pentagon::Square() {
    return  pow(side_a,2) * 0.25 * sqrt(25 + 10 * sqrt(5));
}
void Pentagon::Print() {
    std::cout << "Side: a = " << side_a << std::endl;
}

Pentagon::~Pentagon()  {
    std::cout<<"Pentagon deleted" << std :: endl;
}
