#pragma once

#include <vector>
#include <random>
#include "gui.hpp"
#include "constants.hpp"


std::vector<unsigned> generate_random_vector();
void bubble_sort(std::vector<unsigned>& v, SDL_Renderer* rend, int delay);
void merge_sort(std::vector<unsigned>& v, SDL_Renderer* rend, unsigned start, unsigned end, int delay);
void quick_sort(std::vector<unsigned>& v, SDL_Renderer* rend, unsigned left, unsigned right, int delay);
void selection_sort(std::vector<unsigned>& vec, SDL_Renderer* rend, int delay);

unsigned partition(std::vector<unsigned>& v, unsigned left, unsigned right);
void merge_intervals(std::vector<unsigned>& v, unsigned start, unsigned mid, unsigned end);