#ifndef __SNAKE_FOOD_HPP__
#define __SNAKE_FOOD_HPP__ 

#include "position.hpp"

class Food
{
public:
    
    Food(size_t b_width_, size_t b_height_);
    void GenerateFood(size_t b_width_, size_t b_height_);

    ~Food() = default;

    const Position& GetPosition() const;

private:
    Position m_position;
};
#endif // __SNAKE_FOOD_HPP__