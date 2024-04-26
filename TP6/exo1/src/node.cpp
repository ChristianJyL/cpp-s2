#include "node.hpp"

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
    if (value < Node::value ){
        left = create_node(value);
    }else {
        right = create_node(value);
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

}


