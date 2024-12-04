#include <chrono>
#include <thread>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>  // For sleep()
#include <termios.h> // For terminal control

#include "game.hpp"

    Game::Game(size_t width_, size_t height_)
    : m_board(width_, height_), m_snake(),
      m_food(width_, height_), m_gameOver(false), m_score(0)
{
    SetTeminal();
}

Game::~Game()
{
    ResetTerminal();
}

void Game::Run()
{
    while (!m_gameOver)
    {
        std::cout << "Running game loop...\n"; // Debugging line

        HandleInput();
        Update();
        Render();
        std::this_thread::sleep_for(std::chrono::milliseconds(400));

        std::cout << "Game still running, score: " << m_score << std::endl;
    }

    std::cout << "Game Over! Your score is: " << m_score << std::endl;
}

void Game::HandleInput()
{
    SetTeminal();

    if (kbhit())
    {
        
        char input;
        std::cin >> input;

        switch (input)
        {
            case 'w':
                if (m_snake.GetDirection() != Direction::DOWN)
                {
                    m_snake.SetDirection(Direction::UP);
                }
                break;
            case 's':
                if (m_snake.GetDirection() != Direction::UP)
                {
                    m_snake.SetDirection(Direction::DOWN);
                }
                break;
            case 'a':
                if (m_snake.GetDirection() != Direction::RIGHT)
                {
                    m_snake.SetDirection(Direction::LEFT);
                }
                break;
            case 'd':
                if (m_snake.GetDirection() != Direction::LEFT)
                {
                    m_snake.SetDirection(Direction::RIGHT);
                }
                break;
            case 'q':
                m_gameOver = true;
                break;
        }
    }

    ResetTerminal();
}

void Game::Update()
{
    m_snake.Move();

    std::cout << "Snake head position: (" << m_snake.GetHead().x << ", " << m_snake.GetHead().y << ")" << std::endl;
    std::cout << "Food position: (" << m_food.GetPosition().x << ", " << m_food.GetPosition().y << ")" << std::endl;

    const Position& headPos = m_snake.GetHead();
    const Position& foodPos = m_food.GetPosition();

    if (headPos.x == foodPos.x && headPos.y == foodPos.y)
    {
        m_snake.Grow();
        m_score += 10;
        m_food.GenerateFood(m_board.GetWidth(), m_board.GetHeight());
        std::cout << "Food eaten!" << std::endl;
    }

    if (headPos.x < 0 || headPos.x >= m_board.GetWidth() ||
        headPos.y < 0 || headPos.y >= m_board.GetHeight()) 
    {
        std::cout << "Collided! Game over!" << std::endl;
        m_gameOver = true;
    }

}

void Game::Render()
{
    std::cout << "Rendering" << std::endl;
    std::cout << "\033[2J\033[1;1H";
    m_board.Draw(m_snake, m_food);
    
    std::cout.flush();
}

void Game::SetTeminal()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void Game::ResetTerminal()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

bool Game::kbhit()
{
    struct termios oldt, newt;
    int ch;
    bool ret = false;

    // Get the current terminal attributes
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Set terminal to non-canonical mode
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Set the file descriptor to non-blocking mode
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

    // Try to read a character
    if (read(STDIN_FILENO, &ch, 1) != -1)
    {
        ret = true;
    }

    // Restore the original terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, 0);

    return ret;
}