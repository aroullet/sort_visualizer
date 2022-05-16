#include "gui.hpp"

SDL_Window* initialize_window(int w, int h) {
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0)) {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }
    SDL_Window* win = SDL_CreateWindow("Sort Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);

    return win;
}

SDL_Renderer* get_renderer(SDL_Window* win) {
    return SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
}