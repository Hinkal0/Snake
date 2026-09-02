#include "GameManager.h"

GameManager::GameManager()
  : window (sf::VideoMode({800, 600}), "Snake") {

}

void GameManager::update() {
  while (const auto& event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window.close();
    }
  }
  window.clear();
  window.display();
}
