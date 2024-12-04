#ifndef __SNAKE_POSITION_HPP__
#define __SNAKE_POSITION_HPP__

#include <cstddef>

struct Position 
{
    size_t x;
    size_t y;

    Position(size_t x_ = 0, size_t y_ = 0) : x(x_), y(y_) {}
};

#endif // __SNAKE_POSITION_HPP__