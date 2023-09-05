#include "../include/CheckOrder.hpp"
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

int priorityFromOperator(char oper) {
  switch (oper) {
  default:
    return -1;
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  }
}

bool isOperator(char current) {
  switch (current) {
  default:
    return false;
  case '+':
  case '*':
  case '/':
  case '^':
  case '-':
    return true;
  }
}

void toPrefix(string expression, stack<string> *final_expression) {
  int expression_length = expression.size();
  stack<char> operators;

  string current_number = "";

  for (int i = 0; i < expression_length; ++i) {

    char current_char = expression.at(i);

    if (isdigit(current_char)) {
      current_number += current_char;
    }

    else {
      final_expression->push(current_number);
      current_number = "";

      if (isOperator(current_char)) {

        while (!operators.empty() &&
               priorityFromOperator(current_char) <=
                   priorityFromOperator(operators.top())) {
          string aux;
          aux = operators.top();
          operators.pop();
          final_expression->push(aux);
        }

        if (!operators.empty() && priorityFromOperator(current_char) >
                                      priorityFromOperator(operators.top())) {
          string aux;
          aux = current_char;
          final_expression->push(aux);
        }

        else {
          operators.push(current_char);
        }
      }
    }
  }
  if (current_number != "") {
    final_expression->push(current_number);
  }
  while (!operators.empty()) {
    string aux;
    aux = operators.top();
    operators.pop();
    final_expression->push(aux);
  }
}
