
#include "ArenaAllocator.h"

#include <cstdio>
#include <cstring>

template <typename T>
T* ArenaAllocator::alloc(void) {
    if (this->m_pointer + sizeof(T) > this->m_size)
        throw "Not Implemented";

    uint8_t* pointer = this->m_pointer;
    this->m_pointer += sizeof(T);
    return static_cast<T*>(pointer);
}

bool ArenaAllocator::dealloc(void* _target = NULL) {
    if (_target != NULL)
        fprintf(stderr, "[WARNING]: ARENA ALLOCATOR DOES NOT USE THE GIVEN TARGET!");

    uint8_t *backup = this->m_buffer;
    this->m_buffer = (uint8_t*)memset(this->m_buffer, 0, this->m_size * sizeof(uint8_t));

    if (this->m_buffer == NULL) {
        this->m_buffer = backup;
        return false;
    }

    this->m_pointer = this->m_buffer;
    return true;
}
