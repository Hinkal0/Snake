#pragma once
#include <SFML/Graphics.hpp>

class Text {
  
  const sf::Font& font;
  sf::Text text;
  
  uint32_t size;
  sf::Vector2f pos;
  uint32_t origin;
public:

  Text(const sf::Font& font, sf::Vector2u winSize, sf::Vector2f pos, uint32_t size, sf::String str, uint32_t origin = 0);

  void updateScales(uint32_t width, uint32_t height);

  void update(sf::String str);
  void draw(sf::RenderWindow& window) const;
};