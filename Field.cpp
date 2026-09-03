#include "Field.h"
#include <random>

sf::Texture Field::fieldTex("textures/field.png");
sf::Texture Field::appleTex("textures/apple.png");

void Field::updateScales(uint32_t width, uint32_t height) {
  field.setScale({0.75f*width/600, 0.75f*height/600});
  field.setPosition({width/2.f, height/2.f+height/12.f});
  apple.setScale({0.75f*50.0f/512.0f*width/600, 0.75f*50.0f/512.0f*height/600});
  corner = {
    field.getPosition().x-field.getGlobalBounds().size.x/2+0.75f*50.0f*width/600,
    field.getPosition().y-field.getGlobalBounds().size.y/2+0.75f*50.0f*height/600
  };
  cell = 0.75f*50.0f*width/600;
  if (hasApple) {
    apple.setPosition(corner + sf::Vector2f({applePos.x*cell, applePos.y*cell}));
  }

  this->width = width;
  this->height = height;
}

Field::Field(uint32_t width, uint32_t height) {
  field.setOrigin({325, 325});
  apple.setOrigin({256, 256});
  
  updateScales(width, height);
}

void Field::spawnRandomApple() {
  hasApple = true;
  applePos = {(uint32_t)rand()%12, (uint32_t)rand()%12};
  apple.setPosition(corner + sf::Vector2f({applePos.x*cell, applePos.y*cell}));
}

void Field::removeApple() {
  hasApple = false;
}

void Field::draw(sf::RenderWindow& window) const {
  window.draw(field);
  if (hasApple) window.draw(apple);
}