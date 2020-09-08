//Ваньков Денис М80-207Б-17
//Вариант 22(N-дерево, пятиугольник, шестиугольник, восьмиугольник)

#include <cstdlib>
#include <iostream>
#include <string>

#include "Pentagon.h"
#include "Rhombus.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "TreeItem.h"
#include "Tree.h"
#include "Figure.h"
#include <memory>
#include <cstdint>

void help(){
	std::cout << "Press 1 to get help" << std::endl;
	std::cout << "Press 2 to add figure in Tree" << std::endl;
	std::cout << "Press 3 to get a number of nodes on level" << std::endl;
	std::cout << "Press 4 to print Tree" << std::endl;
	std::cout << "Press 5 to delete figure from Tree" << std::endl;
	std::cout << "Press 6 to get demo iterator" << std::endl;
	std::cout << "Press 7 to get demo sort" << std::endl;
	std::cout << "Press 8 to get demo parallel sort" << std::endl;
	std::cout << "Press 0 to exit" << std::endl;
}

/*
int main()
{
	Tree<Figure> Tree;
	std::shared_ptr<TreeItem<Figure>> test;
	std::shared_ptr<Figure> ptr;
	size_t input = 0, key, parentKey;
	std::cout << "Choose an operation:" << std::endl;
	std::cout << "1) Add rhombus" << std::endl;
	std::cout << "2) Add pentagon" << std::endl;
	std::cout << "3) Add hexagon" << std::endl;
	std::cout << "4) Delete node from Tree" << std::endl;
	std::cout << "5) Print Tree" << std::endl;
	std::cout << "6) Exit" << std::endl;
	std::cout << "7) Iterator demo" << std::endl;
	std::cout << "8) Sort demo" << std::endl;
	std::cout << "9) Parallel sort demo" << std::endl;
	std::cout << "0) Help" << std::endl;
	while (input != 6) {
		std::cin >> input;
		if (input == 1) {
			std::cout << "Insert diagonales, key, parent key" << std::endl;
			ptr = std::make_shared<Rhombus>(std::cin);
			std::cin >> key >> parentKey;
			Tree.insert(ptr, parentKey, key);
		}
		else if (input == 2) {
			std::cout << "Insert side, key, parent key" << std::endl;
			ptr = std::make_shared<Pentagon>(std::cin);
			std::cin >> key >> parentKey;
			Tree.insert(ptr, parentKey, key);
		}
		else if (input == 3) {
			std::cout << "Insert side, key, parent key" << std::endl;
			ptr = std::make_shared<Hexagon>(std::cin);
			std::cin >> key >> parentKey;
			Tree.insert(ptr, parentKey, key);
		}
		else if (input == 4) {
			if (!Tree.empty()) {
				std::cin >> key;
				Tree.remove(key);
			}
			else {
				std::cout << "Tree is empty." << std::endl;
			}

		}
		else if (input == 5) {
			if (!Tree.empty())
				Tree.print();
			else {
				std::cout << "Tree is empty." << std::endl;
			}
		}
		else if (input == 7) {
			if (Tree.empty())
				std::cout << "Tree is empty" << std::endl;
			else {
				for (auto i : Tree) {
					i->print();
					std::cout << std::endl;
				}
			}
		}
		else if (input == 8) {
			if (Tree.empty())
				std::cout << "Tree is empty" << std::endl;
			else {
				Tree.sort();
				//Tree.print();
			}
		}
		else if (input == 9) {
			if (Tree.empty())
				std::cout << "Tree is empty" << std::endl;
			else {
				Tree.sortParallel();
				//Tree.print();
			}
		}
		else if (input == 0) {
			std::cout << "1) Add rhombus" << std::endl;
			std::cout << "2) Add pentagon" << std::endl;
			std::cout << "3) Add hexagon" << std::endl;
			std::cout << "4) Delete node from Tree" << std::endl;
			std::cout << "5) Print Tree" << std::endl;
			std::cout << "6) Exit" << std::endl;
			std::cout << "7) Iterator demo" << std::endl;
			std::cout << "8) Sort demo" << std::endl;
			std::cout << "9) Parallel sort demo" << std::endl;
			std::cout << "0) Help" << std::endl;
			std::cin >> input;
		}
		else
			std::cin >> input;
	}

	return 0;
}
*/

int main(int argc, const char * argv[]) {
	size_t act;

	Tree<Figure> tree;
	std::shared_ptr<Figure> ptr;
	size_t parentKey;
	size_t key;
	help();

	while (true) {
		std::cin >> act;
		if (act == 0) break;
		if (act > 8) {
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
							//Tree.Push(std::shared_ptr<TTreeItem<Figure>> (new TTreeItem<Figure> (std::shared_ptr <Pentagon>(new Pentagon(std::cin)))));
							ptr = std::make_shared<Pentagon>(std::cin);
							std::cout << "Insert the key of parent and the key of figure:\n";
							std::cin >> parentKey >> key;
							tree.insert(ptr, parentKey, key);
							break;
						}
						case 2: {
							//Tree.Push(std::shared_ptr<TTreeItem<Figure>> (new TTreeItem<Figure> (std::shared_ptr <Hexagon>(new Hexagon(std::cin)))));
							ptr = std::make_shared<Hexagon>(std::cin);
							std::cout << "Insert the key of parent and the key of figure:\n";
							std::cin >> parentKey >> key;
							tree.insert(ptr, parentKey, key);
							break;
						}
						case 3: {
							//Tree.Push(std::shared_ptr<TTreeItem<Figure>> (new TTreeItem<Figure> (std::shared_ptr <Octagon>(new Octagon(std::cin)))));
							ptr = std::make_shared<Octagon>(std::cin);
							std::cout << "Insert the key of parent and the key of figure:\n";
							std::cin >> parentKey >> key;
							tree.insert(ptr, parentKey, key);
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
			case 3: {/*
				int number = 0;
				std::cout << "Enter level to get a number of nodes" << std::endl;
				std::cin >> number;
				std::cout << "On level " << number << " nodes: " << Tree.GetNodesOnLevel(number) << std::endl;
				*/
				break;
			}
			case 4: {
				if (tree.empty())
					std::cout << "Tree is empty" << std::endl;
				else
					tree.print();
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
						i->print();
						std::cout << std::endl;
					}
				}
				break;
			}
			case 7: {
				if (tree.empty())
					std::cout << "Tree is empty" << std::endl;
				else {
					tree.sort();
				}
				break;
			}
			case  8: {
				if (tree.empty())
					std::cout << "Tree is empty" << std::endl;
				else {
					tree.sortParallel();
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