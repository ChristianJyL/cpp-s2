#include <iostream>
#include <string>
#include <numeric>
#include <vector>

int somme_carre(std::vector<int> const& numbers){
    int sum { std::accumulate(numbers.begin(), numbers.end(), 0, [](int acc, int current_element) { return acc + current_element*current_element; }) };
    return sum;
}

int produit_pair(std::vector<int> const& numbers){
    int produit { std::accumulate(numbers.begin(), numbers.end(), 1, [](int acc, int current_element) { if (current_element%2==0) return acc * current_element; else return acc; }) };
    return produit;
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::cout << somme_carre(vec) << std::endl;

    std::vector<int> vec2{1, 2, 3, 4, 5};
    std::cout << produit_pair(vec2) << std::endl;

    return 0;
}