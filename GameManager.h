#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"

class GameManager {
  sf::RenderWindow window;
  void pollEvents();
  void draw();

  Field field;

public:

  GameManager();
  GameManager(const GameManager&) = delete;
  GameManager operator=(const GameManager&) = delete;

  void update();
  
  bool isOpen() const;
};