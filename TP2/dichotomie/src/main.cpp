#include <vector>
#include <algorithm>
#include <iostream>

int search(std::vector<int> vec, int value)
{
    size_t left{0};
    size_t right{vec.size() - 1};
    size_t middle{(left + right) / 2};

    while (left <= right)  
    {
        if (vec[middle] == value)
        {
            return middle;
        }
        else
        {
            if (vec[middle] < value)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        middle = (left + right) / 2; //On recalcule le milieu
    }
    return -1; //On trouve rien
}

int main()
{

    std::vector<int> vec{1, 2, 2, 3, 4, 8, 12};
    std::cout << search(vec, 8) << std::endl;

    vec = {1, 2, 3, 3, 6, 14, 12, 15};
    std::cout << search(vec, 15) << std::endl;

    vec = {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::cout << search(vec, 16) << std::endl;

    vec = {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::cout << search(vec, 6) << std::endl;

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << search(vec, 10) << std::endl;

    return 0;
}