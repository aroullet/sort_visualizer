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
            if (vec[j] > vec[j + 1])
                std::swap(vec[j], vec[j+1]);
        }
    }
}

unsigned partition(std::vector<unsigned>& vec, unsigned left, unsigned right) {
    int pivot_index = left + (right - left) / 2;
    int pivot_value = vec[pivot_index];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(vec[i] < pivot_value) {
            i++;
        }
        while(vec[j] > pivot_value) {
            j--;
        }
        if(i <= j) {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quick_sort(std::vector<unsigned>& vec, unsigned left, unsigned right) {
    if(left < right) {
        unsigned pivot_index = partition(vec, left, right);
        quick_sort(vec, left, pivot_index - 1);
        quick_sort(vec, pivot_index, right);
    }
}

void selection_sort( std::vector<unsigned>& vec) {
    for (size_t pos = 0; pos < vec.size(); ++pos) {
        size_t min = pos;

        for (size_t i = pos + 1; i < vec.size(); ++i) {
            if (vec[i] < vec[min]) min = i;
        }

        if (min != pos) {
            std::swap(vec[min], vec[pos]);
        }
    }
}