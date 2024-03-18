#include "utils.hpp"
#include <vector>
#include <iostream>


void displayVector(std::vector<unsigned int> const& v)
{
    for (unsigned int const &elem : v)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

unsigned int max_vec(std::vector<unsigned int> const& vec)
{
    unsigned int max = 0;
    for (unsigned int const &elem : vec)
    {
        if (elem > max)
        {
            max = elem;
        }
    }
    return max;
}

