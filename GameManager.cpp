#include "GameManager.h"


GameManager::GameManager()
  : window (sf::VideoMode({600, 600}), "Snake", sf::Style::Titlebar | sf::Style::Close),
    field (600, 600) {
  field.spawnRandomApple();
}

void GameManager::update() {
  pollEvents();

  window.clear(sf::Color(43, 35, 17));

  draw();

  window.display();
}

bool GameManager::isOpen() const {
  return window.isOpen();
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
  }
}

void GameManager::draw() {
  field.draw(window);
}