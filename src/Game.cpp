#include "Game.h"

Game::Game()
    : mWindow(sf::VideoMode(1920, 1080), "Stick War Game"),
      mPlayer(100, 100, true),
      mEnemy(1820, 980) {
        mBackground.setSize(sf::Vector2f(1920, 1080));
        mBackground.setFillColor(sf::Color::White);
}

void Game::run() {
        while (mWindow.isOpen()) {
                processEvents();
                update();
                render();
        }
}

void Game::processEvents() {
        sf::Event event;
        if (mWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) mWindow.close();
        }
        mPlayer.handleInput();
}

void Game::update() {
        const sf::Vector2f player_pos = mPlayer.getPosition();
        mEnemy.update(player_pos);
}

void Game::render() {
        mWindow.clear();
        mWindow.draw(mBackground);
        mPlayer.render(mWindow);
        mEnemy.render(mWindow);
        mWindow.display();
}
