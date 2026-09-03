#pragma once
#include <SFML/Graphics.hpp>

class Field {
  static sf::Texture fieldTex;
  static sf::Texture appleTex;

  uint32_t width;
  uint32_t height;

  sf::Vector2f corner;
  float cell;

  sf::Sprite apple = sf::Sprite(appleTex);
  bool hasApple = false;
  sf::Vector2u applePos = {0, 0};

  void updateScales(uint32_t width, uint32_t height);
  
public:

  sf::Sprite field = sf::Sprite(fieldTex);

  Field(uint32_t width, uint32_t height);

  void spawnRandomApple();
  void removeApple();
  void draw(sf::RenderWindow& window) const;
};