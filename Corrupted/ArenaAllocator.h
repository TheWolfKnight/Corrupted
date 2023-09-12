#pragma once

#include <cstdint>
#include <cstdlib>

#include "IAllocator.h"

class ArenaAllocator : public IAllocator {
public:
    inline explicit ArenaAllocator(size_t size) : IAllocator() {
        this->m_size = size;
        this->m_buffer = (uint8_t*)malloc(sizeof(uint8_t) * size);
        this->m_pointer = m_buffer;
    }

    template <typename T>
    T* alloc(void);

    virtual bool dealloc(void* target) = 0;

    inline ~ArenaAllocator() {
        free(this->m_buffer);
    }

private:

    size_t m_size;
    uint8_t* m_buffer;
    uint8_t* m_pointer;

};
