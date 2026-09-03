#pragma once
#include <SFML/Graphics.hpp>
#include <deque>

class Field {
  static sf::Texture fieldTex;
  static sf::Texture appleTex;

  uint32_t width;
  uint32_t height;

  sf::Vector2f corner;
  float cell;

  sf::Sprite apple = sf::Sprite(appleTex);
  bool hasApple = false;
  sf::Vector2i applePos = {0, 0};
  
  void updateScales(uint32_t width, uint32_t height);
  
  friend class Snake;

public:

  sf::Sprite field = sf::Sprite(fieldTex);

  Field(uint32_t width, uint32_t height);

  void spawnRandomApple(const std::deque<sf::Vector2i>& pos);
  void removeApple();
  void draw(sf::RenderWindow& window) const;

  sf::Vector2f getCellPosition(const sf::Vector2i& cellPos) const;
};