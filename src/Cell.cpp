#include "Cell.h"

#include <SDL2/SDL_render.h>
#include <fmt/core.h>
#include "Util.h"

Cell::Cell(Pos pos, CellState state)
  : pos_(pos), state_(state), rect_{pos.x,pos.y,gridProp.width,gridProp.height}
{}

void Cell::draw(SDL_Renderer *renderer){
  if(state_ == CellState::Dead){
    col_ = {0xff,0xff,0xff,0xff};
  }
  if(state_ == CellState::Alive){
    col_ = {0x66,0x66,0x66,0xff};
  }
  SDL_SetRenderDrawColor(renderer,col_.r, col_.g, col_.b,col_.a);
  SDL_RenderFillRect(renderer, &rect_);
  SDL_RenderDrawRect(renderer, &rect_);
  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff,0xff);
}

void Cell::setState(CellState state){state_=state;}
CellState Cell::getState()const{return state_;}

std::string Cell::getStateString()const{
  switch (state_) {
    case CellState::Alive:
      return "Alive";
    case CellState::Dead:
      return "Dead";
    default:
      return "None";
  }
}
Pos Cell::getPos()const{return pos_;}

std::ostream& operator<<(std::ostream &out, Cell &other){
  out << fmt::format("Position: ({},{}), State: {}\n", other.pos_.x, other.pos_.y,other.getStateString());
  return out;
}
