#include <vector>
#include <cstdlib>
#include <algorithm>
#include "utils.hpp"
#include <iostream>

void counting_sort(std::vector<unsigned int> & vec){
    unsigned int max {max_vec(vec)};
    std::vector<unsigned int> occurences {};
    std::vector<unsigned int> result {};
    for (unsigned int i = 0; i < max+1; i++){ //On initialise le vecteur d'occurences à 0
        occurences.push_back(0);
    }
    for (unsigned int const& elem : vec){ //On compte le nombre d'occurences de chaque élément
        occurences[elem]++;
    }
    
    for (unsigned int i {0}; i < occurences.size(); i++){
        for (unsigned int j {0} ; j <occurences[i] ; j++){
            result.push_back(i);
        }
    }
    vec = result;
}

std::vector<unsigned int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<unsigned int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}
bool is_sorted(std::vector<unsigned int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }


int main()
{
    std::vector<unsigned int> list = generate_random_vector(50);

    counting_sort(list);

    if (is_sorted(list))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    return 0;
}