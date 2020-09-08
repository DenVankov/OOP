#ifndef OOP_LAB2_ITEM_H
#define OOP_LAB2_ITEM_H

#include "Hexagon.h"
class TTreeItem {
public:
    TTreeItem(const Hexagon& hexagon);
    TTreeItem(const TTreeItem &orig);
    friend std::ostream& operator<<(std::ostream &os, const TTreeItem &obj);

    TTreeItem*& GetSon();
    TTreeItem*& GetBrother();
    Hexagon GetHexagon() const;

    virtual ~TTreeItem();
private:
    Hexagon hexagon;
    TTreeItem *son;
    TTreeItem *brother;
};


#endif //OOP_LAB2_ITEM_H
