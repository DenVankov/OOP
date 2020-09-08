//Ваньков Денис М80-207Б-17
//Вариант 22(N-дерево, пятиугольник, шестиугольник, восьмиугольник)

#include <cstdlib>
#include <iostream>
#include <memory>
#include <cstdint>

#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Item.h"
#include "Tree.h"
#include "Figure.h"


void help(){
    std::cout << "Press 1 to get help" << std::endl;
    std::cout << "Press 2 to add figure in tree" << std::endl;
    std::cout << "Press 3 to get a number of nodes on level" << std::endl;
    std::cout << "Press 4 to print tree" << std::endl;
    std::cout << "Press 5 to delete figure from tree" << std::endl;
    std::cout << "Press 6 to get demo iterator" << std::endl;
    std::cout << "Press 0 to exit" << std::endl;
}

int main(int argc, const char * argv[]) {
    size_t act;

    TTree<Figure> tree;
    std::shared_ptr<Figure> ptr;
    size_t parentKey;
    size_t key;
    help();

    while (true) {
        std::cin >> act;
        if (act == 0) break;
        if (act > 6) {
            std::cout << "Error: enter another parameter (0-6)\n";
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
                            //tree.Push(std::shared_ptr<TTreeItem<Figure>> (new TTreeItem<Figure> (std::shared_ptr <Pentagon>(new Pentagon(std::cin)))));
                            ptr = std::make_shared<Pentagon>(std::cin);
                            std::cout << "Insert the key of parent and the key of figure:\n";
                            std::cin >> parentKey >> key;
                            tree.Insert(ptr, parentKey, key);
                            break;
                        }
                        case 2: {
                            //tree.Push(std::shared_ptr<TTreeItem<Figure>> (new TTreeItem<Figure> (std::shared_ptr <Hexagon>(new Hexagon(std::cin)))));
                            ptr = std::make_shared<Hexagon>(std::cin);
                            std::cout << "Insert the key of parent and the key of figure:\n";
                            std::cin >> parentKey >> key;
                            tree.Insert(ptr, parentKey, key);
                            break;
                        }
                        case 3: {
                            //tree.Push(std::shared_ptr<TTreeItem<Figure>> (new TTreeItem<Figure> (std::shared_ptr <Octagon>(new Octagon(std::cin)))));
                            ptr = std::make_shared<Octagon>(std::cin);
                            std::cout << "Insert the key of parent and the key of figure:\n";
                            std::cin >> parentKey >> key;
                            tree.Insert(ptr, parentKey, key);
                            break;
                        }
                        default: {
                            std::cerr << "Error: incorrect data\n";
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
                std::cout << "On level " << number << " nodes: " << tree.GetNodesOnLevel(number) << std::endl;
                break;
            }
            case 4: {
                if (tree.empty())
                    std::cout << "Tree is empty" << std::endl;
                else
                    std::cout << tree << "\n";
                break;
            }
            case 5: {
                if (tree.empty())
                    std::cout << "Tree is empty" << std::endl;
                else {
                    std::cout << "Enter the key of figure to delete it:\n";
                    std::cin >> key;
                    tree.remove(key);
                }
                break;
            }
            case 6: {
                if (tree.empty())
                    std::cout << "Tree is empty" << std::endl;
                else {
                    for (auto i : tree) {
                        i->Print();
                        std::cout << std::endl;
                    }
                }
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
