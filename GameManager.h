#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Snake.h"
#include "Text.h"

class GameManager {
  sf::RenderWindow window;
  void pollEvents();
  void draw();

  static sf::Font arial;

  sf::Clock clock;
  Field field;
  Text score;
  Text best;
  Text help;
  uint32_t oldScore = 0;
  uint32_t curScore = 0;

  uint32_t bestScore = 0;

  bool paused = false;

  Snake snake = Snake(field, curScore);

public:

  GameManager();
  GameManager(const GameManager&) = delete;
  GameManager operator=(const GameManager&) = delete;

  void update();
  
  bool isOpen() const;
};