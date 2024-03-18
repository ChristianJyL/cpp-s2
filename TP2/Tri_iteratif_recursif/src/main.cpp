#include <vector>
#include <algorithm>
#include "trie.hpp"
#include "utils.hpp"
#include <iostream>



int main()
{

    //SELECTION SORT----------------------------------------------------------
    std::vector<int> list = {12, 8, 23, 10, 15};

    selection_sort(list);
    displayVector(list);

    if (is_sorted(list))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    //BUBLE SORT----------------------------------------------------------
    list = {12, 8, 23, 10, 15};
    bubble_sort(list);
    displayVector(list);

    if (is_sorted(list))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    //MERGE SORT----------------------------------------------------------
    std::vector<float> list2 = {12, 8, 23, 10, 15};
    merge_sort(list2);
    displayVector(list2);


    return 0;
}