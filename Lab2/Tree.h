#ifndef OOP_LAB2_TREE_H
#define OOP_LAB2_TREE_H

#include "Hexagon.h"
#include "Item.h"
#include <stdbool.h>

class TTree{
public:
    TTree();
    TTree(const TTree &orig);

    int GetNodesOnLevel(int level) {
        return GetNodesOnLevel(root, level);
    }

    void Push(Hexagon &obj) {
        Push(root, obj);
    }

    void Pop(int value){
        Pop(&root, value);
    }
    friend std::ostream &operator<<(std::ostream &os, const TTree &tree);

    virtual ~TTree();

private:
    void Push(TTreeItem *&item, Hexagon &hexagon);
    void Pop(TTreeItem **item, int value);
    int GetNodesOnLevel(TTreeItem* item, int level);
    TTreeItem* root;
};
#endif //OOP_LAB2_TREE_H
