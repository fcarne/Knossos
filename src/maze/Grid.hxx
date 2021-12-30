#include "Grid.h"

template <typename T, size_t M>
T (&_make_sub_array(T (&orig)[M], size_t o))
[] {
    return (T(&)[])(*(orig + o));
}
#define make_sub_array(type, array, n, o) (type(&)[n]) _make_sub_array(array, o)

template <typename T>
class Grid<T>::Impl {
   private:
    uint16_t cols;
    std::unique_ptr<T*[]> data;

   public:
    Impl(uint16_t rows, uint16_t cols, const T& initValue) : cols(cols), data(std::make_unique<T*[]>(rows)) {
        for ()
    }

    std::shared_ptr<T[]> operator[](uint16_t row) {
        return std::shared_ptr(data[row]);
    }
};

template <typename T>
Grid<T>::Grid(uint16_t rows, uint16_t cols, const T& initValue) : pimpl(new Impl(rows, cols, initValue)) {}

template <typename T>
Grid<T>::~Grid() = default;

template <typename T>
std::shared_ptr<T[]> Grid<T>::operator[](uint16_t row) {
    return pimpl->operator[](row);
}