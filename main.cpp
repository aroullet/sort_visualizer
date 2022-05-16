#include <iostream>
#include "gui.hpp"
#include "sorting.hpp"

constexpr int WIDTH = 900;
constexpr int HEIGHT = 1200;

int main() {
    std::cout << "Hello, World!" << std::endl;

    //SDL_Window* win = initialize_window(WIDTH, HEIGHT);
    //SDL_Renderer* rend = get_renderer(win);

    auto vec = generate_random_vector();

    for (auto& ele: vec)
        std::cout << ele << " ";

    quick_sort(vec, 0, vec.size()-1);
    std::cout << '\n';

    for (auto& ele: vec)
        std::cout << ele << " ";


    return 0;
}
