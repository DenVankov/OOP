#include <cstdlib>
#include <iostream>
#include "Hexagon.h"
#include "Tree.h"
#include "Item.h"

void help()
{
    std::cout << "Press 1 to get help" << std::endl;
    std::cout << "Press 2 to add figure in tree" << std::endl;
    std::cout << "Press 3 to get a number of nodes on level" << std::endl;
    std::cout << "Press 4 to print tree" << std::endl;
    std::cout << "Press 5 to delete figure from tree" << std::endl;
    std::cout << "Press 0 to exit" << std::endl;
}

int main(int argc, const char * argv[]) {
    help();

    size_t act;
    TTree s;

    while (true) {
        std::cin >> act;
        if (act == 0) break;
        if (act > 6) {
            std::cout << "Error: enter another parameter" << std::endl;
            continue;
        }
        switch (act) {
            case 1: {
                help();
                break;
            }
            case 2: {
                std::cout << "Adding the hexagon" << std::endl;
                std::cout << "Enter side of hexagon: " << std::endl;
                Hexagon obj(std::cin);
                s.Push(obj);
                break;
            }
            case 3: {
                int number = 0;
                std::cout << "Enter level to get a number of nodes" << std::endl;
                std::cin >> number;
                std::cout << "On level " << number << " nodes: " << s.GetNodesOnLevel(number) << std::endl;
                break;
            }
            case 4: {
                std::cout << s << std::endl;
                break;
            }
            case 5: {
                std::cout << "Enter side of hexagon to delete him: " << std::endl;
                int value;
                std::cin >> value;
                s.Pop(value);
                break;
            }
            default: {
                std::cout << "Error, incorrect data" << std::endl;
                break;
            }
        }
    }
    return 0;
}