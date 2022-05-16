#include "sorting.hpp"
#include <algorithm>

constexpr unsigned LOWER_BOUND = 0;
constexpr unsigned UPPER_BOUND = 100;
constexpr unsigned VECTOR_SIZE = 10;

std::vector<unsigned> generate_random_vector() {

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(LOWER_BOUND, UPPER_BOUND);

    auto gen = [&distr, &generator](){ return distr(generator); };

    std::vector<unsigned> vec(VECTOR_SIZE);
    std::generate(vec.begin(), vec.end(), gen);

    return vec;
}

void bubble_sort(std::vector<unsigned> &vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec.at(j) > vec.at(j + 1))
                std::swap(vec.at(j), vec.at(j + 1));
        }
    }
}

unsigned partition(std::vector<unsigned>& values, unsigned left, unsigned right) {
    int pivot_index = left + (right - left) / 2;
    int pivot_value = values[pivot_index];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(values[i] < pivot_value) {
            i++;
        }
        while(values[j] > pivot_value) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quick_sort(std::vector<unsigned>& values, unsigned left, unsigned right) {
    if(left < right) {
        unsigned pivot_index = partition(values, left, right);
        quick_sort(values, left, pivot_index - 1);
        quick_sort(values, pivot_index, right);
    }
}
