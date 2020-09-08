#ifndef OOP_LAB3_ITEM_H
#define OOP_LAB3_ITEM_H

#include <stdio.h>
#include <memory>
#include "Figure.h"

class TTreeItem {
public:
    TTreeItem(const std::shared_ptr<Figure> &figure);
    friend std::ostream& operator<<(std::ostream &os, const TTreeItem &obj);

    std::shared_ptr<TTreeItem> GetSon();
    std::shared_ptr<TTreeItem> GetBrother();
    void SetSon(std::shared_ptr<TTreeItem> son);
    void SetBrother(std::shared_ptr<TTreeItem> brother);
    std::shared_ptr<Figure> GetFigure() const;


    virtual ~TTreeItem();
private:
    std::shared_ptr<Figure> figure;
    std::shared_ptr<TTreeItem> son;
    std::shared_ptr<TTreeItem> brother;
};

#endif //OOP_LAB3_ITEM_H