#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

void draw_line(SDL_Renderer* rend, unsigned idx, unsigned val, int r, int g, int b, int alpha);
void draw_vector(const std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned current, unsigned compared);
void update_gui(const std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned i, unsigned j);