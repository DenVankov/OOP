#include <iostream>
#include "Tree.h"

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
    return this->root == nullptr;
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


template<class T>
size_t TTree<T>::Partition(size_t *arr, size_t low, size_t high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; high != 0 && j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            //swap(&arr[i], &arr[j]);
            size_t tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    //swap(&arr[i + 1], &arr[high]);
    size_t tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return (i + 1);
}

template<class T>
void TTree<T>::QuickSort(size_t *arr, size_t low, size_t high)
{
    if (low < high)
    {

        size_t pi = Partition(arr, low, high);
        if (pi > 0)
            QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

size_t FutureQuickSort(size_t *arr, size_t left, size_t right)
{
    size_t i = left, j = right;

    size_t tmp;

    size_t pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (i < right) {
        std::packaged_task<size_t(size_t *, size_t, size_t)> task(FutureQuickSort);
        auto result = task.get_future();

        std::thread task_td(std::move(task), std::ref(arr), i, right);
        task_td.join();
        result.get();
    }
    if (left < j) {
        std::packaged_task<size_t(size_t *, size_t, size_t)> task(FutureQuickSort);
        auto result = task.get_future();

        std::thread task_td(std::move(task), std::ref(arr), left, j);
        task_td.join();
        result.get();
    }
    return 0;
}

template <class T>
void TreeGoGet(std::shared_ptr<TTreeItem<T>> item, size_t i, size_t *keys) { //Функция обхода дерева для получения ключей
    if (item) {
        keys[i] = item->GetKey();
        ++i;
        if (item->GetBrother() != nullptr) {
            TreeGoGet(item->GetBrother(), i, keys);
        }
        if (item->GetSon() != nullptr) {
            TreeGoGet(item->GetSon(), i, keys);
        }
    }
}

template <class T>
void TreeGoSet(std::shared_ptr<TTreeItem<T>> item, size_t i, size_t *keys) { //Функция обхода дерева для установки ключей
    if (item) {
        item->SetKey(keys[i]);
        ++i;
        if (item->GetBrother() != nullptr) {
            TreeGoSet(item->GetBrother(), i, keys);
        }
        if (item->GetSon() != nullptr) {
            TreeGoSet(item->GetSon(), i, keys);
        }
    }
}

template<class T>
void TTree<T>::Sort()
{
    /* size_t size = 0;
    for (auto it : *this) {
        size++;
    }
     */
    //std::shared_ptr<TreeItem<T>> * arr = new std::shared_ptr<TreeItem<T>>[size];
    size_t arr[100];
    size_t size = 0;
    TreeGoGet(root , size, arr);

    /*
    auto it = begin();
    for (size_t i = 0; i < size; ++i) {
        arr[i] = it->Print();
        it++;
    }
    */
    //it = begin();
    QuickSort(arr, 0, size - 1);
    TreeGoSet(root, size, arr);
    /*
    for (size_t i = 0; i < size; ++i) {
        it->SetKey(arr[i]);
        it++;
    }
    */
}

template<class T>
void TTree<T>::SortParallel()
{
    /*
    size_t size = 0;
    for (auto it : *this) {
        size++;
    }
    //std::shared_ptr<TreeItem<T>> * arr = new std::shared_ptr<TreeItem<T>>[size];
    size_t arr[100];
    auto it = begin();
    for (size_t i = 0; i < size; ++i) {
        arr[i] = it->GetKey();
        it++;
    }
    */

    size_t arr[100];
    size_t size = 0;
    TreeGoGet(root , size, arr);


    FutureQuickSort(arr, 0, size - 1);
    TreeGoSet(root, size, arr);

    /*
    it = begin();
    for (size_t i = 0; i < size; ++i) {
        it->SetKey(arr[i]);
        it++;
    }
    */
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

