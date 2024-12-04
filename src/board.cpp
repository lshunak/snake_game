#include <iostream>
#include <cstdlib>
#include "board.hpp"

Board::Board(size_t width_, size_t height_) : m_width(width_), m_height(height_)
{}

void Board::Draw(const Snake& snake_, const Food& food_) const
{
    system("clear");
    
    for (size_t i = 0; i < m_width + 2; ++i)
    {
        std::cout << "#";
    }
    std::cout << std::endl;

    // Draw the board
    for (size_t i = 0; i < m_height; ++i)
    {
        std::cout << "#";

        for (size_t j = 0; j < m_width; ++j)
        {
            bool drawn = false;
            const auto &snakeBody = snake_.GetSnakeBody();

            // Check if this position is the snake's head
            const Position &head = snakeBody.front();
            if (head.x == j && head.y == i)
            {
                // Draw head based on the snake's direction
                switch (snake_.GetDirection())
                {
                case Direction::STOP:
                    std::cout << "O";
                    break;
                case Direction::UP:
                    std::cout << "^";
                    break;
                case Direction::DOWN:
                    std::cout << "v";
                    break;
                case Direction::LEFT:
                    std::cout << "<";
                    break;
                case Direction::RIGHT:
                    std::cout << ">";
                    break;
                }
                drawn = true;
            }
            else
            {
                // Draw the snake's body
                for (size_t k = 1; k < snakeBody.size(); ++k)
                {
                    if (snakeBody[k].x == j && snakeBody[k].y == i)
                    {
                        std::cout << "o"; // Body part
                        drawn = true;
                        break;
                    }
                }
            }
            if (!drawn)
            {
                if (food_.GetPosition().x == j && food_.GetPosition().y == i)
                {
                    std::cout << "*";
                }
                else
                {
                    std::cout << " ";
                }
            }
        }
        std::cout << "#";
        std::cout << std::endl;
    }

    for (size_t i = 0; i < m_width + 2; ++i)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
}

size_t Board::GetWidth() const
{
    return m_width;
}

size_t Board::GetHeight() const
{
    return m_height;
}