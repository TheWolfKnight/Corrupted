#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstdio>

#include "IAllocator.hpp"

class ArenaAllocator : public IAllocator {
public:

    inline explicit ArenaAllocator(void) = default;

    inline explicit ArenaAllocator(size_t size) : IAllocator() {
        this->m_size = size;
        this->m_buffer = (uint8_t*)malloc(sizeof(uint8_t) * size);
        this->m_pointer = m_buffer;
    }

    template <typename T>
    inline uint8_t* alloc(void) {
        if (this->m_pointer + sizeof(T) > this->m_buffer + this->m_size)
            throw "Not Implemented";

        uint8_t* pointer = this->m_pointer;
        this->m_pointer += sizeof(T);
        return pointer;
    }

    inline ~ArenaAllocator() {
        free(this->m_buffer);
    }

private:

    size_t m_size{};
    uint8_t* m_buffer{ nullptr };
    uint8_t* m_pointer{ nullptr };

};
