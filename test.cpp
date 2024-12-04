#include "game.hpp"

int main()
{
    // Set the width and height of the game board
    size_t width = 20;  // You can adjust these values
    size_t height = 20; // You can adjust these values

    // Create a Game instance
    Game game(width, height);

    // Start the game
    game.Run();

    return 0;
}
