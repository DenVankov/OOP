#include "TreeItem.h"
#include <iostream>


template<class T>
TreeItem<T>::TreeItem(const std::shared_ptr<T>& figure, size_t key)
{
	this->figure = figure;
	this->key = key;
	this->brother = nullptr;
	this->son = nullptr;
	this->parent = nullptr;
}

template <class T> TAllocationBlock
TreeItem<T>::tree_itemAllocator(sizeof(TreeItem<T>), 100);

template <class T>
TreeItem<T>::TreeItem(const TreeItem<T>& orig)
{
	this->figure = orig.figure;
	this->son = orig.son;
	this->brother = orig.brother;
	this->parent = orig.parent;
}

template<class T>
void * TreeItem<T>::operator new(size_t size)
{
	return tree_itemAllocator.allocate();
}

template<class T>
void TreeItem<T>::operator delete(void * p)
{
	tree_itemAllocator.deallocate(p);
}

template<class T>
std::shared_ptr<TreeItem<T>> TreeItem<T>::getParent()
{
	return this->parent;
}

template <class T>
std::shared_ptr<TreeItem<T>> TreeItem<T>::getSon()
{
	return this->son;
}

template <class T>
std::shared_ptr<TreeItem<T>> TreeItem<T>::getBrother()
{
	return this->brother;
}

template<class T>
void TreeItem<T>::setParent(std::shared_ptr<TreeItem<T>> parent)
{
	this->parent = parent;
}

template <class T>
void TreeItem<T>::setSon(std::shared_ptr<TreeItem<T>> son)
{
	this->son = son;
}

template <class T>
void TreeItem<T>::setBrother(std::shared_ptr<TreeItem<T>> sibling)
{
	this->brother = sibling;
	sibling->parent = this->parent;
}

template <class T>
std::shared_ptr<T> TreeItem<T>::getFigure() const
{
	return this->figure;
}

template <class T>
void TreeItem<T>::setKey(size_t key)
{
	this->key = key;
}

template<class T>
void TreeItem<T>::setFigure(std::shared_ptr<T> figure)
{
	this->figure = figure;
}

template <class T>
size_t TreeItem<T>::getKey() const
{
	return key;
}

template<class T>
void TreeItem<T>::print()
{
	std::cout << "[";
	figure->Print();
	std::cout << ", Square = " << figure->Square() << ", Key = " << key << "]\n";
}

template<class T>
std::shared_ptr<TreeItem<T>> TreeItem<T>::getNext()
{
	std::shared_ptr<TreeItem<T>> tmp;
	if (this->getSon()) {
		return getSon();
	} else if (this->getBrother()) {
		return getBrother();
	} else if (this->getParent()) {
		tmp = this->getParent();

		while (tmp && !(tmp->getBrother())) {
			tmp = tmp->getParent();
		}
		if (!tmp)
			return nullptr;
		tmp = tmp->getBrother();
		return tmp;
	}
	return nullptr;
}

template <class T>
TreeItem<T>::~TreeItem()
{
	//std::cout << "TreeItem deleted" << std::endl;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TreeItem<T>& obj)
{
	//os << "[" << *obj.getFigure() << "]" << ":"<< obj.getKey() << std::endl;
	return os;
}

#include "TreeItem.h"
template class TreeItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TreeItem<Figure>& obj);