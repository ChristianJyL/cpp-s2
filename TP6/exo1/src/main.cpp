#include <iostream>
#include "node.hpp"




int main()
{
    Node* arbre = create_node(10);
    arbre->insert(7);
    arbre->insert(12);


    pretty_print_left_right(*arbre);

    std::cout << arbre->height() << std::endl; 

    arbre->delete_childs();
    pretty_print_left_right(*arbre);

    return 0;
}