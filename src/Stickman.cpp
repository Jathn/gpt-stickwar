#include "Stickman.h"

Stickman::Stickman(float x, float y) : mSpeed(0.2f) {
  // Initialize the stickman body
  mBody.setSize(sf::Vector2f(20, 50));  // Width x Height
  mBody.setFillColor(sf::Color::White);
  mBody.setPosition(x, y);

  // Initialize the sword
  mSword.setSize(sf::Vector2f(30, 5));  // Length x Thickness
  mSword.setFillColor(sf::Color::Red);
  mSword.setPosition(x + 20, y + 20);  // Position relative to the body
}

const sf::Vector2f& Stickman::getPosition() { return mBody.getPosition(); }

void Stickman::handleInput() {
  const sf::Vector2f pos = mBody.getPosition();
  const float x = pos.x;
  const float y = pos.y;

  const std::map<sf::Keyboard::Key, Direction> movement_map = {
      {sf::Keyboard::W, Direction::UP},
      {sf::Keyboard::S, Direction::DOWN},
      {sf::Keyboard::D, Direction::RIGHT},
      {sf::Keyboard::A, Direction::LEFT}};

  const std::map<sf::Keyboard::Key, Direction>::const_iterator it =
      std::find_if(movement_map.cbegin(), movement_map.cend(),
                   [](std::pair<sf::Keyboard::Key, Direction> movement_pair) {
                     return sf::Keyboard::isKeyPressed(movement_pair.first);
                   });

  if (it == movement_map.end()) {
    return;
  }

  move((*it).second);
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
      mBody.move(0, -mSpeed);  // Move up
      mSword.move(0, -mSpeed);
      break;
    case Direction::DOWN:
      mBody.move(0, mSpeed);
      mSword.move(0, mSpeed);
      break;
    case Direction::LEFT:
      mBody.move(-mSpeed, 0);  // Move left
      mSword.move(-mSpeed, 0);
      break;
    case Direction::RIGHT:
      mBody.move(mSpeed, 0);  // Move right
      mSword.move(mSpeed, 0);
      break;
    default:
      break;
  }
};

void Stickman::render(sf::RenderWindow& window) {
  window.draw(mBody);
  window.draw(mSword);
}
