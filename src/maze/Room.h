#ifndef ROOM_H_
#define ROOM_H_

#include <cstdint>
#include <memory>

class Doors {
   private:
    class Impl;
    std::unique_ptr<Impl> pimpl;

   public:
    enum Direction : int {
        NORTH,
        SOUTH,
        WEST,
        EAST
    };

    Doors();
    ~Doors();

    bool isPortOpen(Direction);
    void openPort(Direction);

    static Direction opposite(Direction d) {
        switch (d) {
            case NORTH:
                return SOUTH;
                break;
            case SOUTH:
                return NORTH;
                break;
            case WEST:
                return EAST;
                break;
            case EAST:
                return WEST;
                break;
        }
    }
};

class Room {
   private:
    uint32_t x;
    uint32_t y;
    Doors doors;

   public:
    Room(uint32_t, uint32_t);
    virtual ~Room();

    uint32_t getX();
    uint32_t getY();
    Doors getDoors();
};

#endif
