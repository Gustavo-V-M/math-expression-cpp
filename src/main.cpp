#include "../include/CheckOrder.hpp"
#include "../include/Variable.hpp"
#include "../include/toPrefix.hpp"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  string expression = "12+13";
  if (!isCorrectOrder(expression)) {
    cout << "Invalid Expression (Order of terms is incorrect)" << endl;
  }

  else {
    stack<string> final_expression;
    toPrefix(expression, &final_expression);
    int final_expression_size = final_expression.size();

    while (!final_expression.empty()) {
      string top = final_expression.top();
      final_expression.pop();
      cout << top << endl;
    }
  }

  return 0;
}
