#pragma once
#include <SFML/Graphics.hpp>
#include <deque>
#include "Field.h"

enum class Direction {
  Right,
  Left,
  Up,
  Down
};

class Snake {
  std::deque<sf::Vector2i> pos;

  static sf::Texture headTex;
  static sf::Texture bodyTex;
  
  sf::Sprite head = sf::Sprite(headTex);
  sf::Sprite body = sf::Sprite(bodyTex);

  void updateScales(uint32_t width, uint32_t height);

  Field& field;

public:
  bool collided = false;  
  Direction dir = Direction::Right;

  Snake(Field& field);

  void changeDirection(Direction d);

  void update();
  void draw(sf::RenderWindow& window);
};