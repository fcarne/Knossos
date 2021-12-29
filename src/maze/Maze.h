#ifndef MAZE_H_
#define MAZE_H_

#include <cstdint>
#include <memory>
#include <vector>

#include "Grid.h"
#include "Room.h"

template <class R>
class Maze {
   private:
    uint32_t width;
    uint32_t height;
    Grid<R> rooms;

   public:
    Maze(int, int);
    ~Maze();

    vector<shared_ptr<R>> getNeighbours(const R&, bool alreadyIn);
    void connect(const R&, const R&);
    shared_ptr<R> getRoom(uint32_t, uint32_t);
    bool canMove(const R&, R::Direction)
};

#endif