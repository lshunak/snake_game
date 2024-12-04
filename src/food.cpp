#include "food.hpp"
#include <cstdlib>

Food::Food(size_t b_width_, size_t b_height_)
{
    GenerateFood(b_width_, b_height_);
}

void Food::GenerateFood(size_t b_width_, size_t b_height_)
{
    m_position.x = rand() % b_width_;
    m_position.y = rand() % b_height_;
}

const Position& Food::GetPosition() const
{
    return m_position;
}
