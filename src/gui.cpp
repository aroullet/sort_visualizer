#include "gui.hpp"

void update_gui(const std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned i, unsigned j) {

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255); // white
    SDL_RenderClear(rend);

    draw_vector(vec, rend, i, j);

    SDL_RenderPresent(rend);
    SDL_Delay(30);
}

void draw_vector(const std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned current, unsigned compared) {
    SDL_Rect rect;
    rect.x = 0; rect.y = 0;
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

void comparison_found(const std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned i, unsigned j) {

    SDL_SetRenderDrawColor(rend, 255, 0, 0, 255); // red

    SDL_RenderDrawLine(rend, i, 99, i, vec[i]);
    SDL_RenderDrawLine(rend, j, 99, j, vec[j]);

    SDL_RenderPresent(rend);
    SDL_Delay(200);
}