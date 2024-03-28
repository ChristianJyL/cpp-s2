#include "utils.hpp"
#include <cctype>
#include <iostream>
#include <stack>
#include <string>

bool is_floating(std::string const &s)
{
    for (char const &character : s)
    {
        std::cout << "Character :" << character << std::endl;
        if (!std::isdigit(character) && character != '.')
        {
            return false;
        }
    }
    return true;
}

float npi_evaluate(std::vector<std::string> const &tokens)
{
    std::stack<float> pile{};
    for (std::string token : tokens)
    {
        if (is_floating(token))
        {
            pile.push(std::stof(token));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            // Je récupère l'élément en haut de la pile
            float rightOperand{pile.top()};
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            pile.pop();
            float leftOperand{pile.top()};
            pile.pop();

            float result{};
            if (token == "+")
            {
                result = leftOperand + rightOperand;
            }
            else if (token == "-")
            {
                result = leftOperand - rightOperand;
            }
            else if (token == "*")
            {
                result = leftOperand * rightOperand;
            }
            else if (token == "/")
            {
                result = leftOperand / rightOperand;
            }
            pile.push(result);
        }
        else
        {
            std::cout << "Je crois que cest pas normal mon reuf" << std::endl;
        }
    }
    if (pile.size() != 1)
    {
        std::cout << "Error: mets une expression valide mon reuf" << std::endl;
    }

    float result = pile.top();
    pile.pop();
    return result;
}

Token make_token(float value){
    return Token{TokenType::OPERAND, value, Operator::ADD};
}

Token make_token(Operator op){
    return Token{TokenType::OPERATOR, 0.0f, op};
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> tokens{};
    for(std::string word : words){
        if(is_floating(word)){
            tokens.push_back(make_token(std::stof(word)));
        }else if(word == "+"){
            tokens.push_back(make_token(Operator::ADD));
        }else if(word == "-"){
            tokens.push_back(make_token(Operator::SUB));
        }else if(word == "*"){
            tokens.push_back(make_token(Operator::MUL));
        }else if(word == "/"){
            tokens.push_back(make_token(Operator::DIV));
        }else{
            std::cout << "Error: mets une expression valide mon reuf" << std::endl;
        }
    }
    return tokens;
}

float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> pile{};
    for(Token token : tokens){
        if(token.type == TokenType::OPERAND){
            pile.push(token.value);
        }else if(token.op == Operator::ADD || token.op == Operator::SUB || token.op == Operator::MUL || token.op == Operator::DIV){
            float rightOperand{pile.top()};
            pile.pop();
            float leftOperand{pile.top()};
            pile.pop();

            float result{};
            if(token.op == Operator::ADD){
                result = leftOperand + rightOperand;
            }else if(token.op == Operator::SUB){
                result = leftOperand - rightOperand;
            }else if(token.op == Operator::MUL){
                result = leftOperand * rightOperand;
            }else if(token.op == Operator::DIV){
                result = leftOperand / rightOperand;
            }
            pile.push(result);
        }else{
            std::cout << "Error: mets une expression valide mon reuf" << std::endl;
        }
    }
    if(pile.size() != 1){
        std::cout << "Error: mets une expression valide mon reuf" << std::endl;
    }

    float result = pile.top();
    pile.pop();
    return result;
}