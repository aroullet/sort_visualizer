#include <functional>
#include <iostream>
#include "gui.hpp"
#include "sorting.hpp"
#include "constants.hpp"

int main() {

   auto vec = generate_random_vector();

    SDL_Window* win = nullptr;
    SDL_Renderer* rend = nullptr;
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &rend);
    SDL_RenderSetScale(rend, WIDTH/VECTOR_SIZE, HEIGHT/UPPER_BOUND);

   typedef std::function<void(std::vector<unsigned>, SDL_Renderer*, unsigned, unsigned)> sort_func_t;
    sort_func_t fn;

    char ans;
    std::cout << "Which sorting algorithm?\nOptions: Bubble Sort ('b'), Merge Sort (m), Quick Sort ('q'), Selection Sort('s')\n";
    std::cin >> ans;

    using std::placeholders::_1, std::placeholders::_2;

    if (tolower(ans) == 's')
        fn = std::bind(&selection_sort, vec, rend, 7);
    else if (tolower(ans) == 'b')
        fn = std::bind(&bubble_sort, vec, rend, 10);
    else if (tolower(ans) == 'm')
        fn = std::bind(&merge_sort, vec, rend, 0, VECTOR_SIZE-1, 100);
    else if (tolower(ans) == 'q')
        fn = std::bind(&quick_sort, vec, rend, 0, VECTOR_SIZE-1, 100);

    fn(vec, rend, 0, VECTOR_SIZE-1);

    SDL_DestroyRenderer(rend);
    SDL_Quit();

    return 0;
}
