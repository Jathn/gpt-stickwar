#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Stickman.h"

class Game {
       public:
        Game();
        void run();

       private:
        void processEvents();
        void update();
        void render();

        sf::RenderWindow mWindow;
        sf::RectangleShape mBackground;

        Stickman mPlayer;
        Stickman mEnemy;
};

#endif  // GAME_H
