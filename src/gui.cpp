#include "gui.hpp"

void update_gui(const std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned i, unsigned j, int delay) {

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255); // white
    SDL_RenderClear(rend);

    draw_vector(vec, rend, i, j);

    SDL_RenderPresent(rend);
    SDL_Delay(delay);
}

void draw_vector(const std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned current, unsigned compared) {

    for (int i = 0; i < vec.size(); ++i) {

        if (i == current)
            SDL_SetRenderDrawColor(rend, 0, 0, 255, 255); // blue

        else if (i == compared)
            SDL_SetRenderDrawColor(rend, 0, 255, 0, 255); // green

        else
            SDL_SetRenderDrawColor(rend, 0, 0, 0, 0); // black

        SDL_RenderDrawLine(rend, i, 99, i, 99-vec[i]);
    }
}