#pragma once
#include <SFML/Graphics.hpp>

class GameManager {
public:
  sf::RenderWindow window;

  GameManager();
  GameManager(const GameManager&) = delete;
  GameManager operator=(const GameManager&) = delete;

  void update();
  
};