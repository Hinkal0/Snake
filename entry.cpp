#include "GameManager.h"
#include <random>

int main() {
  std::srand(std::time(NULL));

  GameManager gm;

  while (gm.isOpen()) {
    gm.update();
  }
}