#include "../include/CheckOrder.hpp"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOpeningSymbol(char current) {
  switch (current) {
  default:
    return false;
  case '(':
  case '[':
  case '{':
  case '<':
    return true;
  }
}

char openingSymbolFrom(char current) {
  switch (current) {
  default:
    return '\0';
  case ')':
    return '(';
  case ']':
    return '[';
  case '}':
    return '{';
  case '>':
    return '<';
  }
}

bool isCorrectOrder(string expression) {
  const char *expression_arr = expression.c_str();
  const int expression_length = expression.size();
  stack<char> variables_stack;

  for (int i; i < expression_length; ++i) {
    if (isOpeningSymbol(expression_arr[i])) {
      variables_stack.push(expression_arr[i]);
    } else if (openingSymbolFrom(expression_arr[i]) != '\0') {
      if (variables_stack.empty() ||
          variables_stack.top() != openingSymbolFrom(expression_arr[i])) {
        return false;

      } else if (!variables_stack.empty()) {
        variables_stack.pop();
      }
    }
  }

  return true;
}
