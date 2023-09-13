#pragma once

#include <cstdint>

class IAllocator {
public:
    template <typename T>
    uint8_t alloc(void) { throw "This is an interface, dont call it"; };
    //virtual bool dealloc(void* target) = 0;
};
