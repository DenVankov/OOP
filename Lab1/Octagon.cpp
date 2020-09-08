#include "Octagon.h"
#include <istream>
#include <cmath>

Octagon::Octagon() :Octagon(0) {

}

Octagon::Octagon(size_t i) : side_a(i){
    std::cout << "Octagon created: " << side_a  << std::endl;
}

Octagon::Octagon(std::istream &is) {
    int ptr;
    std::cout << "Insert side a:" << std::endl;
    is >> ptr;
    while (ptr < 0) {
        std:: cout << "Please, insert correct data" << std:: endl;
        is >> ptr;
    }
    side_a = ptr;

}

Octagon::Octagon(const Octagon &orig) {
    std::cout << "Octagon copy created" << std::endl;

    side_a = orig.side_a;
}

double Octagon::Square() {
    return  2 * pow(side_a,2) * (1 + sqrt(2));

}
void Octagon::Print() {
    std::cout << "Side: a = " << side_a << std::endl;
}

Octagon::~Octagon() {
    std::cout<<"Octagon deleted" << std :: endl;
}