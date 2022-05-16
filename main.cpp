#include "gui.hpp"
#include "sorting.hpp"

constexpr int WIDTH = 1200;
constexpr int HEIGHT = 900;

int main() {

    SDL_Window* win = nullptr;
    SDL_Renderer* rend = nullptr;
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &rend);
    SDL_RenderSetScale(rend, 10, 10);

    auto vec = generate_random_vector();
    selection_sort(vec, rend);

    SDL_DestroyRenderer(rend);
    SDL_Quit();

    return 0;
}
