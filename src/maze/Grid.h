#ifndef GRID_H_
#define GRID_H_

#include <cstdint>
#include <memory>
template <typename T>
class Grid {
   private:
    class Impl;
    std::unique_ptr<Impl> pimpl;

   public:
    Grid(uint16_t rows, uint16_t cols, const T& initValue = T());
    ~Grid();
    std::shared_ptr<T[]> operator[](uint16_t row);
};

#include "Grid.hxx"

#endif