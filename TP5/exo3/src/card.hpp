#pragma once
#include <vector>
#include <string>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    int hash() const&{                                                 //coeur = 0 donc 1 de coeur = 0*13+0 = 0 et 2 de coeur = 0*13+1 = 1 et 3 de coeur = 0*13+2 = 2 ...
        return static_cast<int>(kind) * 13 + static_cast<int>(value);  //diamant = 1 donc 1 de diamant = 1*13+0 = 13 et 2 de diamant = 1*13+1 = 14 et 3 de diamant = 1*13+2 = 15 ...    
    }                                                                  //chacune des 52 cartes a un hash unique
};

bool operator==(Card const& a, Card const& b);
std::vector<Card> get_cards(size_t const size);
std::string card_name(Card const& card) ;

