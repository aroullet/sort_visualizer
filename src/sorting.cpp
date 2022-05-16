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
