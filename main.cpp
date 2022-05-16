#include <tuple>
#include <functional>
#include <iostream>
#include "gui.hpp"
#include "sorting.hpp"

constexpr std::tuple<int, int> ASPECT_RATIO(16, 9);
constexpr int WIDTH = VECTOR_SIZE * std::get<0>(ASPECT_RATIO);
constexpr int HEIGHT = UPPER_BOUND * std::get<1>(ASPECT_RATIO);

int main() {

   auto vec = generate_random_vector();

    SDL_Window* win = nullptr;
    SDL_Renderer* rend = nullptr;
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &rend);
    SDL_RenderSetScale(rend, std::get<0>(ASPECT_RATIO), std::get<1>(ASPECT_RATIO));

   typedef std::function<void(std::vector<unsigned>, SDL_Renderer*, unsigned, unsigned)> sort_func_t;
    sort_func_t fn;

    char ans;
    std::cout << "Which sorting algorithm?\nOptions: Bubble Sort ('b'), Quick Sort ('q'), Selection Sort('s')\n";
    std::cin >> ans;

    using std::placeholders::_1, std::placeholders::_2;

    if (tolower(ans) == 's')
        fn = std::bind(&selection_sort, vec, rend);
    else if (tolower(ans) == 'b')
        fn = std::bind(&bubble_sort, vec, rend);
    else if (tolower(ans) == 'q')
        fn = std::bind(&quick_sort, vec, rend, 0, VECTOR_SIZE-1);

    fn(vec, rend, 0, VECTOR_SIZE-1);

    SDL_DestroyRenderer(rend);
    SDL_Quit();

    return 0;
}
