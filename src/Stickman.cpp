#include "Stickman.h"

Stickman::Stickman(float x, float y, bool friendly) : mSpeed(0.2f) {
        mBody.setSize(sf::Vector2f(20, 50));
        mBody.setFillColor(sf::Color::Yellow);
        mBody.setPosition(x, y);

        mSword.setSize(sf::Vector2f(30, 5));

        mSword.setFillColor(sf::Color::Red);

        if (friendly) {
                mSword.setFillColor(sf::Color::Green);
        }

        mSword.setPosition(x + 20, y + 20);
}

const sf::Vector2f& Stickman::getPosition() { return mBody.getPosition(); }

void handleMovement(std::map<sf::Keyboard::Key, Direction> movement_map, Stickman& stickman) {
        for (const auto& [key, direction] : movement_map) {
                std::thread([&, key, direction]() {
                        if (sf::Keyboard::isKeyPressed(key)) {
                                stickman.move(direction);
                        }
                }).detach();
        }

}

void Stickman::handleInput() {
        const sf::Vector2f pos = mBody.getPosition();
        const float x = pos.x;
        const float y = pos.y;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                attack();
        }

        const std::map<sf::Keyboard::Key, Direction> movement_map = {
            {sf::Keyboard::W, Direction::UP},
            {sf::Keyboard::S, Direction::DOWN},
            {sf::Keyboard::D, Direction::RIGHT},
            {sf::Keyboard::A, Direction::LEFT}};

        const std::map<sf::Keyboard::Key, Direction>::const_iterator it = movement_map.cbegin();

        handleMovement(movement_map, *this);
}

void Stickman::update(const sf::Vector2f& player_pos) {
        const sf::Vector2f own_pos = getPosition();
        const float x_diff = player_pos.x - own_pos.x;
        const float y_diff = player_pos.y - own_pos.y;

        if (x_diff >= 0) {
                move(Direction::RIGHT);
        } else {
                move(Direction::LEFT);
        }

        if (y_diff <= 0) {
                move(Direction::UP);
        } else {
                move(Direction::DOWN);
        }
}

void Stickman::move(const Direction& dir) {
        switch (dir) {
                case Direction::UP:
                        mBody.move(0, -mSpeed);
                        mSword.move(0, -mSpeed);
                        break;
                case Direction::DOWN:
                        mBody.move(0, mSpeed);
                        mSword.move(0, mSpeed);
                        break;
                case Direction::LEFT:
                        mBody.move(-mSpeed, 0);
                        mSword.move(-mSpeed, 0);
                        break;
                case Direction::RIGHT:
                        mBody.move(mSpeed, 0);
                        mSword.move(mSpeed, 0);
                        break;
                default:
                        break;
        }
};

void Stickman::attack() {
        mSword.rotate(10);
}

void Stickman::render(sf::RenderWindow& window) {
        window.draw(mBody);
        window.draw(mSword);
}
