#include "Grid.h"

template <typename T>
Grid<T>::Grid(uint16_t rows, uint16_t cols, const T& initValue) : pimpl(new Grid::Impl<T>(rows, cols, initValue)) {}

template <typename T>
Grid<T>::~Grid() = default;

template <typename T>
std::shared_ptr<T[]> Grid<T>::operator[](uint16_t row) {
    return pimpl->operator[](row);
}

template <typename S>
class Impl {
   private:
    uint16_t cols;
    std::unique_ptr<S[]> data_ptr;

   public:
    Impl(uint16_t rows, uint16_t cols, const S& initValue) : data_ptr(std::make_unique(new S[rows * cols]{initValue})), cols(cols) {
    }

    std::shared_ptr<S[]> operator[](uint16_t row) {
        return std::shared_ptr<S[]>(data_ptr[row * cols]);
    }
};