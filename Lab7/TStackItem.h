#ifndef OOP_LAB4_TSTACKITEM_H
#define OOP_LAB4_TSTACKITEM_H

#include <iostream>
#include <memory>

template <class T>
class TStackItem
{
public:
    TStackItem(const T &val, TStackItem<T> *item);
    virtual ~TStackItem();

    void Push(const T &val);
    T &Pop() const;
    void SetNext(TStackItem<T> *item);
    TStackItem<T> &GetNext() const;

private:
    T *value;
    TStackItem<T> *next;
};

#endif //OOP_LAB4_TSTACKITEM_H
