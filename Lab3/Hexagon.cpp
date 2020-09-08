#include "Hexagon.h"
#include <istream>
#include <cmath>

Hexagon::Hexagon() :Hexagon(0) {

}

Hexagon::Hexagon(size_t i) : side_a(i){
    std::cout << "Hexagon created: " << side_a  << std::endl;
}

double Hexagon::Square() {
    return  1.5 * pow(side_a,2) * sqrt(3);

}
void Hexagon::Print() {
    std::cout << "Hexagon with side = " << side_a;
}

size_t Hexagon::GetSide(){
    return side_a;
}

Hexagon::~Hexagon() {}


Hexagon::Hexagon(std::istream &is) {
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

Hexagon &Hexagon::operator=(const Hexagon &obj) {
    if (this == &obj) return *this;
    side_a = obj.side_a;
    return *this;
}

bool Hexagon::operator==(const Hexagon &obj) const {
    return side_a == obj.side_a;
}

bool Hexagon::operator!=(const Hexagon &obj) const {
    return side_a != obj.side_a;
}

std::ostream &operator<<(std::ostream &os, const Hexagon &obj) {
    os << "Hexagon with side: " << obj.side_a << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Hexagon &obj) {
    std::cout << "Insert side of Hexagon: \n";
    is >> obj.side_a;
    return is;
}