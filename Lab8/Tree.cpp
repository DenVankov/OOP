#include "Tree.h"

template <class T>
Tree<T>::Tree()
{
	this->root = nullptr;
}

template<class T>
TIterator<TreeItem<T>, T> Tree<T>::begin()
{
	return TIterator<TreeItem<T>, T>(root);
}

template<class T>
TIterator<TreeItem<T>, T> Tree<T>::end()
{
	return TIterator<TreeItem<T>, T>(nullptr);
}

template <class T>
std::shared_ptr<TreeItem<T>> Tree<T>::insert(std::shared_ptr<T> figure, size_t parentKey, size_t key)
{
	std::shared_ptr<TreeItem<T>> node = std::make_shared<TreeItem<T>>(figure, key);
	if (empty()) {
		root = node;
		root->setParent(nullptr);
		std::cout << "Tree was empty. Item was set as root." << std::endl;
		return root;
	}

	std::shared_ptr<TreeItem<T>> parent = find(this->root, parentKey);

	if (!parent) {
		std::cout << "Parent with this key not found." << std::endl;

		if (root->getSon()) {
			std::shared_ptr<TreeItem<T>> tmp = root->getSon();

			while (tmp->getBrother())
				tmp = tmp->getBrother();

			tmp->setBrother(node);
			node->setParent(root);
			return tmp->getBrother();
		} else {
			root->setSon(node);
			node->setParent(root);
			return root->getSon();
		}
	}
	if (parent->getSon()) {
		std::shared_ptr<TreeItem<T>> tmp = parent->getSon();

		while (tmp->getBrother())
			tmp = tmp->getBrother();

		tmp->setBrother(node);
		return tmp->getBrother();
	} else {
		parent->setSon(node);
		node->setParent(parent);
		return parent->getSon();
	}
}


template <class T>
void Tree<T>::remove(size_t key)
{
	if (root->getKey() == key) {
		root = nullptr;
	}
	else {
		remove(root, key);
	}
}


template <class T>
void Tree<T>::remove(std::shared_ptr<TreeItem<T>> node, size_t key)
{
	if (node->getSon()) {
		if (node->getSon()->getKey() == key) {
			std::shared_ptr<TreeItem<T>> tr = node->getSon();
			node->setSon(node->getSon()->getBrother());
			tr->setBrother(nullptr);
			return;
		} else {
			remove(node->getSon(), key);
		}
	}
	if (node->getBrother()) {
		if (node->getBrother()->getKey() == key) {
			std::shared_ptr<TreeItem<T>> tr = node->getBrother();
			node->setBrother(node->getBrother()->getBrother());
			tr->setBrother(nullptr);
			return;
		} else {
			remove(node->getBrother(), key);
		}
	}
}

template <class T>
bool Tree<T>::empty()
{
	return this->root == nullptr;
}

template <class T>
std::shared_ptr<TreeItem<T>> Tree<T>::find(std::shared_ptr<TreeItem<T>> node, size_t key)
{
	std::shared_ptr<TreeItem<T>> tr = nullptr;
	if (node->getKey() == key)
		return node;
	if (node->getSon()) {
		tr = find(node->getSon(), key);
		if (tr != nullptr) {
			return tr;
		}
	}
	if (node->getBrother()) {
		tr = find(node->getBrother(), key);
		if (tr != nullptr) {
			return tr;
		}
	}
	return nullptr;
}

template <class T>
void Tree<T>::print()
{
	this->print(this->root, 0);
}

template<class T>
size_t Tree<T>::partition(size_t array[], size_t low, size_t high)
{
	size_t middle = array[high];    // создаем массив размером равным максимальному значению элемента
	size_t i = (low - 1);  // индекс меньшего элемента

	for (size_t j = low; high != 0 && j <= high - 1; j++)
	{
		if (array[j] <= middle)
		{
			i++;    // Увеличиваем index минимального
			size_t tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	size_t tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	std::cout << i + 1 << std::endl;
	return (i + 1);
}

template <class T>
void Tree<T>::print(std::shared_ptr<TreeItem<T>> tree, size_t spacing)
{
	if (tree)
		for (size_t i = 0; i < spacing; i++)
			std::cout << "\t";
	tree->print();
	if (tree->getSon())
		print(tree->getSon(), spacing + 1);
	if (tree->getBrother())
		print(tree->getBrother(), spacing);
}

template<class T>
void Tree<T>::quickSort(size_t arr[], size_t low, size_t high)
{
	if (low < high)
	{

		size_t pi = partition(arr, low, high);
		if (pi > 0)
			quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

template<class T>
void Tree<T>::sort()
{
	size_t size = 0;
	
	for (auto it : *this) {
		size++;
	}
	
	size_t arr[100];
	auto it = begin();
	
	for (size_t i = 0; i < size; ++i) {
		arr[i] = it->getKey();
		it++;
	}
	
	it = begin();
	quickSort(arr, 0, size - 1);
	
	for (size_t i = 0; i < size; ++i) {
		it->setKey(arr[i]);
		it++;
	}
}

size_t futureQuickSort(size_t *arr, size_t left, size_t right)
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
		std::packaged_task<size_t(size_t *, size_t, size_t)> task(futureQuickSort);
		auto result = task.get_future();

		std::thread task_td(std::move(task), std::ref(arr), i, right);
		task_td.join();
		result.get();
	}
	if (left < j) {
		std::packaged_task<size_t(size_t *, size_t, size_t)> task(futureQuickSort);
		auto result = task.get_future();

		std::thread task_td(std::move(task), std::ref(arr), left, j);
		task_td.join();
		result.get();
	}
	return 0;
}


template<class T>
void Tree<T>::sortParallel()
{
	size_t size = 0;
	for (auto it : *this) {
		size++;
	}

	size_t arr[100];
	auto it = begin();

	for (size_t i = 0; i < size; ++i) {
		arr[i] = it->getKey();
		it++;
	}

	futureQuickSort(arr, 0, size - 1);
	it = begin();

	for (size_t i = 0; i < size; ++i) {
		it->setKey(arr[i]);
		it++;
	}
	
}


template <class T>
Tree<T>::~Tree()
{}




template <class T>
std::ostream & operator<<(std::ostream & os, Tree<T> & obj)
{
	obj.print();
	return os;
}

#include "Figure.h"
template class Tree<Figure>;
//template std::ostream& operator<<(std::ostream& os, const Tree<Figure>& Tree);
