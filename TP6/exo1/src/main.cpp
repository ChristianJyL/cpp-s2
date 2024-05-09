#include <iostream>
#include "node.hpp"




int main()
{
    Node* arbre = create_node(5);
    arbre->insert(3);
    arbre->insert(7);
    arbre->insert(2);
    arbre->insert(4);
    arbre->insert(6);
    arbre->insert(8);
    arbre->insert(1);
    arbre->insert(9);
    arbre->insert(0);

    std::cout <<"Affichage infixe :" << std::endl;
    arbre->display_infixe();
    std::cout << std::endl;

    std::cout << "Affichage postfixe :" << std::endl;
    std::vector<Node const*> post = arbre->postfixe();
    int sum {0};
    for (auto node : post) {
        std::cout << node->value << " ";
        sum += node->value;
    }
    std::cout << std::endl;

    std::cout << "Node le plus a gauche (le minimum) : " << min(*arbre) << std::endl;
    std::cout << "Node le plus a droite (le maximum) : " << max(*arbre) << std::endl;


    std::cout << "Somme des valeurs a partir du parcours postfixe: " << sum << std::endl;

    std::cout << "Affichage normal :" << std::endl;
    pretty_print_left_right(*arbre);

    std::cout << "Hauteur de l'arbre : ";
    std::cout << arbre->height() << std::endl; 

    return 0;
}