#include "Text.h"

Text::Text(const sf::Font& font, sf::Vector2u winSize, sf::Vector2f pos, uint32_t size, sf::String str, uint32_t origin) 
: font(font), text(font, str, size*winSize.y/600.0f), size(size), pos(pos), origin(origin) {
  if (!origin) text.setOrigin({text.getLocalBounds().size.x/2, text.getLocalBounds().size.y/2});
  if (origin == 2) text.setOrigin({text.getLocalBounds().size.x, 0});
  text.setPosition({pos.x*winSize.x/600.0f, pos.y*winSize.y/600.0f});
}

void Text::updateScales(uint32_t width, uint32_t height) {
  text.setCharacterSize(size*height/600.0f);
  text.setPosition({pos.x*width/600.0f, pos.y*height/600.0f});
}

void Text::update(sf::String str) {
  text.setString(str);
  if (!origin) text.setOrigin({text.getLocalBounds().size.x/2, text.getLocalBounds().size.y/2});
  if (origin == 2) text.setOrigin({text.getLocalBounds().size.x, 0});
}

void Text::draw(sf::RenderWindow& window) const {
  window.draw(text);
}