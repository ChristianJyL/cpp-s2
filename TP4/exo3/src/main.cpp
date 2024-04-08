#include <iostream>
#include <string>
#include <vector>

bool is_palindrome(std::string const& word){
    return std::equal(word.begin(), word.end(), word.rbegin());
}

int main() {
    std::vector<std::string> words = {"radar", "Squeezie", "tot", "non", "oui"};
    for (auto const& word : words) {
        if ( is_palindrome(word) ) {
            std::cout << word << " : Hehehe c'est un pal indrome ! (ref à palword lol mdr)" << std::endl;
        } else {
            std::cout << word << " : ah bah nan, choqué déçu, c'est pas un palindrome" << std::endl;
        }
    }
    return 0;
}