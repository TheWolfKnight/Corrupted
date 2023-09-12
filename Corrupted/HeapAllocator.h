#pragma once

#include "IAllocator.h"

class HeapAllocator : public IAllocator {
public:
    inline explicit HeapAllocator(void) : IAllocator() {}

    template <typename T>
    T* alloc(void);

    virtual bool dealloc(void* target) = 0;
};
