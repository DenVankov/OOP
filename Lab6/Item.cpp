#include <iostream>
#include <cstdlib>

#include "Item.h"


template <class T>
TTreeItem<T>::TTreeItem(const std::shared_ptr<T> &figure, size_t key) {
    this->figure = figure;
    this->son = nullptr;
    this->brother = nullptr;
    this->key = key;

    std::cout << "Tree item: created" << std::endl;
}

template <class T>
std::shared_ptr<TTreeItem<T>> TTreeItem<T>::GetParent() {
    return this->parent;
}

template <class T>
std::shared_ptr<T> TTreeItem<T>::GetFigure() const {
    return this->figure;
}

template <class T>
std::shared_ptr<TTreeItem<T>> TTreeItem<T>::GetSon() {
    return this->son;
}

template <class T>
size_t TTreeItem<T>::GetKey() const {
    return key;
}

template <class T>
void TTreeItem<T>::SetKey(size_t key) {
    this->key = key;
}
template <class T>
void TTreeItem<T>::SetSon(std::shared_ptr<TTreeItem<T>> son) {
    this->son = son;
}

template <class T>
void TTreeItem<T>::SetBrother(std::shared_ptr<TTreeItem<T>> brother) {
    this->brother = brother;
}

template <class T>
void TTreeItem<T>::SetParent(std::shared_ptr<TTreeItem<T>> parent){
    this->parent = parent;
}

template <class T>
std::shared_ptr<TTreeItem<T>> TTreeItem<T>::GetBrother() {
    return this->brother;
}

template <class T>
std::shared_ptr<TTreeItem<T>> TTreeItem<T>::GetNext()
{
    std::shared_ptr<TTreeItem<T>> tmp;
    if (this->GetSon()) {
        return GetSon();
    }
    else if (this->GetBrother()) {
        return GetBrother();
    } else if (this->GetParent()) {
        tmp = this->GetParent();

        while (tmp && !(tmp->GetBrother())) {
            tmp = tmp->GetParent();
        }
        if (!tmp)
            return nullptr;
        tmp = tmp->GetBrother();
        return tmp;
    }
    return nullptr;
}

template <class T>
TTreeItem<T>::~TTreeItem() {}

template <class T> TAllocationBlock
        TTreeItem<T>::treeItemAllocator(sizeof(TTreeItem<T>), 100);

template<class T>
void * TTreeItem<T>::operator new(size_t size)
{
    return treeItemAllocator.Allocate();
}

template<class T>
void TTreeItem<T>::operator delete(void * p)
{
    treeItemAllocator.Deallocate(p);
}

template <class A>
std::ostream& operator<<(std::ostream &os, const TTreeItem<A> &obj) {
    os << "[" << obj.GetFigure()->GetSide() << "]";
    return os;
}

template class TTreeItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TTreeItem<Figure>& obj);
