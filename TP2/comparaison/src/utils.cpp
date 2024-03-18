#include "utils.hpp"
#include <vector>
#include <iostream>

void displayVector(std::vector<int> v){
    for (int const& elem : v){
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void displayVector(std::vector<float> v){
    for (float const& elem : v){
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}