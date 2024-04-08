#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>

size_t folding_string_hash(std::string const& s, size_t max){
    size_t hash {0};
    hash = std::accumulate(s.begin(), s.end(), 0, [](int acc, int current_element) { return acc + current_element; });
    hash = hash % max;
    return hash;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash {0};
    for (size_t i = 0; i < s.size(); i++){
        hash += s[i] * i;
    }
    hash = hash % max;
    return hash;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t hash {0};
    size_t power {1};
    for (size_t i = 0; i < s.size()-1; i++){
        hash += s[i] * power;
        power *= p;
    }
    hash = hash % m;
    return hash;

}


int main()
{
    /*Question 1*/
    std::string s = "BonneVacances";
    size_t max = 1024;
    std::cout << "Question 1 : " << folding_string_hash(s, max) << std::endl;

    /*Question 2 : Différence entre abc et cba*/
    std::string s1 = "abc";
    std::string s2 = "cba";
    std::cout << "Question 2 : " << folding_string_ordered_hash(s1, max) << " " << folding_string_ordered_hash(s2, max) << std::endl;

    /*Question 3 : polynomial rolling hash*/
    size_t p = 7;
    size_t m = 1024;
    std::cout << "Question 3 : " << polynomial_rolling_hash(s, p, m) << std::endl;

    return 0;
}