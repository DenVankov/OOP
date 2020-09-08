#include <iostream>
#include "Tree.h"
#include "Item.h"
#include "Figure.h"

TTree::TTree() {
    this->root = nullptr;
}

void TreeDel(std::shared_ptr<TTreeItem> item) {  // Деструктор для дерева
    if(item) {
        TreeDel(item->GetBrother());
        TreeDel(item->GetSon());
        item.reset();
    }
}

TTree::~TTree() {
    TreeDel(root);
    std::cout << "Tree deleted" << std::endl;
}

int TTree::GetNodesOnLevel(std::shared_ptr<TTreeItem> item, int level) {    //Функция показывающаю, сколько элементов на определенном уровне
    if (item == nullptr) return 0;

    if (level <= 0) return 0;

    return GetNodesOnLevel(item->GetSon(), level - 1)  + (level == 1) + GetNodesOnLevel(item->GetBrother(), level);
}

bool TTree::empty() {
    return root == nullptr;
}

std::shared_ptr<TTreeItem> TTree::Push(std::shared_ptr<TTreeItem> item)
{
    if (this->empty()) {
        this->root = item;
        return this->root;
    } else {
        if (root->GetSon()) {
            std::shared_ptr<TTreeItem> tmp = root->GetSon();
            while (tmp->GetBrother())
                tmp = tmp->GetBrother();
            tmp->SetBrother(item);
            return tmp->GetBrother();
        }
        else {
            root->SetSon(item);
            return root->GetSon();
        }
    }
}

std::shared_ptr<TTreeItem> tree_find_parent(std::shared_ptr<TTreeItem> item, int value) { //функция по поиску предка по значению
    if (item == nullptr) {
        return nullptr;
    }
    if(item->GetFigure()->GetSide() == value) {
        return item;
    }
    std::shared_ptr<TTreeItem> parent_node = tree_find_parent(item->GetSon(), value);
    if (parent_node == nullptr) {
       parent_node = tree_find_parent(item->GetBrother(), value);
    }
    return parent_node;
}

int tree_find_parent1(std::shared_ptr<TTreeItem> item, int value) { // Функция поиска предка по указателю на значение
    int idx = 0;
    if (item->GetFigure()->GetSide() == value) {
        return 1;
    }
    if (item->GetSon() != nullptr){
        idx = tree_find_parent1(item->GetSon() , value);
    }
    if (item->GetBrother() != nullptr){
        idx = tree_find_parent1(item->GetBrother(), value);
    }

    if (idx == 1) {
        item->GetBrother().reset();
        item->GetBrother() = nullptr;
        idx = 0;
    }
    return 0;
}

void split(std::shared_ptr<TTreeItem> item) {  //Функция для переприсваивания брата (перескок)
    std::shared_ptr<TTreeItem> tmp = item->GetBrother();
    item->GetSon() = tmp->GetSon();
    item->GetFigure() = tmp->GetFigure();
    item->GetBrother() = tmp->GetBrother();
    tmp.reset();
    tmp = nullptr;
}

TTreeItem *destroy_Tree(std::shared_ptr<TTreeItem> pointer) {
    if(pointer == nullptr) {
        return nullptr;
    }

    if (pointer->GetSon() != nullptr) {
        destroy_Tree(pointer->GetSon());
    }

    if (pointer->GetBrother() != nullptr) {
        destroy_Tree(pointer->GetBrother());
    }

    if (pointer->GetSon() == nullptr && pointer->GetBrother() == nullptr) {
        pointer.reset();
        pointer = nullptr;
    }
    return nullptr;
}

void TTree::Pop(size_t value)
{
    if (root->GetFigure()->GetSide() == value) {
        root = nullptr;
    }
    else {
        Pop(root, value);
    }
}

void TTree::Pop(std::shared_ptr<TTreeItem> item, size_t value)
{
    if (item->GetSon()) {
        if (item->GetSon()->GetFigure()->GetSide() == value) {
            std::shared_ptr<TTreeItem> ptr = item->GetSon();
            item->SetSon(item->GetSon()->GetBrother());
            ptr->SetBrother(nullptr);
            return;
        }
        else {
            Pop(item->GetSon(), value);
        }
    }
    if (item->GetBrother()) {
        if (item->GetBrother()->GetFigure()->GetSide() == value) {
            std::shared_ptr<TTreeItem> ptr = item->GetBrother();
            item->SetBrother(item->GetBrother()->GetBrother());
            ptr->SetBrother(nullptr);
            return;
        }
        else {
            Pop(item->GetBrother(), value);
        }
    }
}


void TSpace(size_t n){ // Функция расставляющая пробелы
    for (size_t i=0;i<=n;i++)
        std::cout << "    ";
}

void TreeRun(std::ostream &os, std::shared_ptr<TTreeItem> item, size_t space){ //Функция обхода дерева для печати
    if (item) {
        TSpace(space);
        //os << *item << std::endl;
        std::cout << "[";
        item->GetFigure()->Print();
        std::cout << "]" << "\n";
        if (item->GetBrother() != nullptr) {
            TreeRun(os, item->GetBrother(),space);
        }
        if (item->GetSon() != nullptr) {
            TreeRun(os, item->GetSon(),space+1);
        }
    }
}

std::ostream& operator<<(std::ostream &os, const TTree &tree) { //Оператор вывода дерева
    std::shared_ptr<TTreeItem> obj = tree.root;
    os << "Printed tree:" << std::endl;
    TreeRun(os, obj,1);
    return os;
}