#pragma once


class Convertor {
public:

    template <typename T>
    T* convert(void* input);

    template <typename T>
    bool try_convert(void* input, T* output);

};
