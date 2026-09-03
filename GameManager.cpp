#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
  : window (sf::VideoMode({600, 600}), "Snake", sf::Style::Titlebar | sf::Style::Close),
    field (600, 600) {
  clock.start();
}

void GameManager::update() {
  pollEvents();

  if (clock.getElapsedTime().asMilliseconds() >= 500) {
    snake.update();
    clock.restart();
  }

  window.clear(sf::Color(43, 35, 17));

  draw();

  window.display();
}

bool GameManager::isOpen() const {
  return window.isOpen();
}

void GameManager::draw() {
  field.draw(window);
  snake.draw(window);
}

void GameManager::pollEvents() {
  while (const auto& event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window.close();
      continue;
    }
    if (const auto* resized = event->getIf<sf::Event::Resized>()) {
      sf::View view(sf::FloatRect({.0f, .0f}, {(float)resized->size.x, (float)resized->size.y}));
      window.setView(view);
    }
    if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
      switch (key->code) {
      case sf::Keyboard::Key::Right:
        snake.changeDirection(Direction::Right);
        break;
      case sf::Keyboard::Key::Left:
        snake.changeDirection(Direction::Left);
        break;
      case sf::Keyboard::Key::Up:
        snake.changeDirection(Direction::Up);
        break;
      case sf::Keyboard::Key::Down:
        snake.changeDirection(Direction::Down);
        break;
      case sf::Keyboard::Key::R:
        snake.restart();
        break;
      default:
        break;
      }
    }
  }
}