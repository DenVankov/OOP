#include <iostream>
#include <cstdlib>

#include "Item.h"
#include "Figure.h"

TTreeItem::TTreeItem(const std::shared_ptr<Figure> &figure) {
    this->figure = figure;
    this->son = nullptr;
    this->brother = nullptr;
    std::cout << "Tree item: created" << std::endl;
}

std::shared_ptr<Figure> TTreeItem::GetFigure() const {
    return this->figure;
}

std::shared_ptr<TTreeItem> TTreeItem::GetSon() {
    return this->son;
}

void TTreeItem::SetSon(std::shared_ptr<TTreeItem> son) {
    this->son = son;
}

void TTreeItem::SetBrother(std::shared_ptr<TTreeItem> brother) {
    this->brother = brother;
}

std::shared_ptr<TTreeItem> TTreeItem::GetBrother() {
    return this->brother;
}

TTreeItem::~TTreeItem() {
    std::cout << "Tree item: deleted" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const TTreeItem &obj) {
    os << "[" << obj.GetFigure() << " " << obj.GetFigure()->Square() << "]";
    return os;
}