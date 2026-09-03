#include "Snake.h"
#include <algorithm>

sf::Texture Snake::headTex("textures/head.png");
sf::Texture Snake::bodyTex("textures/body.png");

void Snake::updateScales(uint32_t width, uint32_t height) {
  head.setScale({0.75f*width/600, 0.75f*height/600});
  body.setScale({0.75f*width/600, 0.75f*height/600});
}

Snake::Snake(Field& field) : field(field) {
  head.setOrigin({25, 25});
  body.setOrigin({25, 25});

  pos.push_front({5, 5});

  updateScales(field.width, field.height);
}

void Snake::changeDirection(Direction d) {
  if ((d == Direction::Right || d == Direction::Left) && 
      (dir == Direction::Right || dir == Direction::Left)) return;
  if ((d == Direction::Up || d == Direction::Down) && 
      (dir == Direction::Up || dir == Direction::Down)) return;
  dir = d;
}

void Snake::update() {
  if (collided) return;

  sf::Vector2i d;
  switch (dir) {
  case Direction::Right:
    d = {1, 0};
    break;
  case Direction::Left:
    d = {-1, 0};
    break;
  case Direction::Up:
    d = {0, -1};
    break;
  case Direction::Down:
    d = {0, 1};
    break;
  }

  sf::Vector2i newHead = pos.front()+d;
  if (newHead.x < 0 || newHead.y < 0 || newHead.x > 11 || newHead.y > 11
      || std::find(pos.begin(), pos.end(), newHead) != pos.end()) {
    collided = true;
    return;
  }

  pos.push_front(newHead);
  if (newHead == field.applePos) {
    field.spawnRandomApple();
  } else {
    pos.pop_back();
  }

}

void Snake::draw(sf::RenderWindow& window) {
  head.setPosition(field.getCellPosition(pos.front()));
  window.draw(head);
  for (auto i = pos.begin()+1; i != pos.end(); ++i) {
    body.setPosition(field.getCellPosition(*i));
    window.draw(body);
  }
}
