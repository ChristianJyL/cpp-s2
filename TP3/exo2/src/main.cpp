#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include "utils.hpp"

std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

int main()
{

    //NPI test avec structure et enum
    
    std::vector<std::string> words{split_string("3 4 +")}; //7
    // std::vector<std::string> words{split_string("2 12 + 5 +")};
    // std::vector<std::string> words{split_string("3 4 11 5 + / +")};
    // std::vector<std::string> words{split_string("4 5 2 * +")};
    std::vector<Token> tokens = tokenize(words);
    std::cout << npi_evaluate(tokens) << std::endl;

    return 0;
}