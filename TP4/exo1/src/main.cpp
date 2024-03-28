#include <vector>
#include <algorithm>
#include<cstdlib>
#include <iostream>

int main()
{
    std::vector<int> vec{};
    for (int i{0}; i < 100; i++)
    {
        int nbRand = rand() % 100;
        vec.push_back(nbRand);
    }

    // Déclaration d'un itérateur permettant d'indiquer la fin du vecteur v
    std::vector<int>::iterator end_iterator{vec.end()};

    // Parcours du vecteur avec l'itérateur
    for (std::vector<int>::iterator it{vec.begin()}; it != end_iterator; ++it)
    {
        std::cout << *it << std::endl;
    }

    int inputValue {};
    std::cin >> inputValue; 
    while (std::cin.fail() ){
        std::cout << "Erreur d'entrée..." << std::endl;
        std::cin.clear(); // On remet std::cin dans un état fonctionnel.
        std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
        std::cin >> inputValue;
    }

    



    return 0;
}