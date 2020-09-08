#ifndef OOP_LAB4_TREE_H
#define OOP_LAB4_TREE_H

#include "Figure.h"
#include "Iterator.h"
#include "Item.h"
#include <stdbool.h>
#include <memory>
#include <cstdint>


template <class T> class TTree{
public:
    TTree();

    int GetNodesOnLevel(int level) {
        return GetNodesOnLevel(root, level);
    }

    TIterator<TTreeItem<T>, T> begin();
    TIterator<TTreeItem<T>, T> end();

    std::shared_ptr<TTreeItem<T>> Insert(std::shared_ptr<T> figure, size_t parentKey, size_t key);
    std::shared_ptr<TTreeItem<T>> Find(std::shared_ptr<TTreeItem<T>> tree, size_t key);
    std::shared_ptr<TTreeItem<T>> Push(std::shared_ptr<TTreeItem<T>> item);

    bool empty();

    void remove(size_t key);
    void remove(std::shared_ptr<TTreeItem<T>> tree, size_t key);

    void Pop(size_t value);
    void Pop(std::shared_ptr<TTreeItem<T>> tree, size_t value);

    template <class A>
    friend std::ostream &operator<<(std::ostream &os, const TTree<A> &tree);

    virtual ~TTree();

private:
    int GetNodesOnLevel(std::shared_ptr<TTreeItem<T>> item, int level);
    std::shared_ptr<TTreeItem<T>> root;
};

#endif //OOP_LAB4_TREE_H
