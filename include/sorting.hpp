#pragma once

#include <vector>
#include <random>
#include "gui.hpp"

constexpr unsigned LOWER_BOUND = 0;
constexpr unsigned UPPER_BOUND = 100;
constexpr unsigned VECTOR_SIZE = 100;

std::vector<unsigned> generate_random_vector();
void bubble_sort(std::vector<unsigned>& v, SDL_Renderer* rend);
void merge_sort(std::vector<unsigned>& v);
void quick_sort(std::vector<unsigned>& v, unsigned left, unsigned right);
void selection_sort(std::vector<unsigned>& vec, SDL_Renderer* rend);
unsigned partition(std::vector<unsigned>& v, unsigned left, unsigned right);