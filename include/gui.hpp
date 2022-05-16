#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

void draw_vector(const std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned current, unsigned compared);
void update_gui(const std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned i, unsigned j);
void comparison_found(const std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned i, unsigned j);