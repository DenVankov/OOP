#ifndef OOP_LAB4_TREE_H
#define OOP_LAB4_TREE_H

#include "Figure.h"
#include "Iterator.h"
#include "Item.h"
#include <stdbool.h>
#include <memory>
#include <cstdint>
#include <future>
#include <thread>
#include <pthread.h>

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

    bool empty();

    void remove(size_t key);
    void remove(std::shared_ptr<TTreeItem<T>> tree, size_t key);

    void Sort();
    void SortParallel();

    template <class A>
    friend std::ostream &operator<<(std::ostream &os, const TTree<A> &tree);

    virtual ~TTree();

private:
    std::future<void> SortInBackground();
    size_t Partition(size_t arr[], size_t low, size_t high);
    void QuickSort(size_t arr[], size_t low, size_t high);
    int GetNodesOnLevel(std::shared_ptr<TTreeItem<T>> item, int level);
    std::shared_ptr<TTreeItem<T>> root;
};

#endif //OOP_LAB4_TREE_H
