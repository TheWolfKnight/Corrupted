
#include <cstdlib>

#include "HeapAllocator.h"

template <typename T>
T* HeapAllocator::alloc(void) {
    return static_cast<T*>(malloc(sizeof(T)));
}

bool HeapAllocator::dealloc(void* target) {
    free(target);
    return true;
}
