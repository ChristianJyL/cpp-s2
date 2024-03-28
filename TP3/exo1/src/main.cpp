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

    // NPI notation
    std::string input{};
    std::cout << "Enter your operation: ";
    std::getline(std::cin, input);
    std::vector<std::string> tokens = split_string(input);
    std::cout << npi_evaluate(tokens) << std::endl;
  

    return 0;
}