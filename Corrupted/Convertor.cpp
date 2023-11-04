
#include "Convertor.hpp"

template <typename T>
T* Convertor::convert(void* input) {

    T* result = dynamic_cast<T>(input);

    return result;

}

template <typename T>
bool Convertor::try_convert(void* input, T* output) {

    T* result = dynamic_cast<T>(input);

    if (result != NULL) {
        output = result;
        return true;
    }

    output = nullptr;
    return false;
}
