#include "../include/CheckOrder.hpp"
#include "../include/evaluate.hpp"
#include "../include/toPostfix.hpp"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  // argv[1] is the expression passed to the command line
  string expression = argv[1];
  if (!isCorrectOrder(expression)) {
    cout << "Invalid Expression (Order of terms is incorrect)" << endl;
  }

  else {
    stack<string> final_expression;
    toPostfix(expression, &final_expression);
    int result = evaluate(final_expression);

    cout << result << endl;
  }

  return 0;
}
