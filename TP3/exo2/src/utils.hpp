#pragma once
#include <string>
#include <vector>

enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

bool is_floating(std::string const& s);
float npi_evaluate(std::vector<std::string> const& tokens);



