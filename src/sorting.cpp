#include <algorithm>
#include "sorting.hpp"

std::vector<unsigned> generate_random_vector() {

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(LOWER_BOUND, UPPER_BOUND);

    auto gen = [&distr, &generator](){ return distr(generator); };

    std::vector<unsigned> vec(VECTOR_SIZE);
    std::generate(vec.begin(), vec.end(), gen);

    return vec;
}

void bubble_sort(std::vector<unsigned> &vec, SDL_Renderer* rend, int delay) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1])
                std::swap(vec[j], vec[j + 1]);
            update_gui(vec, rend, j, j+1, delay);
        }
    }
}

unsigned partition(std::vector<unsigned>& vec, unsigned left, unsigned right) {
    int pivot_index = left + (right - left) / 2;
    int pivot_value = vec[pivot_index];
    int i = left, j = right;
    while(i <= j) {
        while(vec[i] < pivot_value) {
            i++;
        }
        while(vec[j] > pivot_value) {
            j--;
        }
        if(i <= j) {
            std::swap(vec[i], vec[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quick_sort(std::vector<unsigned>& vec, SDL_Renderer* rend, unsigned left, unsigned right, int delay) {
    if(left < right) {
        unsigned pivot_index = partition(vec, left, right);
        update_gui(vec, rend, left, pivot_index-1, delay);
        quick_sort(vec, rend, left, pivot_index - 1, delay);
        quick_sort(vec, rend, pivot_index, right, delay);
    }
}

void selection_sort(std::vector<unsigned>& vec, SDL_Renderer* rend, int delay) {
    for (size_t i = 0; i < vec.size(); ++i) {
        size_t min = i;

        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[min]) min = j;
            update_gui(vec, rend, i, j, delay);
        }

        if (min != i) {
            std::swap(vec[min], vec[i]);
        }
    }
}

void merge_intervals(std::vector<unsigned>& v, unsigned start, unsigned mid, unsigned end) {

    std::vector<unsigned> temp;

    unsigned i, j;
    i = start;
    j = mid + 1;

    while (i <= mid && j <= end) {
        if (v[i] <= v[j]) {
            temp.push_back(v[i]);
            ++i;
        }
        else {
            temp.push_back(v[j]);
            ++j;
        }
    }
    while (i <= mid) {
        temp.push_back(v[i]);
        ++i;
    }
    while (j <= end) {
        temp.push_back(v[j]);
        ++j;
    }
    for (int i = start; i <= end; ++i)
        v[i] = temp[i - start];
}

void merge_sort(std::vector<unsigned>& v, SDL_Renderer* rend, unsigned start, unsigned end, int delay) {
    if (start < end) {
        unsigned mid = (start + end) / 2;
        update_gui(v, rend, start, end, delay);
        merge_sort(v, rend, start, mid, delay);
        merge_sort(v, rend, mid + 1, end, delay);
        merge_intervals(v, start, mid, end);
    }
}