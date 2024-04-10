#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include "card.hpp"

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

int main() {
    
    std::vector<Card> cards = get_cards(100);
    std::unordered_map<Card, int> number_card {};

    for (Card const& card : cards ){
        number_card[card] += 1;
    }

    for (std::pair<Card, int> const& card : number_card) {
        std::cout << card_name(card.first) << " : " << card.second << std::endl;
    }

    std::cout << "Number of different cards : " << number_card.size() << std::endl;

    return 0;
}