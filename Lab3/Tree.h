#ifndef OOP_LAB3_TREE_H
#define OOP_LAB3_TREE_H

#include "Figure.h"
#include "Item.h"
#include <stdbool.h>
#include <memory>

class TTree{
public:
    TTree();

    int GetNodesOnLevel(int level) {
        return GetNodesOnLevel(root, level);
    }

    std::shared_ptr<TTreeItem> Push(std::shared_ptr<TTreeItem> item);
    bool empty();

    void Pop(int value){
        Pop(root, value);
    }
    void Pop(size_t value);
    void Pop(std::shared_ptr<TTreeItem> tree, size_t value);

    friend std::ostream &operator<<(std::ostream &os, const TTree &tree);

    virtual ~TTree();

private:
    void Pop(std::shared_ptr<TTreeItem> item, int value);
    int GetNodesOnLevel(std::shared_ptr<TTreeItem> item, int level);
    std::shared_ptr<TTreeItem> root;
};

#endif //OOP_LAB3_TREE_H