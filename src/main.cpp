#include <fmt/core.h>
#include <SDL2/SDL.h>

#include <chrono>
#include <random>

#include "CGLife.h"

int main(int argv, char **argc) {
  // 32bit mersenne twister seeded using steady clock for better randomness
  std::mt19937 mt{static_cast<std::mt19937::result_type>(
    std::chrono::steady_clock::now().time_since_epoch().count()
  )};
  // reusable uniform rand num generator between 0 and world bounds
  std::uniform_int_distribution<> worldseed{0,winDim.width*winDim.height};
  Vec2i seed{worldseed(mt), worldseed(mt)};
  CGLife game{"Conways Game of life", seed};
  game.run();

  return 0;
}
