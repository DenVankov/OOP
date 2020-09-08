#ifndef OOP_LAB4_TALLOCATIONBLOCK_H
#define OOP_LAB4_TALLOCATIONBLOCK_H

#include <iostream>
#include <cstdlib>
#include "TStack.h"

typedef unsigned char Byte;

class TAllocationBlock
{
public:
    TAllocationBlock(size_t size, size_t count);
    void *Allocate();
    void Deallocate(void *ptr);
    bool Empty();
    size_t Size();

    virtual ~TAllocationBlock();

private:
    Byte *_used_blocks;
    TStack<void *>_free_blocks;
};

#endif //OOP_LAB4_TALLOCATIONBLOCK_H
