#include "GameManager.h"

int main() {
  GameManager gm;

  while (gm.window.isOpen()) {
    gm.update();
  }
}