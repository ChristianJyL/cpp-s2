#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>


int main()
{
    //Question 1
    std::vector<int> vec{};
    for (int i{0}; i < 100; i++)
    {
        int nbRand = rand() % 100;
        vec.push_back(nbRand);
    }
    //Question 2
    // Déclaration d'un itérateur permettant d'indiquer la fin du vecteur v
    std::vector<int>::iterator end_iterator{vec.end()};

    // Parcours du vecteur avec l'itérateur
    for (std::vector<int>::iterator it{vec.begin()}; it != end_iterator; ++it)
    {
        std::cout << *it << std::endl;
    }

    //Question 3
    int inputValue{};
    std::cout << "Entrez une valeur :";
    std::cin >> inputValue;
    while (std::cin.fail())
    {
        std::cout << "Erreur d'entrée..." << std::endl;
        std::cin.clear();           // On remet std::cin dans un état fonctionnel.
        std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
        std::cin >> inputValue;
    }

    // Recherche de l'élément 3 dans le vecteur v
    auto it{std::find(vec.begin(), vec.end(), inputValue)};

    // On compare l'itérateur avec l'itérateur sur le dernier élément du vecteur
    if (it != vec.end())
    {
        std::cout << "L'élément est bien présent : " << *it << std::endl;
    }
    else
    {
        std::cout << "L'élément n'a pas été trouvé" << std::endl;
    }

    //Question 4
    std::cout << "Entrez la valeur du nombre dont vous voulez connaitre l'occurence : ";
    std::cin >> inputValue;
    while (std::cin.fail())
    {
        std::cout << "Erreur d'entrée..." << std::endl;
        std::cin.clear();           // On remet std::cin dans un état fonctionnel.
        std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
        std::cin >> inputValue;
    }
    const int occ = std::count(vec.begin(),vec.end(), inputValue);
    std::cout << "Il y a " << occ << " occurences de la valeur " << inputValue << std::endl;

    //Question 5
    std::sort(vec.begin(), vec.end());
    for (int element : vec){ //parcours sans itérateur 
        std::cout << element << std::endl;
    }
    //Question 6
    // Somme des éléments du vecteur v
    int sum { std::accumulate(vec.begin(), vec.end(), 0, [](int acc, int current_element) { return acc + current_element; }) };
    std::cout << "La somme est : "<<  sum << std::endl;

    return 0;
}