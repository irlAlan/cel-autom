#include "CGLife.h"
#include "Cell.h"
#include "Util.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <fmt/core.h>
#include <memory>


CGLife::CGLife(std::string title, Vec2i seed)
  : col_{0xff,0xff,0xff,0xff}
{

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fmt::println(fmt::format("Cannot init video: %s", SDL_GetError()));
    std::exit(-1);
  }

  window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, winDim.width,
                            winDim.height, SDL_WINDOW_SHOWN);
  if (!window_) {
    fmt::println(fmt::format("Cannot create sdl window: %s", SDL_GetError()));
    std::exit(-1);
  }

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer_) {
    fmt::println(fmt::format("Cannot create renderer: %s", SDL_GetError()));
    std::exit(-1);
  }
  SDL_RenderSetLogicalSize(renderer_, winDim.width, winDim.height);


  // seed has winDim.w*winDim.h
  // gives me the seed in bounds of the window
  Pos seedPos{(seed.x/winDim.height)/gridProp.width,(seed.y/winDim.width)/gridProp.height};
  fmt::println("seed pos: ({},{})", seedPos.x, seedPos.y);
  int height,width = 0;

  // cmap_.insert({std::unique_ptr<Cell>(new Cell({0,0}, CellState::Alive)), CellState::Alive});
  cmap_[seedPos] = CellState::Alive;
  //for(auto& val : cells_){
  //  for(auto& cell : val) {
  //    cell = std::unique_ptr<Cell>(new Cell({height/10,width/10},CellState::Alive));
  //    width++;
  //  }
  //  height++;
  //}
}

CGLife::~CGLife(){
  window_ = nullptr;
  renderer_ = nullptr;
}

void CGLife::run(){

  bool quit{false};

  while(!quit){
    while(SDL_PollEvent(&event_)){
      switch(event_.type){
        case SDL_QUIT:
          quit = true;
          break;
        default:
          break;
      } // switch
    }// poll event
    update();
    draw();
  } // start loop 
}



void CGLife::draw(){
  SDL_SetRenderDrawColor(renderer_,col_.r,col_.g, col_.b, col_.a);
  SDL_RenderClear(renderer_);

  SDL_SetRenderDrawColor(renderer_, 0xcc, 0xcc, 0xcc, 0xcc);


  for (int x{0}; x < winDim.width; x += gridProp.width) {
    SDL_RenderDrawLine(renderer_, x, 0, x, winDim.height);
  }
  for (int y{0}; y < winDim.height; y += gridProp.height) {
    SDL_RenderDrawLine(renderer_, 0, y, winDim.width, y);
  }

 // for(const auto& cell_array : cells_){
 //   for(const auto& cell : cell_array){
 //     cell->draw(renderer_);
 //   }
 // }
  SDL_RenderPresent(renderer_);
}

void CGLife::update(){
}

void CGLife::handleBounds(Pos &pos){}
int  CGLife::countAliveNeighbours(const Pos &pos){return 0;}
