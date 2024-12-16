#include "Game.h"
#include <iostream>
int main() {
    try {
        Game game;      // Create the Game object
        game.run();     // Run the main game loop
    } catch (const std::exception& e) {
        // Handle any exceptions
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
