#pragma once

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <array>
#include <memory>
#include <unordered_map>

#include "Cell.h"
#include "Util.h"


class CGLife{
public:
  // creates an array with same dimensions as the window
  using Cells2d = std::array<std::array<std::unique_ptr<Cell>,winDim.width>,winDim.height>;
  using CellMap = std::unordered_map<Pos,CellState>;
public:
  CGLife(std::string title="Default", Vec2i seed={0,0});
  ~CGLife();
  void run();
private:
  void draw();
  void update();
  void handleBounds(Pos &pos);
  int countAliveNeighbours(const Pos &pos);
private:
  SDL_Window *window_{nullptr};
  SDL_Renderer *renderer_{nullptr};
  SDL_Event event_; 
  Pos mousePos_;
  RGBA col_;
  // Cells2d cells_;
  CellMap cmap_;
};
