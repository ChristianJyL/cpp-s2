#include "node.hpp"
#include <iostream>

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

Node* create_node(int value){
    Node* node = new Node();
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool Node::is_leaf() const{
    if (left == nullptr && right == nullptr) {
        return true;
    }
    return false;
}

void Node::insert(int value){
    if (value < this->value){
        if (left == nullptr) {
            left = create_node(value);
        } else {
            left->insert(value);
        }
    } else {
        if (right == nullptr) {
            right = create_node(value);
        } else {
            right->insert(value);
        }
    }
}

int Node::height() const{
    if (is_leaf()) {
        return 1;
    }
    int left_height = 0;
    int right_height = 0;
    if (left != nullptr) {
        left_height = left->height();
    }
    if (right != nullptr) {
        right_height = right->height();
    }
    return 1 + std::max(left_height, right_height);
}



void Node::delete_childs(){
    if (left != nullptr) {
        left->delete_childs();
        delete left;
        left = nullptr; 
    }
    if (right != nullptr) {
        right->delete_childs();
        delete right;
        right = nullptr; 
    }
}

void Node::display_infixe() const{
    if (left != nullptr) {
        left->display_infixe();
    }
    std::cout <<" - "<< value ;
    if (right != nullptr) {
        right->display_infixe();
    }
}

std::vector<Node const*> Node::prefixe() const{
    std::vector<Node const*> result;
    result.push_back(this);
    if (left != nullptr) {
        auto left_prefixe = left->prefixe();
        result.insert(result.end(), left_prefixe.begin(), left_prefixe.end());
    }
    if (right != nullptr) {
        auto right_prefixe = right->prefixe();
        result.insert(result.end(), right_prefixe.begin(), right_prefixe.end());
    }
    return result;
}

std::vector<Node const*> Node::postfixe() const{
    std::vector<Node const*> result;
    if (left != nullptr) {
        auto left_postfixe = left->postfixe();
        result.insert(result.end(), left_postfixe.begin(), left_postfixe.end());
    }
    if (right != nullptr) {
        auto right_postfixe = right->postfixe();
        result.insert(result.end(), right_postfixe.begin(), right_postfixe.end());
    }
    result.push_back(this);
    return result;
}

Node*& most_left(Node*& node){
    if (node->left == nullptr) {
        return node;
    }
    return most_left(node->left);
}

bool remove(Node*& node, int value){
    if (node == nullptr) { //si l'arbre est vide
        return false;
    }
    if (value < node->value) { //si la valeur est plus petite que la valeur du noeud actuel
        return remove(node->left, value);
    }
    if (value > node->value) { //si la valeur est plus grande que la valeur du noeud actuel
        return remove(node->right, value);
    }

    if (node->value == value) { //si on est au bon endroit
        if (node->is_leaf()) { //Le nœud n'a pas de fils
            delete node;
            node = nullptr;
            return true;
        }
        if (node->left == nullptr) { //Le nœud a un seul fils à droite
            Node* right = node->right;
            delete node;
            node = right;
            return true;
        }
        if (node->right == nullptr) { //Le nœud a un seul fils à gauche
            Node* left = node->left;
            delete node;
            node = left;
            return true;
        }
        Node*& rightN_most_left = most_left(node->right); //On prend le noeud le plus a gauche du fils droit (le plus petit des plus grands)
        node->value = rightN_most_left->value; //On remplace la valeur du noeud à supprimer par la valeur du noeud trouvé
        return remove(rightN_most_left, rightN_most_left->value); //On supprime le noeud qu'on a trouvé (on rappelle la fonction remove pour traiter tous les cas de suppression)
    }
    return false;
}

void delete_tree(Node* node){
    if (node == nullptr) {
        return;
    }
    node->delete_childs();
    delete node;
    node = nullptr;
}

int min(Node const& node){ //sensiblement la même fonction que most_left mais avec un return de int et non de Node*
    if (node.left == nullptr) {
        return node.value;
    }
    return min(*node.left);
}

int max(Node const& node){
    if (node.right == nullptr) {
        return node.value;
    }
    return max(*node.right);
}




