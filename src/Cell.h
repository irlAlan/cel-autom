#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>
#include <iostream>
#include <string>
#include "Util.h"

enum class CellState{Dead=0,Alive=1};

class Cell{
public:
  Cell(Pos pos={0,0}, CellState state=CellState::Alive);
  ~Cell()=default;
  void setState(CellState state);
  CellState getState()const;
  std::string getStateString()const;
  Pos getPos()const;
  void draw(SDL_Renderer *renderer);
private:
  SDL_Rect rect_;
  CellState state_;
  Pos pos_;
  RGBA col_;
public:
  Cell(Cell &cell); // copy constructor
  friend std::ostream& operator<<(std::ostream &out, Cell &other);
};
