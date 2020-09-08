#include "Pentagon.h"
#include <istream>
#include <cmath>

Pentagon::Pentagon() :Pentagon(0) {

}

Pentagon::Pentagon(size_t i) : side_a(i){
    std::cout << "Pentagon created: " << side_a  << std::endl;
}

double Pentagon::Square() {
    return  1.5 * pow(side_a,2) * sqrt(3);

}
void Pentagon::Print() {
    std::cout << "Pentagon with side a = " << side_a;
}

size_t Pentagon::GetSide(){
    return side_a;
}

Pentagon::~Pentagon() {}

Pentagon::Pentagon(std::istream &is) {
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

Pentagon &Pentagon::operator=(const Pentagon &obj) {
    if (this == &obj) return *this;
    side_a = obj.side_a;
    return *this;
}

bool Pentagon::operator==(const Pentagon &obj) const {
    return side_a == obj.side_a;
}

bool Pentagon::operator!=(const Pentagon &obj) const {
    return side_a != obj.side_a;
}

std::ostream &operator<<(std::ostream &os, const Pentagon &obj) {
    os << "Pentagon with side: " << obj.side_a << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Pentagon &obj) {
    std::cout << "Insert side of Pentagon: \n";
    is >> obj.side_a;
    return is;
}