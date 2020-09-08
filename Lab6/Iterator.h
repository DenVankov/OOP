#ifndef OOP_LAB4_ITERATOR_H
#define OOP_LAB4_ITERATOR_H

#include <memory>
#include <iostream>

template <class N, class T>
class TIterator
{
public:
    TIterator(std::shared_ptr<N> n) {
        cur = n;
    }

    std::shared_ptr<T> operator* () {
        return cur->GetFigure();
    }

    std::shared_ptr<T> operator-> () {
        return cur->GetFigure();
    }

    void operator++() {
        cur = cur->GetNext();
    }

    TIterator const operator++ (int) {
        TIterator cur(*this);
        ++(*this);
        return cur;
    }

    bool operator== (const TIterator &it) {
        return (cur == it.cur);
    }

    bool operator!= (const TIterator &it) {
        return (cur != it.cur);
    }

private:
    std::shared_ptr<N> cur;
};

#endif //OOP_LAB4_ITERATOR_H
