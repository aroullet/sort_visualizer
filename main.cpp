#include <tuple>
#include "gui.hpp"
#include "sorting.hpp"

constexpr std::tuple<int, int> ASPECT_RATIO(16, 9);

constexpr int WIDTH = VECTOR_SIZE * std::get<0>(ASPECT_RATIO);
constexpr int HEIGHT = UPPER_BOUND * std::get<1>(ASPECT_RATIO);

int main() {

    SDL_Window* win = nullptr;
    SDL_Renderer* rend = nullptr;
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &rend);
    SDL_RenderSetScale(rend, std::get<0>(ASPECT_RATIO), std::get<1>(ASPECT_RATIO));

    auto vec = generate_random_vector();
    selection_sort(vec, rend);

    SDL_DestroyRenderer(rend);
    SDL_Quit();

    return 0;
}
