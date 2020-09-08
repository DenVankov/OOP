#ifndef ITERATOR_H
#define ITERATOR_H
#include <memory>
#include <iostream>

template <class N, class T>
class TIterator
{
public:
	TIterator(std::shared_ptr<N> n) {
		cur = n;
	}

	std::shared_ptr<N> operator* () {
		//return cur->getFigure();
		return cur;
	}

	std::shared_ptr<N> operator-> () {
		//return cur->getFigure();
		return cur;
	}

	void operator++() {
		cur = cur->getNext();
	}

	TIterator operator++ (int) {
		TIterator cur(*this);
		++(*this);
		return cur;
	}

	bool operator== (const TIterator &i) {
		return (cur == i.cur);
	}

	bool operator!= (const TIterator &i) {
		return (cur != i.cur);
	}

private:
	std::shared_ptr<N> cur;
};
#endif // !ITERATOR_H
