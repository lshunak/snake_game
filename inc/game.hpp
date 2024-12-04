#ifndef __SNAKE_GAME_HPP__
#define __SNAKE_GAME_HPP__

#include <cstddef>
#include "board.hpp"
#include "snake.hpp"
#include "food.hpp"

class Game
{
public:
    Game(size_t width_, size_t height_);
    void Run();
    void HandleInput();
    void Update();
    void Render();

    ~Game();

private:
    Board m_board;
    Snake m_snake;
    Food m_food;
    bool m_gameOver;
    int m_score;

    static void SetTeminal();
    static void ResetTerminal();
    static bool kbhit();
};

#endif // __SNAKE_GAME_HPP__