#ifndef TREE_ITEM_H
#define TREE_ITEM_H
#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "AllocationBlock.h"
#include <memory>

template <class T> class TreeItem
{
public:
	TreeItem(const std::shared_ptr<T>& figure, size_t key);
	TreeItem(const TreeItem& orig);

	void * operator new (size_t size);
	void operator delete(void *p);

	std::shared_ptr<TreeItem<T>> getParent();
	std::shared_ptr<TreeItem<T>> getSon();
	std::shared_ptr<TreeItem<T>> getBrother();
	size_t getKey() const;
	std::shared_ptr<T> getFigure() const;

	void setParent(std::shared_ptr<TreeItem<T>> parent);
	void setSon(std::shared_ptr<TreeItem<T>> son);
	void setBrother(std::shared_ptr<TreeItem<T>> sibling);
	void setKey(size_t key);
	void setFigure(std::shared_ptr<T> figure);

	void print();


	template <class A> friend std::ostream& operator<<(std::ostream& os, const TreeItem<A>& obj);

	std::shared_ptr<TreeItem<T>> getNext();

	~TreeItem();
private:
	std::shared_ptr<TreeItem<T>> son;
	std::shared_ptr<TreeItem<T>> parent;
	std::shared_ptr<TreeItem<T>> brother;
	std::shared_ptr<T> figure;
	size_t key;

	static TAllocationBlock tree_itemAllocator;
};


#endif // !TREE_ITEM_H
