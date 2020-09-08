#include "Octagon.h"
#include <istream>
#include <cmath>

Octagon::Octagon() :Octagon(0) {

}

Octagon::Octagon(size_t i) : side_a(i){
    std::cout << "Octagon created: " << side_a  << std::endl;
}

double Octagon::Square() {
    return  1.5 * pow(side_a,2) * sqrt(3);

}
void Octagon::Print() {
    std::cout << "Octagon with side = " << side_a;
}

size_t Octagon::GetSide(){
    return side_a;
}

Octagon::~Octagon() {}

Octagon::Octagon(std::istream &is) {
    while (true) {
        is >> *this;
        if (std::cin.peek() == '\n') {
            std::cin.get();
            break;
        }
        else {
            std::cerr << "Error: insert data" << "\n";
            std::cin.clear();
            while (std::cin.get() != '\n') {}
        }
    }
}

Octagon &Octagon::operator=(const Octagon &obj) {
    if (this == &obj) return *this;
    side_a = obj.side_a;
    return *this;
}

bool Octagon::operator==(const Octagon &obj) const {
    return side_a == obj.side_a;
}

bool Octagon::operator!=(const Octagon &obj) const {
    return side_a != obj.side_a;
}

std::ostream &operator<<(std::ostream &os, const Octagon &obj) {
    os << "Octagon with side: " << obj.side_a << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Octagon &obj) {
    std::cout << "Insert side of Octagon: \n";
    is >> obj.side_a;
    return is;
}