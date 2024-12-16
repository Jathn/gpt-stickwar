#ifndef STICKMAN_H
#define STICKMAN_H

#include <SFML/Graphics.hpp>

enum class Direction {
    UP,
    DOWN,
    RIGHT,
    LEFT
};

class Stickman {
public:
    Stickman(float x, float y);

    sf::Vector2f getPosition();
    void handleInput();               // Process player input
    void update(const sf::Vector2f& player_pos); // Update stickman state
    void render(sf::RenderWindow& window); // Render stickman and sword
    void move(Direction dir);
private:
    sf::RectangleShape mBody;         // Stickman body
    sf::RectangleShape mSword;        // Stickman's sword
    float mSpeed;                     // Movement speed
};

#endif
