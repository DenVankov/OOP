#include <iostream>
#include <cstdlib>

#include "Item.h"
#include "Hexagon.h"

TTreeItem::TTreeItem(const Hexagon& hexagon) {
    this->hexagon = hexagon;
    this->son = nullptr;
    this->brother = nullptr;
    std::cout << "Tree item: created" << std::endl;
}

TTreeItem::TTreeItem(const TTreeItem &orig) {
    this->hexagon = orig.hexagon;
    this->son = orig.son;
    this->brother = orig.brother;
    std::cout << "Tree item: copied" << std::endl;
}

void TTreeItem::SetItem(Hexagon &hexagon) {
    this->hexagon = hexagon;
    this->son = nullptr;
    this->brother = nullptr;
}

Hexagon TTreeItem::GetHexagon() const {
    return this->hexagon;
}

TTreeItem*& TTreeItem::GetSon() {
    return this->son;
}

TTreeItem*& TTreeItem::GetBrother() {
    return this->brother;
}

TTreeItem::~TTreeItem() {
    std::cout << "Tree item: deleted" << std::endl;
    son = nullptr;
    brother = nullptr;
}

std::ostream& operator<<(std::ostream &os, const TTreeItem &obj) {
    os << "[" << obj.GetHexagon().GetSide() << "]";
    return os;
}