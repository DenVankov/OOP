//Ваньков Денис М80-207Б-17
//Вариант 22(дерево, пятиугольник, шестиугольник, восьмиугольник)

#include <cstdlib>
#include <iostream>
#include <memory>

#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Item.h"
#include "Tree.h"


void help(){
    std::cout << "Press 1 to get help" << std::endl;
    std::cout << "Press 2 to add figure in tree" << std::endl;
    std::cout << "Press 3 to get a number of nodes on level" << std::endl;
    std::cout << "Press 4 to print tree" << std::endl;
    std::cout << "Press 5 to delete figure from tree" << std::endl;
    std::cout << "Press 0 to exit" << std::endl;
}

int main(int argc, const char * argv[]) {
    size_t act;
    TTree s;
    help();

    while (true) {
        std::cin >> act;
        if (act == 0) break;
        if (act > 5) {
            std::cout << "Error: enter another parameter (0-5)\n";
            continue;
        }
        switch (act) {
            case 1: {
                help();
                break;
            }
            case 2: {
                size_t type;
                std::cout << "Choose the figure: \n";
                std::cout << "1 - Pentagon\n";
                std::cout << "2 - Hexagon\n";
                std::cout << "3 - Octagon\n";
                std::cin >> type;

                if (type > 0) {
                    if (type > 3) {
                        std::cout << "Error: enter another parameter (0-3)\n";
                        continue;
                    }
                    switch (type) {
                        case 1: {
                            s.Push(std::shared_ptr<TTreeItem> (new TTreeItem (std::shared_ptr <Pentagon>(new Pentagon(std::cin)))));
                            break;
                        }
                        case 2: {
                            s.Push(std::shared_ptr<TTreeItem> (new TTreeItem (std::shared_ptr <Hexagon>(new Hexagon(std::cin)))));
                            break;
                        }
                        case 3: {
                            s.Push(std::shared_ptr<TTreeItem> (new TTreeItem (std::shared_ptr <Octagon>(new Octagon(std::cin)))));
                            break;
                        }
                    }
                }
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
                std::cout << s << "\n";
                break;
            }
            case 5: {
                std::cout << "Enter side of figure to delete it: " << std::endl;
                size_t value;
                std::cin >> value;
                s.Pop(value);
                break;
            }
            default: {
                std::cerr << "Error: incorrect data\n";
                break;
            }
        }
    }
    return 0;
}
