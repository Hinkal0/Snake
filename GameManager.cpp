#include "GameManager.h"
#include <iostream>
#include <fstream>

sf::Font GameManager::arial("fonts/ArialMT.ttf");

static const wchar_t* titleStr = L"Нажмите Enter чтобы начать";

static const wchar_t* helpStr = 
L"←↑→↓ - повороты\nR - начать заново\nEsc - пауза";

GameManager::GameManager()
  : window (sf::VideoMode({800, 600}), "Snake"),
    title(arial, {800, 600}, {300, 200}, 48, titleStr),
    bestMenu(arial, {800, 600}, {300, 400}, 36, ""),
    field (800, 600),
    score(arial, {800, 600}, {300, 40}, 64, "0"),
    best(arial, {800, 600}, {595, 5}, 32, "", 2),
    help(arial, {800, 600}, {5, 5}, 24, helpStr, 1) {
  sf::Vector2u minSize(800, 600);
  window.setMinimumSize(minSize);

  std::ifstream save("save.dat", std::ios::binary);
  if (save.is_open()) {
    save.read((char*)&bestScore, sizeof(uint32_t));
  }
  best.update(std::wstring(L"Лучший счёт: ") + std::to_wstring(bestScore));
  bestMenu.update(std::wstring(L"Лучший счёт: ") + std::to_wstring(bestScore));
}

void GameManager::update() {
  pollEvents();

  if (scene == 1 && !paused) {

    if (clock.getElapsedTime().asMilliseconds() >= 500) {
      snake.update();

      if (oldScore != curScore) {
        score.update(std::to_string(curScore));
        oldScore = curScore;
        if (curScore > bestScore) {
          bestScore = curScore;
          best.update(std::wstring(L"Лучший счёт: ") + std::to_wstring(bestScore));
        }
      }
      clock.restart();
    }
  }

  draw();
}

bool GameManager::isOpen() const {
  return window.isOpen();
}

void GameManager::draw() {
  window.clear(sf::Color(43, 35, 17));

  if (scene == 0) {
    title.draw(window);
    bestMenu.draw(window);
  } else {
    field.draw(window);
    snake.draw(window);
    score.draw(window);
    best.draw(window);
    help.draw(window);
  }

  window.display();
}

void GameManager::pollEvents() {
  while (const auto& event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      std::ofstream save("save.dat", std::ios::binary);
      save.write((char*)&bestScore, sizeof(uint32_t));
      window.close();
      return;
    }
    if (const auto* resized = event->getIf<sf::Event::Resized>()) {
      sf::View view(sf::FloatRect({.0f, .0f}, {(float)resized->size.x, (float)resized->size.y}));
      window.setView(view);
      title.updateScales(resized->size.x, resized->size.y);
      bestMenu.updateScales(resized->size.x, resized->size.y);

      field.updateScales(resized->size.x, resized->size.y);
      snake.updateScales(resized->size.x, resized->size.y);
      score.updateScales(resized->size.x, resized->size.y);
      best.updateScales(resized->size.x, resized->size.y);
      help.updateScales(resized->size.x, resized->size.y);
    }
    if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
      if (scene == 0) {
        if (key->code == sf::Keyboard::Key::Enter) {
          scene = 1;
          clock.restart();
        }
        continue;
      }

      switch (key->code) {
      case sf::Keyboard::Key::Right:
        snake.changeDirection(Direction::Right);
        break;
      case sf::Keyboard::Key::Left:
        snake.changeDirection(Direction::Left);
        break;
      case sf::Keyboard::Key::Up:
        snake.changeDirection(Direction::Up);
        break;
      case sf::Keyboard::Key::Down:
        snake.changeDirection(Direction::Down);
        break;
      case sf::Keyboard::Key::R:
        if (paused) {
          paused = false;
          clock.start();
        }
        snake.restart();
        break;
      case sf::Keyboard::Key::Escape:
        paused ^= 1;
        if (paused) clock.reset();
        else clock.start();
      default:
        break;
      }
    }
  }
}