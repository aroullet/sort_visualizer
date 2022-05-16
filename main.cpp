#include <tuple>
#include <functional>
#include <iostream>
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

    std::function<void(std::vector<unsigned>&, SDL_Renderer*)> sort_function;

    char ans;
    std::cout << "Which sorting algorithm?\n";
    std::cin >> ans;

    if (tolower(ans) == 's')
        sort_function = selection_sort;
    else if (tolower(ans) == 'b')
        sort_function = bubble_sort;

    sort_function(vec, rend);

    SDL_DestroyRenderer(rend);
    SDL_Quit();

    return 0;
}
