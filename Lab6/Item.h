#ifndef OOP_LAB4_ITEM_H
#define OOP_LAB4_ITEM_H

#include <stdio.h>
#include <memory>
#include "Figure.h"
#include "TAllocationBlock.h"

template <class T>
class TTreeItem {
public:
    TTreeItem(const std::shared_ptr<T> &figure, size_t key);

    template <class A>
    friend std::ostream& operator<<(std::ostream &os, const TTreeItem<A> &obj);

    std::shared_ptr<TTreeItem<T>> GetParent();
    std::shared_ptr<TTreeItem<T>> GetSon();
    std::shared_ptr<TTreeItem<T>> GetBrother();
    std::shared_ptr<T> GetFigure() const;

    size_t GetKey() const;
    void SetKey(size_t key);
    void SetParent(std::shared_ptr<TTreeItem<T>> parent);
    void SetSon(std::shared_ptr<TTreeItem<T>> son);
    void SetBrother(std::shared_ptr<TTreeItem<T>> brother);

    std::shared_ptr<TTreeItem<T>> GetNext();

    void * operator new (size_t size);
    void operator delete(void *p);

    ~TTreeItem();

private:
    std::shared_ptr<T> figure;
    std::shared_ptr<TTreeItem<T>> parent;
    std::shared_ptr<TTreeItem<T>> son;
    std::shared_ptr<TTreeItem<T>> brother;
    size_t key;

    static TAllocationBlock treeItemAllocator;
};

#endif //OOP_LAB4_ITEM_H
