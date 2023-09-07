#ifndef TOPREFIX_H
#define TOPREFIX_H

#include <stack>
#include <string>

using namespace std;

int priorityFromOperator(char oper);
bool isOperator(char current);
void toPostfix(string expression, stack<string> *final_expression);

#endif // TOPREFIX_H
#define TOPREFIX_H
