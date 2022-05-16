#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window* initialize_window(int w, int h);
SDL_Renderer* get_renderer(SDL_Window* win);