#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Snake.h"

class GameManager {
  sf::RenderWindow window;
  void pollEvents();
  void draw();

  sf::Clock clock;
  Field field;
  uint32_t score = 0;
  Snake snake = Snake(field, score);
  sf::Font arial;
  sf::Text scoreboard;

public:

  GameManager();
  GameManager(const GameManager&) = delete;
  GameManager operator=(const GameManager&) = delete;

  void update();
  
  bool isOpen() const;
};