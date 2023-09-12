#pragma once

class IAllocator {
public:
    template <typename T>
    T* alloc(void);
    virtual bool dealloc(void* target) = 0;
};
