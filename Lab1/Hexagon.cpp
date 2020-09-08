#include "Hexagon.h"
#include <istream>
#include <cmath>

Hexagon::Hexagon() :Hexagon(0) {

}

Hexagon::Hexagon(size_t i) : side_a(i){
    std::cout << "Hexagon created: " << side_a  << std::endl;
}

Hexagon::Hexagon(std::istream &is) {
    int ptr;
    std::cout << "Insert side a:" << std::endl;
    is >> ptr;
    while (ptr < 0) {
        std:: cout << "Please, insert correct data" << std:: endl;
        is >> ptr;
    }
    side_a = ptr;

}

Hexagon::Hexagon(const Hexagon &orig) {
    std::cout << "Hexagon copy created" << std::endl;

    side_a = orig.side_a;
}

double Hexagon::Square() {
    return  1.5 * pow(side_a,2) * sqrt(3);

}
void Hexagon::Print() {
    std::cout << "Side: a = " << side_a << std::endl;
}

Hexagon::~Hexagon() {
    std::cout<<"Hexagon deleted" << std :: endl;
}