#pragma once

#include <cstdint>

struct RGBA{
  uint8_t r,g,b,a;
};

struct Vec2i{
  int x,y;
  bool operator==(Vec2i other){
    if(other.x == x && other.y == y)return true;
    return false;
  }
};
using Pos = Vec2i;
struct Dim{int width,height;};

// win Dimensions is the dimension of the window created
// i.e. a 100x100 px window
constexpr Dim winDim{900,600};

// gridProp is the grid proportions
// i.e. each grid cell is 10x10
constexpr Dim gridProp{10,10};
