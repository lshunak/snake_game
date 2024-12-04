#include <algorithm>
#include <iostream>
#include "snake.hpp"
#include "position.hpp"

Snake::Snake() : m_direction(Direction::STOP), m_just_grew(false)
{
    m_snake.push_back(Position(10, 10));
}

void Snake::Move()
{
    Position new_head = m_snake.front();

    switch (m_direction)
    {
    case Direction::UP:
        new_head.y--;
        break;
    case Direction::DOWN:
        new_head.y++;
        break;
    case Direction::LEFT:
        new_head.x--;
        break;
    case Direction::RIGHT:
        new_head.x++;
        break;
    default:
        break;
    }
    m_snake.insert(m_snake.begin(), new_head);
    m_snake.pop_back();
}

void Snake::SetDirection(Direction direction_)
{
    m_direction = direction_;
}

void Snake::Grow()
{
    Position tail = m_snake.back(); // Get the current tail
    std::cout << "Growing snake at tail position: (" << tail.x << ", " << tail.y << ")" << std::endl;
    m_snake.push_back(tail); // Add a new segment to the tail
    m_just_grew = true;
}

bool Snake::IsColliding() 
{
    if (m_just_grew)
    {
        m_just_grew = false;
        return false;
    }

    Position head = m_snake.front();

    for (size_t i = 1; i < m_snake.size(); ++i)
    {
        if (head.x == m_snake[i].x && head.y == m_snake[i].y)
        {
            std::cout << "Collision detected with segment at (" << m_snake[i].x << ", " << m_snake[i].y << ")" << std::endl;

            return true;
        }
    }
    return false;
}

Direction Snake::GetDirection() const
{
    return m_direction;
}

const std::vector<Position>& Snake::GetSnakeBody() const
{
    return m_snake;
}

Position Snake::GetHead() const
{
    return m_snake.front();
}