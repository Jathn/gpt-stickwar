#ifndef STICKMAN_H
#define STICKMAN_H

#include <map>
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

    const sf::Vector2f& getPosition();
    void handleInput();
    void update(const sf::Vector2f& player_pos);
    void render(sf::RenderWindow& window);
    void move(const Direction& dir);
private:
    sf::RectangleShape mBody;
    sf::RectangleShape mSword;
    float mSpeed;
    int health;
};

#endif
