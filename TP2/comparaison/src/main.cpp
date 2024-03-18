#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"
#include "utils.hpp"
#include "trie.hpp"
#include <iostream>


std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

std::vector<float> generate_random_vector_float(size_t const size, int const max = 100) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


int main()
{
    
    {
        std::vector<int> vec = generate_random_vector(10000);
        ScopedTimer timer("selection_sort");
        selection_sort(vec);
    }

    {
        std::vector<int> vec = generate_random_vector(10000);
        ScopedTimer timer("bubble_sort");
        bubble_sort(vec);
    }

    {
        std::vector<float> vec2 = generate_random_vector_float(10000);
        ScopedTimer timer("merge_sort");
        merge_sort(vec2);
    }

    {
        std::vector<int> vec = generate_random_vector(10000);
        ScopedTimer timer("std::sort");
        std::sort(vec.begin(), vec.end());
    }

    //On constate que le tri par fusion et le std::sort sont plus rapide que le tri par sélection et le tri à bulle

    return 0;
}