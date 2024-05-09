#include <iostream>
#include "node.hpp"




int main()
{
    Node* arbre = create_node(10);
    arbre->insert(7);
    arbre->insert(5);
    arbre->insert(8);
    arbre->insert(12);

    std::cout <<"Affichage infixe :" << std::endl;
    arbre->display_infixe();
    std::cout << std::endl;

    std::cout << "Affichage postfixe :" << std::endl;
    std::vector<Node const*> post = arbre->postfixe();
    for (auto node : post) {
        std::cout << node->value << " ";
    }
    std::cout << std::endl;


    std::cout << "Affichage normal :" << std::endl;
    pretty_print_left_right(*arbre);

    std::cout << "Hauteur de l'arbre : ";
    std::cout << arbre->height() << std::endl; 

    std::cout << "Node le plus à gauche :"<< most_left(arbre)->value << std::endl;
    
    arbre->delete_childs();

    std::cout << "Affichage normal après suppression:" << std::endl;
    pretty_print_left_right(*arbre);

    
    

  
    return 0;
}