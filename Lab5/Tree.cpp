#include <iostream>
#include "Tree.h"
#include "Item.h"
#include "Figure.h"

template <class T>
TTree<T>::TTree() {
    this->root = nullptr;
}

template <class T>
TIterator<TTreeItem<T>, T> TTree<T>::begin() {
    return TIterator<TTreeItem<T>, T>(root);
}

template <class T>
TIterator<TTreeItem<T>, T> TTree<T>::end() {
    return TIterator<TTreeItem<T>, T>(nullptr);
}

template <class T>
void TreeDel(std::shared_ptr<TTreeItem<T>> item) {  // Деструктор для дерева
    if(item) {
        TreeDel(item->GetBrother());
        TreeDel(item->GetSon());
        item.reset();
    }
}

template <class T>
TTree<T>::~TTree() {
    TreeDel(root);
    std::cout << "Tree deleted" << std::endl;
}

template <class T>
int TTree<T>::GetNodesOnLevel(std::shared_ptr<TTreeItem<T>> item, int level) {    //Функция показывающаю, сколько элементов на определенном уровне
    if (item == nullptr) return 0;

    if (level <= 0) return 0;

    return GetNodesOnLevel(item->GetSon(), level - 1)  + (level == 1) + GetNodesOnLevel(item->GetBrother(), level);
}

template <class T>
bool TTree<T>::empty() {
    return root == nullptr;
}

template <class T>
std::shared_ptr<TTreeItem<T>> TTree<T>::Find(std::shared_ptr<TTreeItem<T>> node, size_t key) {
    std::shared_ptr<TTreeItem<T>> tr = nullptr;
    if (node->GetKey() == key)
        return node;

    if (node->GetSon()) {
        tr = Find(node->GetSon(), key);
        if (tr != nullptr) {
            return tr;
        }
    }

    if (node->GetBrother()) {
        tr = Find(node->GetBrother(), key);

        if (tr != nullptr) {
            return tr;
        }
    }
    return nullptr;
}


template <class T>
std::shared_ptr<TTreeItem<T>> TTree<T>::Insert(std::shared_ptr<T> figure, size_t parentKey, size_t key) {
    std::shared_ptr<TTreeItem<T>> node = std::make_shared<TTreeItem<T>>(figure, key);
    if (empty()) {
        root = node;
        root->SetParent(nullptr);
        std::cout << "Tree was empty. Item was set as root." << std::endl;
        return root;
    }
    std::shared_ptr<TTreeItem<T>> parent = Find(this->root, parentKey);
    if (!parent) {
        std::cout << "Parent with this key not found." << std::endl;
        if (root->GetSon()) {
            std::shared_ptr<TTreeItem<T>> tmp = root->GetSon();

            while (tmp->GetBrother())
                tmp = tmp->GetBrother();

            tmp->SetBrother(node);
            node->SetParent(root);
            return tmp->GetBrother();
        } else {
            root->SetSon(node);
            node->SetParent(root);
            return root->GetSon();
        }
    }

    if (parent->GetSon()) {
        std::shared_ptr<TTreeItem<T>> tmp = parent->GetSon();
        while (tmp->GetBrother())
            tmp = tmp->GetBrother();
        tmp->SetBrother(node);
        return tmp->GetBrother();
    } else {
        parent->SetSon(node);
        node->SetParent(parent);
        return parent->GetSon();
    }
}

template <class T>
std::shared_ptr<TTreeItem<T>> TTree<T>::Push(std::shared_ptr<TTreeItem<T>> item)
{
    if (this->empty()) {
        this->root = item;
        return this->root;
    } else {
        if (root->GetSon()) {
            std::shared_ptr<TTreeItem<T>> tmp = root->GetSon();
            while (tmp->GetBrother())
                tmp = tmp->GetBrother();
            tmp->SetBrother(item);
            return tmp->GetBrother();
        }
        else {
            root->SetSon(item);
            return root->GetSon();
        }
    }
}

template <class T>
TTreeItem<T> *destroy_Tree(std::shared_ptr<TTreeItem<T>> pointer) {
    if(pointer == nullptr) {
        return nullptr;
    }

    if (pointer->GetSon() != nullptr) {
        destroy_Tree(pointer->GetSon());
    }

    if (pointer->GetBrother() != nullptr) {
        destroy_Tree(pointer->GetBrother());
    }

    if (pointer->GetSon() == nullptr && pointer->GetBrother() == nullptr) {
        pointer.reset();
        pointer = nullptr;
    }
    return nullptr;
}

template <class T>
void TTree<T>::remove(size_t key)
{
    if (root->GetKey() == key) {
        root = nullptr;
    }
    else {
        remove(root, key);
    }
}


template <class T>
void TTree<T>::remove(std::shared_ptr<TTreeItem<T>> node, size_t key) {
    if (node->GetSon()) {
        if (node->GetSon()->GetKey() == key) {
            std::shared_ptr<TTreeItem<T>> tr = node->GetSon();
            node->SetSon(node->GetSon()->GetBrother());
            tr->SetBrother(nullptr);
            return;
        } else {
            remove(node->GetSon(), key);
        }
    }

    if (node->GetBrother()) {
        if (node->GetBrother()->GetKey() == key) {
            std::shared_ptr<TTreeItem<T>> tr = node->GetBrother();
            node->SetBrother(node->GetBrother()->GetBrother());
            tr->SetBrother(nullptr);
            return;
        } else {
            remove(node->GetBrother(), key);
        }
    }
}


template <class T>
void TTree<T>::Pop(size_t value) // Вызов функции удаления
{
    if (root->GetFigure()->GetSide() == value) {
        root = nullptr;
    }
    else {
        Pop(root, value);
    }
}

template <class T>
void TTree<T>::Pop(std::shared_ptr<TTreeItem<T>> item, size_t value) // Удаление элемента из дерева
{
    if (item->GetSon()) {
        if (item->GetSon()->GetFigure()->GetSide() == value) {
            std::shared_ptr<TTreeItem<T>> ptr = item->GetSon();
            item->SetSon(item->GetSon()->GetBrother());
            ptr->SetBrother(nullptr);
            return;
        }
        else {
            Pop(item->GetSon(), value);
        }
    }
    if (item->GetBrother()) {
        if (item->GetBrother()->GetFigure()->GetSide() == value) {
            std::shared_ptr<TTreeItem<T>> ptr = item->GetBrother();
            item->SetBrother(item->GetBrother()->GetBrother());
            ptr->SetBrother(nullptr);
            return;
        }
        else {
            Pop(item->GetBrother(), value);
        }
    }
}


void TSpace(size_t n){ // Функция расставляющая пробелы
    for (size_t i=0;i<=n;i++)
        std::cout << "    ";
}

template <class T>
void TreeRun(std::ostream &os, std::shared_ptr<TTreeItem<T>> item, size_t space){ //Функция обхода дерева для печати
    if (item) {
        TSpace(space);
        //os << *item << std::endl;
        std::cout << "[";
        item->GetFigure()->Print();
        std::cout << " , key = " << item->GetKey() << "]" << "\n";
        if (item->GetBrother() != nullptr) {
            TreeRun(os, item->GetBrother(),space);
        }
        if (item->GetSon() != nullptr) {
            TreeRun(os, item->GetSon(),space+1);
        }
    }
}

template <class A>
std::ostream& operator<<(std::ostream &os, const TTree<A> &tree) { //Оператор вывода дерева
    std::shared_ptr<TTreeItem<A>> obj = tree.root;
    os << "Printed tree:" << std::endl;
    TreeRun(os, obj,1);
    return os;
}

template class TTree<Figure>;
template std::ostream &operator<<(std::ostream &os, const TTree<Figure> &obj);

