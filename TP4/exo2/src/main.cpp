#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

auto const is_space = [](char letter){ return letter == ' '; };

int nbLetterFirstWord(const std::string& phrase) {
    auto beginIt =std::find_if_not(phrase.begin(), phrase.end(), is_space); //On récupère le début du premier mot (cas où la phrase possède des espaces au début)
    auto endIt = std::find(beginIt, phrase.end(), ' '); //on pourrait aussi utiliser le find if
    return std::distance(beginIt, endIt);
}

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> result;
    auto beginIt = str.begin();
    while(beginIt != str.end()){
        beginIt = std::find_if_not(beginIt, str.end(), is_space); //On récupère le début du premier mot (cas où la phrase possède des espaces au début)
        auto endWordIt = std::find_if(beginIt, str.end(), is_space); //je l'ai fait avec le find_if cette fois ci
        result.push_back(std::string(beginIt, endWordIt)); //On ajoute le mot à notre vecteur
        beginIt = endWordIt; //On passe au mot suivant
    }
    return result;
}



int main() {
    std::string phrase = "   Salut c'est moi Tchoupi";
    std::cout << "Nombre de lettres dans le premier mot : " << nbLetterFirstWord(phrase) << std::endl;

    std::vector<std::string> words = split_string(phrase);
    for(std::string const& word : words){
        std::cout << word << std::endl;
    }

    return 0;
}