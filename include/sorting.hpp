#pragma once

#include <vector>
#include <random>

std::vector<unsigned> generate_random_vector();
void bubble_sort(std::vector<unsigned>& v);
void merge_sort(std::vector<unsigned>& v);
void quick_sort(std::vector<unsigned>& v, unsigned left, unsigned right);
void selection_sort( std::vector<unsigned>& vec);
unsigned partition(std::vector<unsigned>& v, unsigned left, unsigned right);