#include "../include/evaluate.hpp"
#include "../include/toPostfix.hpp"
#include <cctype>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

int operation(char oper, int a, int b) {
  switch (oper) {
  default:
    return -1;
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  case '^':
    return a ^ b;
  }
}

int evaluate(stack<string> expression) {
  stack<string> final_expression;

  while (!expression.empty()) {
    if (expression.top() != "") {
      final_expression.push(expression.top());
    }
    expression.pop();
  }

  stack<int> numbers_stack;
  stack<char> operators;

  while (!final_expression.empty()) {

    string current = final_expression.top();
    char current_char = current.at(0);

    if (isdigit(current_char)) {
      numbers_stack.push(stoi(current));
    }

    else {
      operators.push(current_char);
      if (numbers_stack.size() >= 2) {
        int b = numbers_stack.top();
        numbers_stack.pop();
        int a = numbers_stack.top();
        numbers_stack.pop();

        char oper = operators.top();
        operators.pop();

        int result = operation(oper, a, b);
        numbers_stack.push(result);
      }
    }

    final_expression.pop();
  }

  return numbers_stack.top();
}
