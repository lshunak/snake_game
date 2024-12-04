#ifndef __SNAKE_SNAKE_HPP__
#define __SNAKE_SNAKE_HPP__

#include <vector>
#include "position.hpp"
#include "direction.hpp"

class Snake
{
public:
    Snake();
    void Move();
    void SetDirection(Direction direction_);
    void Grow();
    bool IsColliding();
    Direction GetDirection() const;
    const std::vector<Position>& GetSnakeBody() const;
    ~Snake() = default;
    Position GetHead() const;

private:
    std::vector<Position> m_snake;
    Direction m_direction;
    bool m_just_grew;
};

#endif // __SNAKE_SNAKE_HPP__