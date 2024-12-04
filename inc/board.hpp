#ifndef __SNAKE_BOARD_HPP__
#define __SNAKE_BOARD_HPP__

#include <cstddef>
#include "snake.hpp"
#include "food.hpp"

class Board 
{
public:
    Board(size_t width_, size_t height_);
    void Draw(const Snake& snake_, const Food& food_) const;
    ~Board() = default;
    size_t GetWidth() const;
    size_t GetHeight() const;
    
private:
    size_t m_width;
    size_t m_height;
};
#endif // __SNAKE_BOARD_HPP__