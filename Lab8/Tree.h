#ifndef TREE_H
#define TREE_H
#include "TreeItem.h"
#include "iterator.h"
#include <memory>
#include <mutex>
#include <future>

template <class T> class Tree
{
public:
	Tree();

	TIterator<TreeItem<T>, T> begin();
	TIterator<TreeItem<T>, T> end();

	std::shared_ptr<TreeItem<T>> insert(std::shared_ptr<T> figure, size_t parentKey, size_t key);
	void remove(size_t key);
	void remove(std::shared_ptr<TreeItem<T>> tree, size_t key);
	bool empty();
	std::shared_ptr<TreeItem<T>> find(std::shared_ptr<TreeItem<T>> tree, size_t key);

	void print();
	void print(std::shared_ptr<TreeItem<T>> tree, size_t spacing);

	//template <class A> friend std::ostream& operator<<(std::ostream& os, const Tree<A> & obj);

	void sort();
	void sortParallel();

	~Tree();
private:
//	std::future<void> sortInBackground();
	size_t partition(size_t array[], size_t low, size_t high);
	void quickSort(size_t arr[], size_t low, size_t high);
	std::shared_ptr<TreeItem<T>> root;
};


#endif // !TREE_H