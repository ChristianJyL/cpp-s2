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
        
}



int main() {
    std::string phrase = "   Salut c'est moi Tchoupi";
    std::cout << "Nombre de lettres dans le premier mot : " << nbLetterFirstWord(phrase) << std::endl;
    return 0;
}